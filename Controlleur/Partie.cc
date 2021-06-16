#include "Partie.hh"

Partie::Partie(const std::vector<Joueur*> & v,int duree)
:tempRestant(duree) {
  for(const auto & p:v) {
    participants.push_back(p);
  }
}

Partie::~Partie() {
  while(participants.size() > 0) {
    delete participants.back();
    participants.pop_back();
  }
}

void Partie::nextFrame() {
  tempRestant--;
  for(auto participant:participants) {
    participant->request_deplacement();
  }
}
