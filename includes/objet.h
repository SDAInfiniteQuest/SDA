/**
* \file objet.h
* \author Pallamidessi joseph, Andreux simon
* \version 1.0
* \date 14 mai 2012
* \brief Header de objet.c
*
* \details Contient les structure des objet (Entites) du jeu.
*
*/



#ifndef _objet_h_
#define _objet_h_
#include <stdlib.h>
#include <stdio.h>
#include "inventaire.h"



/**
 * \struct    Bool
 * \brief     Un type booleen 
 * \details   Pour certains test et return (lisibilite), 0 pour faux,1 pour vrai 
 */
typedef unsigned int Bool; /*!< Base sur un unsigned int */



//coffre---------------------------------------------------------------------------------------------------------------

/**
 * \enum     tresor
 * \brief    Soit de l'or,soit un bonus (objets)
 * \details   OR=0,BONUS=1
 */
enum tresor {
	OR,
	BONUS,
};



/**
 * \enum     bonus
 * \details   BONUS1=0,BONUS2=1,BONUS3=2
 */
enum bonus {
    BONUS1,
    BONUS2,
    BONUS3,
};



/**
 * \struct    str_coffre
 * \brief     Structure coffre contenant un inventaire et/ou des pieces (or) 
 * \details   Contient un inventaire (cf: str_inv) 
 */
typedef struct Coffre{
	Bool ouvert; /*!< Un bool pour savoir si le coffre est ouvert ou non*/
	enum tresor t; /*!< Une enum qui renseigne sur le contenu (un inventaire ou de l'or) */
	int pieces; /*!< Nombre de pieces d'or. */
	inventaire inv; /*!< L'inventaire associe. */
	enum bonus B; /*!< Renseigne le type de bonus contenu. */
}str_coffre,*coffre; /*!< coffre: pointeur sur la structure. */

//fin coffre-----------------------------------------------------------------------------------------------------------




//debut hero-----------------------------------------------------------------------------------------------------------

/**
 * \struct    strHero
 * \brief     Structure definissant le hero  
 * \details   Contient ses point de vie, son or,son inventaire et sa position x,y dans la salle.
 */
typedef struct {
    int HP; /*!< Nombre de points de vie. */
    char* nom; /*!< nom du hero. */
		int x; /*!< Position x dans la salle. */
		int y; /*!< Position y dans la salle. */
		int pieces; /*!< Nombre de pieces. */
    inventaire invHero; /*!< inventaire du hero. */
} strHero,*hero ; /*!< hero: pointeur sur la structure. */

//fin hero-------------------------------------------------------------------------------------------------------------



//debut monstre--------------------------------------------------------------------------------------------------------

/**
 * \struct    strMonstre
 * \brief     Structure definissant un monstre  
 * \details   Contient ses point de vie, son or,son inventaire.
 */
typedef struct {
	int HP; /*!< Nombre de point de vie. */
	char *nom; /*!< Nom du monstre. */
	int pieces; /*!< Nombre de pieces. */
	inventaire invMobs; /*!< Inventaire du monstre. */
} *monstre, strMonstre; /*!< monstre: pointeur sur la structure. */

//fin monstre----------------------------------------------------------------------------------------------------------

#endif
