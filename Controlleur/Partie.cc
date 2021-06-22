#include "Partie.hh"

Partie::Partie(const std::vector<Joueur*> & v,unsigned int duree,int nbFood)
:tempRestant(duree) {
  for(const auto & p:v) {
    participants.push_back(p);
  }
  for(int i=0 ; i<nbFood ; i++) {
    nourritures.push_back(new Nourriture);
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
    participant->request_deplacement();
  }

  // Collision
  for(auto participant:participants) {
    // Nourriture
    for(auto nourriture:nourritures) {
      if(participant->collision(nourriture)) {
        participant->manger(nourriture);
      }
    }
    // Joueurs
    for(auto adversaire:participants) {
      if(participant != adversaire) {
        if(participant->collision(adversaire)) {
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
