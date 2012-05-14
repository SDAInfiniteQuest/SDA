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
	carte card;
	struct str_paquet *suiv;
} *paquet, strPaquet;
/**
 * \brief       initie un pointeru vers NULL
 * \details     
 *
 * @return    renvoie un paquet vide
 */
paquet paquetVide();
/**
 * \brief       ajoute une carte en tete
 * \details     
 *
 * @param 		paquet
 * @param 		carte
 * @return    un paquet
 */
paquet ajouterCarte(paquet,carte);
/**
 * \brief       supprime une carte en tete
 * \details     
 *
 * @param 		paquet
 * @return    un paquet
 */
paquet supprimerCarte(paquet);
/**
 * \brief       prend la carte au dessus du paquet
 * \details     
 *
 * @param 		paquet
 * @return    carte
 */
carte sommetPaquet(paquet);
Bool testVide(paquet);
/**
 * \brief       test si le paquet est vide
 * \details     
 *
 * @param 		paquet
 * @return    bool
 */
int longueur(paquet);
/**
 * \brief       tourne la paquet (la carte en tete passe en queue)
 * \details     
 *
 * @param 		paquet
 * @return    paquet
 */
paquet rotationPaquet(paquet);
/**
 * \brief       génére un paquet aléatoirement
 * \details     
 *
 * @param 		inventaire
 * @return    paquet
 */
paquet paquetGen(inventaire);
/**
 * \brief       combat de deux paquets de cartes
 * \details     a l'issue du combat un des protagonistes perd un point de vie
 *
 * @param 		monstre
 * @param 		hero
 * @return    entier (0 ou 1)
 */
int combat(monstre,hero);
/**
 * \brief       bataille entre deux protagonistes
 * \details     a l'issue de la bataille un des protagonistes perd , le fonction renvoie 0 si c'est le hero et 1 si c'est le monstre
 *
 * @param 		monstre
 * @param 		hero
 * @return    entier (0 ou 1)
 */
int bataille(monstre,hero);

#endif
