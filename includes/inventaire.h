#ifndef _inventaire_h_
#define _inventaire_h_
#include<stdio.h>
#include<stdlib.h>

#define TAILLE_INVENTAIRE 50    /**< Taille maximal d'un paquet */
#define NOMBRE_DE_CARTES 4      /**< Nombre de meme carte maximal */



/**
 * \enum     typeItem
 * \brief    Soit une carte,soit une potion
 * \details   CARTE=0,POTION=1
 */
enum typeItem { CARTE, POTION };



/**
 * \struct    carte
 * \brief     
 * \details   
 */
typedef struct { 
	int ref;            /*!< Reference dans le stock */
	enum typeItem tpIt; /*!< Renseigne le type de carte */
	char nom[20];       /*!< Nom de la carte */
	int HP;             /*!< PV de la carte */
	int attaque;        /*!< Point d'attaque de la carte */
	int defense;        /*!< Point de defense de la carte */
} carte; 



/**
 * \struct    potion
 * \brief    
 * \details   
 */
typedef struct {
	int ref;             /*!< Reference dans le stock */
	enum typeItem tpIt;  /*!< Renseigne le type de potion */
	char nom[20];        /*!< Nom de la potion */
	int HP;              /*!< Pv rendue par la potion */
} potion;



/**
 * \union   type 
 * \brief     potion ou cartes
 * \details   
 */
typedef union {
	int ref;          /*!< Reference dans le stock */
	carte card;       /*!< Une carte */
	potion po;        /*!< Une potion */
} type;



/**
 * \struct    items
 * \brief     potion ou cartes avec la quantite
 * \details   
 */
typedef struct {
	type tp;         /*!< Type de l'item */
	int qte;         /*!< Quantite de l'item */
} item; 



/**
 * \struct    inventaire
 * \brief     contient la place libre et un tableau des objets indexé par leurs références
 * \details   
 */
typedef struct {
	item it[TAILLE_INVENTAIRE];     /*!< Tableau d'item */
	int place;                      /*!< taille restante dans l'inventaire */
} *inventaire, str_inventaire;    /*!< inventaire: pointeur sur la structure */



/**
 * \brief       initie un pointeru vers NULL
 * \details     
 *
 * @return    I renvoie un inventaire NULL
 */
inventaire stockVide();



/**
 * \brief       ajoute une reference
 * \details     
 *
 * @param 		i inventaire NULL
 * @param 		t objet a ajouter
 * @return    I un inventaire vide
 */
inventaire ajoutRef(inventaire i, type t);



/**
 * \brief       supprime une reference
 * \details     
 *
 * @param 		i inventaire
 * @param 		t objet a enlever
 * @return    I renvoie un inventaire
 */
inventaire supprRef(inventaire i, type t);



/**
 * \brief       ajoute quantite
 * \details     
 *
 * @param 		i inventaire
 * @param 		t objet a ajouter
 * @param 		quantite quantite a ajouter
 * @return    I renvoie un inventaire
 */
inventaire ajoutQte(inventaire i, type t, int quantite);



/**
 * \brief       enlever quantite
 * \details     
 *
 * @param 		i inventaire
 * @param 		t objet a enlever
 * @param 		quantite quantite a enlever
 * @return    I renvoie un inventaire 
 */
inventaire supprQte(inventaire i, type t, int quantite);



/**
 * \brief       test si l'inventaire est vide
 * \details     
 *
 * @param 		i inventaire
 * @return    B renvoie un booleen
 */
int estVide(inventaire i);



/**
 * \brief       test si une reference existe
 * \details     
 *
 * @param 		i inventaire
 * @param 		t objet a enlever
 * @return    B renvoie un booleen
 */
int existe(inventaire i, type t);



/**
 * \brief       verifie la quantite d'un objet referencé
 * \details     
 *
 * @param 		i inventaire
 * @param 		t objet 
 * @return    I renvoie un entier
 */
int quantite(inventaire i, type t);



/**
 * \brief       renvoie le nombre de reference
 * \details     
 *
 * @param 		i inventaire
 * @return    I renvoie un entier
 */
int nombreRef(inventaire i);



/**
 * \brief       transfert le contenu d'un inventaire vers un autre
 * \details     
 *
 * @param 		source inventaire source
 * @param 		arrive inventaire arrive
 * @return    I renvoie un inventaire
 */
inventaire transfert(inventaire source, inventaire arrive);



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
