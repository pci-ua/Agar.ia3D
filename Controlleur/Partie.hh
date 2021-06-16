#include "../Modele/entitee/joueur.hh"
#include <vector>
class Partie {
private:
  std::vector<Joueur*> participants;
  int tempRestant; /*seconde*/
public:

  Partie(const std::vector<Joueur*> & v,int duree);
  Partie(const Partie & p) = delete;
  ~Partie();

  Partie& operator=(const Partie & c) = delete;

  // Temporaire
  void renduTerminal();

  void nextFrame();
};
