#include <stdlib.h>
#include <stdio.h>
#include "univers.h"

univ initUniv() {
	univ depart=(univ) malloc(sizeof(strUniv));
	depart->s=creerSalle();
	depart->droite=NULL;
	depart->gauche=NULL;
  remplirSalle(depart->s);
	return depart;
}

univ elmtDroite(univ elmt) {
	if (elmt->droite==NULL) {
		elmt->droite=initUniv();
		elmt->droite->gauche=elmt->droite;
	}
	return elmt->droite;
}

univ elmtGauche(univ elmt) {
	if (elmt->gauche==NULL) {
		elmt->gauche=initUniv();
		elmt->gauche->droite=elmt->gauche;
	}
	return elmt->gauche;
}


univ changement_salle(hero h,salle s,univ univers){
	if(h->x == s->taille/2 && h->y == s->taille-1 ){
	
			s->z[s->taille/2][s->taille-1].obj=NEUTRE;
			s->z[s->taille/2][s->taille-1].H=NULL;

			univers=elmtDroite(univers);

			h->y=univers->s->taille/2;
			h->x=0;

			univers->s->z[univers->s->taille/2][univers->s->taille-1].obj=HERO;
			univers->s->z[univers->s->taille/2][0].H=h;

		}
	else 
		if(h->x == s->taille/2 && h->y == 0 ){

			s->z[s->taille/2][s->taille-1].obj=NEUTRE;
			s->z[s->taille/2][s->taille-1].H=NULL;

			univers=elmtGauche(univers);

			h->y=univers->s->taille/2;
			h->x=univers->s->taille-1;

			univers->s->z[s->taille/2][s->taille-1].obj=HERO;
			univers->s->z[univers->s->taille/2][univers->s->taille-1].H=h;
		}	
	return univers;
}
	
