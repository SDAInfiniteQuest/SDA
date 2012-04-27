#ifndef _inventaire_h_
#define inventaire_h_
#include<stdio.h>
#include<stdlib.h>

#define TAILLE_INVENTAIRE 50
#define NOMBRE_DE_CARTES 4

enum typeItem { CARTE, POTION };

//type carte
typedef struct { 
	enum typeItem tpIt;
	int ref;
	char nom[20];
	int HP;
	int attaque;
	int defense;
} carte; 

//type potion
typedef struct {
	enum typeItem tpIt;
	int ref;
	char nom[20];
	int HP;
} potion;

//type item
typedef union {
	enum typeItem tpIt;
	int ref;
	carte card;
	potion po;
} type;

typedef struct {
	type tp;
	int qte;
} item; 

//type inventaire
typedef struct {
	item it[TAILLE_INVENTAIRE];
	int place;
} *inventaire, str_inventaire;

inventaire stockVide();
inventaire ajoutRef(inventaire, type);
inventaire supprRef(inventaire, type);
inventaire ajoutQte(inventaire, type, int);
inventaire supprQte(inventaire, type, int);
int existe(inventaire, type);
int quantite(inventaire, type);
int nombreRef(inventaire);

//inventaire creerInvHero();
//inventaire creerInvMobs();

//objets de base de l'inventaire

//type potSante = {.po={POTION, 1, "potion de soin", 30}} ;
/*tabCarte[1] = { CARTE, 20, "fantassin", 4, 3, 2 };
tabCarte[2] = { CARTE, 21, "guerrier", 6, 8, 4 };
tabCarte[3] = { CARTE, 22, "barbare", 10, 7, 3 };
tabCarte[4] = { CARTE, 23, "tour", 30, 5, 0 };*/

/*type tabCarte[NOMBRE_DE_CARTES]={
	{ CARTE, 20, "fantassin", 4, 5, 2 },
	{ CARTE, 21, "guerrier", 6, 8, 4 },
	{ CARTE, 22, "barbare", 10,7, 3 },
	{ CARTE, 23, "tour", 30, 6, 0 }
};*/


#endif
