#include "Partie.hh"
#include "../Modele/generateur/g_couleur.hh"
#include "../constante.hh"
#include <math.h> // PI (M_PI), cos , sin
Partie::Partie(const std::vector<Joueur*> & v,unsigned int duree,int nbFood)
:tempRestant(duree) {
  for(const auto & p:v) {
    participants.push_back(p);
  }
  for(int i=0 ; i<nbFood ; i++) {
    nourritures.push_back(new Nourriture(CouleurRandom()));
  }
}

Partie::~Partie() {
  while(participants.size() > 0) {
    delete participants.back();
    participants.pop_back();
  }
  while(nourritures.size() > 0) {
    delete nourritures.back();
    nourritures.pop_back();
  }
}

void Partie::nextFrame() {
  // Délais
  if(tempRestant == 0) {
    throw "_";
  }
  tempRestant--;

  // Déplacement
  for(auto participant:participants) {
    participant->request_deplacement(*this);
  }

  // Collision
  for(auto participant:participants) {
    // Nourriture
    for(auto nourriture:nourritures) {
      if(participant->collision(*dynamic_cast<Boule*>(nourriture))) {
        participant->manger(nourriture);
      }
    }
    // Joueurs
    for(auto adversaire:participants) {
      if(participant != adversaire) {
        if(participant->collision(*dynamic_cast<Boule*>(adversaire))) {
          if(participant->getTaille() > adversaire->getTaille()) {
            participant->manger(adversaire);
          } else {
            adversaire->manger(participant);
          }
        }
      }
    }
  }
}

void Joueur::request_deplacement(const Partie & partie) {
   double angle = deplacement(
        partie.playerNearFrom(getPosition(),getTaille()*JOUEUR::ROV,this),
        partie.foodNearFrom(getPosition(),getTaille()*JOUEUR::ROV)
   );
   Vect2D<double> k(cos(angle),sin(angle));
   k.setMagnitude(vitesse);
   auto pos = getPosition() + k;

   const Vect2D<double> TopLeft(0,0);
   const Vect2D<double> BotRight(CARTE::LARGEUR,CARTE::LONGUEUR);

   if( TopLeft <= pos && pos <= BotRight) {
     getPosition() = pos;
   }
}

std::vector<InfoEntitee> Partie::playerNearFrom(Vect2D<double> pos,double distMax,Joueur* self) const {
     std::vector<InfoEntitee> result;
     for(auto participant:participants) {
          if( (self != participant) && ((participant->getPosition()-pos).getMagnitude() <= distMax )) {
               result.push_back({ participant->getPosition(), participant->getTaille() });
          }
     }
     return result;
}

std::vector<InfoEntitee> Partie::foodNearFrom(Vect2D<double> pos,double distMax) const {
     std::vector<InfoEntitee> result;
     for(auto nourriture:nourritures) {
          if( (nourriture->getPosition()-pos).getMagnitude() <= distMax ) {
               result.push_back({ nourriture->getPosition(), nourriture->getTaille() });
          }
     }
     return result;
}
