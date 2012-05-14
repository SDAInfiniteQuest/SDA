/**
* \file univers.h
* \author Pallamidessi joseph, Andreux simon
* \version 1.0
* \date 14 mai 2012
* \brief Header de univers.c
*
* \details Contient les prototype des fonctions relative a l'environnement de jeu.
*
*/



#ifndef _univers_h_
#define _univers_h_
#include "salle.h"
#include "objet.h"


/**
 * \struct    strUniv
 * \brief     Liste doublement chainee des salles du jeu.
 * \details   structure representant l'integralite de l'environnement du jeu.
 */
typedef struct Univ {
	salle s; /*!< Une salle  */
	int numero; /*!< Le numero de la salle. */
	struct Univ *droite; /*!< Pointeur vers le maillon a droite. */
	struct Univ *gauche; /*!< Pointeur vers le maillon a gauche. */
} *univ,strUniv; /*!< univ: pointeur sur la structure . */



/**
 * \brief       Alloue en memoire un strUniv
 * \details     Alloue un strUniv et appelle remplirSalle() qui remplie aleatoirement la salle
 *
 * @return    U L'univ alloue.
 */
univ initUniv();



/**
 * \brief       Renvoie l'univ de gauche de l'Univ passe en parametre
 * \details     Creer un Univ et le chaine a gauche de l'univ passer en parametre s'il n'existe pas
 *
 * @param     u L'univ dont on veux recuperer l'element a gauche
 * @return    U L'element de gauche de l'univ passe en parametre
 */
univ elmtGauche(univ u);



/**
 * \brief       Renvoie l'univ de droite de l'Univ passe en parametre
 * \details     Creer un Univ et le chaine a droite de l'univ passer en parametre s'il n'existe pas
 *
 * @param     u L'univ dont on veux recuperer l'element a droite
 * @return    U L'element de droite de l'univ passe en parametre
 */
univ elmtDroite(univ u);



/**
 * \brief       Fonction de changement de salle
 * \details     Si le hero est sur le seuil d'une des portes de la salle il passe a la salle correspondante
 *
 * @param     h Le hero a deplacer 
 * @param     s La salle courante
 * @param     univers L'univers courant 
 * @return    U renvoie l'univ correspant a la salle (a gauche ou a droite) ou le hero doit etre
 */
univ changement_salle(hero h,salle s,univ univers);



/**
 * \brief       Affiche le nom de la salle et son numero dans le terminal
 *
 * @param     univers L'univers courant 
 */
void TitreSalle(univ univers);



/**
 * \brief       Desalloue toute la liste doublement chainee 
 * \details     On se place sur l'element le plus a gauche du en desalloue vers la droite en desalouant les salles associees en appellant detruireSalle() .
 *
 * @param     univers N'importe quels chainons de la liste doublement chainee
 */
void DetruireUnivers(univ univers);
#endif

