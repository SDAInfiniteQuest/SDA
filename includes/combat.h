/**
* \file combat.h
* \author Pallamidessi joseph, Andreux simon
* \version 1.0
* \date 14 mai 2012
* \brief Header de combat.c
*
* \details Contient les prototype des fonctions relative au combat dans le jeu.
*
*/

#ifndef _combat_h_
#define _combat_h_
#include<stdlib.h>
#include<stdio.h>
#include "objet.h"

/**
 * \struct    paquet
 * \brief     Liste chainee ciculaire
 * \details   modélise le comportement d'un un paquet de carte
 */
typedef struct str_paquet {
	carte card;                /*!< Une carte */
	struct str_paquet *suiv;   /*!< pointeur sur le paquet suivant*/
} *paquet, strPaquet;        /*!< paquet: pointeur sur la structure */



/**
 * \brief       initie un pointeru vers NULL
 * \details     
 *
 * @return   P renvoie un paquet vide
 */
paquet paquetVide();



/**
 * \brief       ajoute une carte en tete
 * \details     
 *
 * @param 		p paquet
 * @param 		c carte
 * @return    R un paquet
 */
paquet ajouterCarte(paquet p,carte c);



/**
 * \brief       supprime une carte en tete
 * \details     
 *
 * @param 		p paquet
 * @return    R un paquet
 */
paquet supprimerCarte(paquet p);



/**
 * \brief       prend la carte au dessus du paquet
 * \details     
 *
 * @param 		p paquet
 * @return    C carte
 */
carte sommetPaquet(paquet p);



/**
 * \brief       Test si un paquet est vide
 * \details     
 *
 * @param 		p paquet
 * @return    B carte
 */
Bool testVide(paquet p);



/**
 * \brief      Donne la taille d'un paquet (nombre de carte)
 * \details     
 *
 * @param 		p paquet
 * @return    I la taille du paquet 
 */
int longueur(paquet p);



/**
 * \brief       tourne la paquet (la carte en tete passe en queue)
 * \details     
 *
 * @param 		p paquet
 * @return    R paquet
 */
paquet rotationPaquet(paquet p);



/**
 * \brief       génére un paquet aléatoirement
 * \details     
 *
 * @param 		i inventaire
 * @return    P paquet
 */
paquet paquetGen(inventaire i);



/**
 * \brief       combat de deux paquets de cartes
 * \details     a l'issue du combat un des protagonistes perd un point de vie
 *
 * @param 		m monstre
 * @param 		h hero
 * @return    I entier (0 ou 1)
 */
int combat(monstre m,hero h);



/**
 * \brief       bataille entre deux protagonistes
 * \details     a l'issue de la bataille un des protagonistes perd , le fonction renvoie 0 si c'est le hero et 1 si c'est le monstre
 *
 * @param 		m monstre
 * @param 		h hero
 * @return    I entier (0 ou 1)
 */
int bataille(monstre m,hero h);

#endif
