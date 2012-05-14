#ifndef _inventaire_h_
#define _inventaire_h_
#include<stdio.h>
#include<stdlib.h>

#define TAILLE_INVENTAIRE 50
#define NOMBRE_DE_CARTES 4

enum typeItem { CARTE, POTION };

/**
 * \struct    carte
 * \brief     
 * \details   
 */
typedef struct { 
	int ref;
	enum typeItem tpIt;
	char nom[20];
	int HP;
	int attaque;
	int defense;
} carte; 

/**
 * \struct    potion
 * \brief    
 * \details   
 */
typedef struct {
	int ref;
	enum typeItem tpIt;
	char nom[20];
	int HP;
} potion;

/**
 * \struct    item
 * \brief     potion ou cartes
 * \details   
 */
typedef union {
	int ref;
	carte card;
	potion po;
} type;
/**
 * \struct    items
 * \brief     potion ou cartes avec la quantite
 * \details   
 */
typedef struct {
	type tp;
	int qte;
} item; 

/**
 * \struct    inventaire
 * \brief     contient la place libre et un tableau des objets indexé par leurs références
 * \details   
 */
typedef struct {
	item it[TAILLE_INVENTAIRE];
	int place;
} *inventaire, str_inventaire;
/**
 * \brief       initie un pointeru vers NULL
 * \details     
 *
 * @return    renvoie un inventaire NULL
 */
inventaire stockVide();
/**
 * \brief       ajoute une reference
 * \details     
 *
 * @param 		inventaire NULL
 * @param 		objet a ajouter
 * @return    un inventaire vide
 */
inventaire ajoutRef(inventaire, type);
/**
 * \brief       supprime une reference
 * \details     
 *
 * @param 		inventaire
 * @param 		objet a enlever
 * @return    renvoie un inventaire
 */
inventaire supprRef(inventaire, type);
/**
 * \brief       ajoute quantite
 * \details     
 *
 * @param 		inventaire
 * @param 		objet a ajouter
 * @param 		quantite a ajouter
 * @return    renvoie un inventaire
 */
inventaire ajoutQte(inventaire, type, int);
/**
 * \brief       enlever quantite
 * \details     
 *
 * @param 		inventaire
 * @param 		objet a enlever
 * @param 		quantite a enlever
 * @return    renvoie un inventaire 
 */
inventaire supprQte(inventaire, type, int);
/**
 * \brief       test si l'inventaire est vide
 * \details     
 *
 * @param 		inventaire
 * @return    renvoie un booleen
 */
int estVide(inventaire);
/**
 * \brief       test si une reference existe
 * \details     
 *
 * @param 		inventaire
 * @param 		objet a enlever
 * @return    renvoie un booleen
 */
int existe(inventaire, type);
/**
 * \brief       verifie la quantite d'un objet referencé
 * \details     
 *
 * @param 		inventaire
 * @param 		objet 
 * @return    renvoie un entier
 */
int quantite(inventaire, type);
/**
 * \brief       renvoiue le nombre de reference
 * \details     
 *
 * @param 		inventaire
 * @return    renvoie un entier
 */
int nombreRef(inventaire);
/**
 * \brief       transfert le contenu d'un inventaire vers un autre
 * \details     
 *
 * @param 		inventaire source
 * @param 		inventaire arrive
 * @return    renvoie un inventaire
 */
inventaire transfert(inventaire, inventaire);
/**
 * \brief       cree un inventaire pour le hero
 * \details     
 *
 * @return    renvoie un inventaire
 */
inventaire creerInvHero();
/**
 * \brief       cree un inventaire pour le monstre
 * \details     
 *
 * @return    renvoie un inventaire
 */
inventaire creerInvMobs();
/**
 * \brief       cree un inventaire pour le coffre
 * \details     
 *
 * @return    renvoie un inventaire
 */
inventaire creerInvCoffre();



#endif
