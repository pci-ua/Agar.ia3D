#include "ia.hh"
#include <iostream>
extern Ia iatest[];

// déplacement de l'ia à la position i dans le tableau ia
void Ia::deplacement (int width,int height) {
     width /= 2;
     height /= 2;

     _cible = Vect2D({-width,width},{-height,height});
     float Magnitude = _cible.length();

     if( Magnitude != 0 ) {
          Vect2D v = Vect2D(_cible);
          v.setMagnitude(_vitesse);

          Vect2D p = _position + v;

          const Vect2D TopLeft (-width,-height);
          const Vect2D BotRight (width,height);

          if( TopLeft <= p && p <= BotRight) {
               _position.setX( p.getX() );
               _position.setZ( p.getZ() );
          }
     }
}
