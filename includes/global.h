/**
* \file global.h
* \author Pallamidessi joseph, Andreux simon
* \version 1.0
* \date 14 mai 2012
* \brief Header de global.c
*
* \details Contient les prototype des fonctions "universelles" et/ou d'affichage.
*
*/

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



/**
 * \brief       Affiche le menu et renvoie un int suivant le choix fait
 * \details     Renvoie 0 si le choix est continuer et 1 s'il on veut quitter 
 *
 * @return    I L'int correspondant au choix dans le menu
 */
int menu();



/**
 * \brief       Alloue en memoire et initialise un hero
 * \details     L'utilisateur rentre le nom du hero (caractere max==TAILLE_NOM_MAX).
 *
 * @return    H Le hero ainsi cree
 */
hero creerHero();



/**
 * \brief       Creer un monstre
 * \details     Alloue en memoire un monstre et l'initialise aleatoirement 
 *
 * @return    M Le monstre cree aleatoirement
 */
monstre creerMonstre();



/**
 * \brief       Creer un coffre
 * \details     Alloue en memoire un coffre et l'initialise aleatoirement 
 *
 * @return    U L'element de gauche de l'univ passe en parametre
 */
coffre creerCoffre();



/**
 * \brief       Desalloue un coffre
 *
 * @param     C Le coffre a desalloue
 */
void detruireCoffre(coffre C);



/**
 * \brief       Desalloue un monstre
 *
 * @param     M le monstre a desalloue
 */
void detruireMonstre(monstre M);



/**
 * \brief       Affiche la vie du hero dans le terminal
 * \details     Affiche la vie du hero sous forme d'une barre rouge ou une case vaut 1 PV
 *
 * @param     H Le hero dont on veut afficher la vie
 */
void AfficherVie(hero H);



/**
 * \brief       Affiche l'or du hero dans le terminal
 *
 * @param     H Le hero dont on veut afficher l'or
 */
void afficherOr(hero H);



/**
 * \brief       Cache le curseur de la console
 * \details     Cache le curseur de la console en l'affichant beaucoup plus bas
 *
 */
void PlanquerCurseur();



/**
 * \brief       Desalloue un monstre
 *
 * @param     h Le hero a desalloue
 */
void DetruireHero(hero h);



/**
 * \brief       Affiche l'ecran de game over
 * \details     Si le vie du hero atteint 0,alors l'ecran de game over apparait
 *
 * @param     h hero dont on doit verifier la vie
 */
void GameOver(hero h);

#endif
