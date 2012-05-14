#ifndef _global_h_
#define _global_h_
#include <stdlib.h>
#include <stdio.h>
#include "objet.h"
#include "graphics.h"

#define vrai 1 								/**< Definition du booleen vrai */
#define faux 0 								/**< Definition du booleen faux */
#define NBR_MENU 1 						/**< Nombre d'elements dans le menu (0 compris) */
#define TAILLE_NOM_MAX 15 		/**< Taille maximal du nom du hero */
//#define TAILLE_BESTIAIRE 10



int menu();


hero creerHero();
monstre creerMonstre();
coffre creerCoffre();
void detruireCoffre(coffre);
void detruireMonstre(monstre);
void AfficherVie(hero);
void afficherOr(hero);
void PlanquerCurseur();
void DetruireHero(hero h);
void GameOver(hero h);



#endif
