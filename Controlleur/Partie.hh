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

  void nextFrame();

  std::vector<InfoEntitee> playerNearFrom(Vect2D<double> pos,double size) const;
  std::vector<InfoEntitee> foodNearFrom(Vect2D<double> pos,double size) const;
};
