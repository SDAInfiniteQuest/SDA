/**
* \file salle.h
* \author Pallamidessi joseph, Andreux simon
* \version 1.0
* \date 14 mai 2012
* \brief Header de salle.c
*
* \details Contient les prototype des fonctions relative au salle.
*
*/




#ifndef _salle_h_
#define _salle_h_
#include "objet.h"
#include "graphics.h" 
#include "global.h" 

#define MIN_TAILLE 5      	/**< Taille minimal des salles */
#define MAX_TAILLE 15       /**< Taille maximal des salles */
#define MIN_COFFRE 0      	/**< Nombre minimal de coffres */
#define MAX_COFFRE 2        /**< Nombre maximal de coffres */
#define MIN_MONSTRE 1       /**< Nombre minimal de monstres */
#define MAX_MONSTRE 3       /**< Nombre maximal de monstres */
#define NBR_MONSTRE_JEU 10  /**< Nombre de monstres different dans le jeu */


//debut zone---------------------------------------------------------------------------------------------------------------
/**
 * \enum     terrain
 * \brief    Renseigne le type de "dalle"
 * \details   MUR=0,SOL=1
 */
enum terrain {
	MUR,
	SOL
};


/**
 * \enum     objet
 * \brief    Renseigne le type "d'objet" sur une dalle (hero,monstre ou coffre)
 * \details   HERO=0,MONSTRE=1,COFFRE=2,NEUTRE=3
 */
enum objet {
	HERO,
	MONSTRE,
	COFFRE,
	NEUTRE         // Sinon toutes les cases sont forcement soit des monstres soit des heros soit des coffres
};



/**
 * \struct    zone
 * \brief     Une zone (une dalle de la salle) et tout ce quelle contient  
 * \details   Deux enum ,un qui renseigne si c'est du sol ou un mur,et l'autre le type d'objet qui si trouve.
 * Un pointeur sur un hero, un monstre et un coffre, qui sont Null s'il n'y a pas un tel objet dessus 
 */
typedef struct {
	enum terrain ter; /*!< Renseigne le type de zone (mur ou sol). */
	enum objet obj; /*!< Renseigne le type d'objet qui s'y trouve (hero,monstreou coffre). */
	hero H; /*!< Pointe sur le hero qui se trouve sur cette zone, sinon NULL. */
	monstre mobs; /*!< Pointe sur le monstre qui se trouve sur cette zone, sinon NULL. */
	coffre C; /*!< Pointe sur le coffre qui se trouve sur cette zone, sinon NULL. */
} zone;

//fin zone-----------------------------------------------------------------------------------------------------------------



/**
 * \struct    strSalle
 * \brief     Uns salle, qui est composee de zones (dalles)  
 * \details   Contient une matrice de zone et un numero de salle, ainsi que la taille de la matrice (salle).
 */
typedef struct salle {
	int numero; /*!< Le numero de la salle. */
	zone **z; /*!< La matrice de zones. */
	int taille;      /*!< Taille de la salle. */ // vu que c'est creer aleatoirement mieux vos stocker la taille de la salle dans la str
} *salle, strSalle; /*!< salle: pointeur sur la structure. */



/**
 * \brief       Donne un nombre aleatoire entre a et b compris. 
 *
 * @param     a int pour la valeur min de l'intervalle. 
 * @param     b int pour la veleur max de l'intervalle.
 * @return    resultat un int: le nombre aleatoire obtenu.
 */
int randIntervalle(int a,int b);



/**
 * \brief       Alloue la memoire pour une salle
 * \details     On initialise tout les pointeur sur hero,monstre et coffre a NULL,et le numero salle est egale a la variable global numeroSalle qu'on incremente. 
 *
 * @return    s Le pointeur sur la salle alloue.
 */
salle creerSalle();



/**
 * \brief       Creer aleatoirement un contenu de salle donnee.
 * \details     On passe tout les zones de la matrice en sol, avec un objet NEUTRE dessus, puis on rajoute les murs sur le cote de la salle, les monstres en les creant aleatoirement,les coffre en les creant aleatoirement, puis les mur aleatoire au milieux de la salle. 
 *
 * @param     s une salle deja alloue en memoire 
 * @return    S une salle rempli aleatoirement de monstres,coffres et murs.
 */
salle remplirSalle(salle s);


 
/**
 * \brief       Desalloue une salle
 *
 * @param     s la salle a free.
 */                         
void detruireSalle(salle s);



/**
 * \brief       Affiche une salle
 * \details     Affiche une salle dans le terminal,avec des murs en blanc, et des indication (M,H,C) en couleurs  	*pour les hero,monstre et coffre.
 *
 * @param     s La salle a afficher
 */
void afficheSalle(salle s);



/**
 * \brief       Insere le hero sur la premiere salle creer (debut du jeu)
 * \details     Le hero est inserer sur la zone (2,2) de la premiere salle
 *
 * @param     s La salle ou inserer le hero (ici la premiere). 
 * @param     h Le hero a inserer.
 */
void insererHero(salle s,hero h);



/**
 * \brief       Fonction de deplacement
 * \details     Le hero est bloquer par les murs,si le deplacement n'est pas possible le fonction renvoie le bool faux. 
 *
 * @param     h Le hero a deplacer 
 * @param     s La salle ou il se deplace
 * @param     entree Un int correspondant a l'entree clavier fournit par l'utilisateur 
 * @return    B renvoie vrai si le deplacement est possible sinon faux.
 */
Bool deplacement(hero h,salle s,int entree);



/**
 * \brief       Ouvre un coffre et le hero recupere le contenu
 * \details     Le hero recupere de l'or ou des items (cartes,potion..) contenu dans le coffre.
 *
 * @param     s La salle courante 
 * @param     h Le hero qui recupere le contenu du coffre
 */
void OuvrirCoffre(salle s,hero h);



/**
 * \brief       Renvoie un monstre s'il est sur la case du hero,sinon renvoie NULL 
 *
 * @param     s La salle courante 
 * @param     h le hero, pour recuperer sa position
 * @return    M Le pointeur sur le monstre,si monstre il ya , sinon revoie NULL.
 */
monstre CaseMonstre(salle s, hero h);

#endif
