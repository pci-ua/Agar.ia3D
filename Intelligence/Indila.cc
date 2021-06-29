#include "Indila.hh"

Indila::Indila()
     // Seul la couleur est nécessaire par défaut,
     // mais vous pouvez ajouter / modifier ce que vous voulez !
     :Joueur(Couleur(0,128,128)) {}

double Indila::deplacement(std::vector<InfoEntitee> joueurs,std::vector<InfoEntitee> nourritures) {
     // Ici l'idée est juste de faire tournée l'ia sur elle même
     // pour cela on donne juste un angle de direction qui s'incrémente
     i+=0.1;
     return i;
}
