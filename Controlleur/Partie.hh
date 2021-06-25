#include "../Modele/entitee/joueur.hh"
#include "../Modele/entitee/nourriture.hh"
#include <vector>
class Partie {
private:
  std::vector<Joueur*> participants;
  std::vector<Nourriture*> nourritures;
  unsigned int tempRestant; /*seconde*/
public:

  Partie(const std::vector<Joueur*> & v,unsigned int duree,int nmbFood);
  Partie(const Partie & p) = delete;
  ~Partie();

  Partie& operator=(const Partie & c) = delete;

  // Temporaire
  void renduTerminal();
  auto p_begin() { return participants.begin(); }
  auto p_end() { return participants.end(); }
  auto n_begin() { return nourritures.begin(); }
  auto n_end() { return nourritures.end(); }

  void nextFrame();
};
