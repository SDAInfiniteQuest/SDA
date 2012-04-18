#ifndef __univers_h_
#define __univers_h_
#include "salle.h"

typedef struct Univ {
	salle s;
	struct Univ *droite;
	struct Univ *gauche;
} *univ,strUniv;

univ initUniv();
univ elmtGauche(univ);
univ elmtDroite(univ);

#endif

