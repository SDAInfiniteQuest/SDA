#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"inventaire.h"

type potSante = {.card={POTION, 1, "potion de soin", 5, 0, 0}} ;
type fantassin = {.card={CARTE, 20, "fantassin", 4, 3, 2}};
type guerrier = {.card={CARTE, 21, "guerrier", 6, 8, 4}};
type barbare = {.card={CARTE, 22, "barbare", 10, 7, 3}};
type tour = {.card={CARTE, 23, "tour", 30, 5, 0}};
type sorcier = {.card={CARTE, 24, "sorcier", 15, 4, 1}};


inventaire stockVide() {
	inventaire inv=(inventaire) calloc(1,sizeof(str_inventaire));
	inv->place=TAILLE_INVENTAIRE;
	return inv;
}

inventaire ajoutRef(inventaire inv, type t) {
	if (existe(inv,t)!=1) {
		if (t.card.tpIt==CARTE) inv->it[t.ref].tp.card=t.card;
		if (t.po.tpIt==POTION) inv->it[t.ref].tp.po=t.po;
	}
	return inv;
}

inventaire supprRef(inventaire inv, type t) {
	if (existe(inv,t)==1) {
		inv->it[t.ref].tp.ref=0;
		inv->it[t.ref].qte=0;
	}
	return inv;
}

inventaire ajoutQte(inventaire inv, type t, int qte) {
	int dispo=9-inv->it[t.ref].qte;
	int rempli;
	if (qte>dispo) rempli=dispo;
	else rempli=qte;
	if (inv->place+rempli>TAILLE_INVENTAIRE) {
		rempli=TAILLE_INVENTAIRE-inv->place;
	}
	
	inv->it[t.ref].qte+=rempli;	
	inv->place-=rempli;
	
	return inv;
}

inventaire supprQte(inventaire inv, type t, int qte) {
	int rempli=inv->it[t.ref].qte;
	if (qte>rempli){
		inv->it[t.ref].qte=0;
		inv->place+=rempli;
	}
	else {
		inv->it[t.ref].qte-=qte;
		inv->place+=qte;
	}
	
	return inv;
}

int existe(inventaire inv, type t) {
	if (inv->it[t.ref].tp.card.ref==t.ref) return 1;
	else return 0;
}

int quantite(inventaire inv, type t) {
	return inv->it[t.ref].qte;
}

int nombreRef(inventaire inv) {
	int i,ref; ref=0;
	for(i=0;i<TAILLE_INVENTAIRE;i++) {
		if (inv->it[i].tp.ref!=0) ref++;
	}
	return ref;
}

inventaire creerInvHero() {
	inventaire inv=stockVide();

	ajoutRef(inv, potSante);
	ajoutQte(inv, potSante, 3);
	
	ajoutRef(inv, fantassin);
	ajoutQte(inv, fantassin, 4);
	
	ajoutRef(inv, guerrier);
	ajoutQte(inv, guerrier, 3);
	
	ajoutRef(inv, barbare);
	ajoutQte(inv, barbare, 3);
	
	ajoutRef(inv, tour);	
	ajoutQte(inv, tour, 2);

	ajoutRef(inv, sorcier);
	ajoutQte(inv, sorcier, 2);
	
	return inv;
}

inventaire creerInvMobs(){
	inventaire inv=stockVide();
	
	ajoutRef(inv, fantassin);
	ajoutQte(inv, fantassin, rand()%9+1);
	
	ajoutRef(inv, guerrier);
	ajoutQte(inv, guerrier, rand()%4+1);
	
	ajoutRef(inv, barbare);
	ajoutQte(inv, barbare, rand()%4+1);
	
	ajoutRef(inv, tour);	
	ajoutQte(inv, tour, rand()%3);

	ajoutRef(inv, sorcier);
	ajoutQte(inv, sorcier, rand()%3);
	
	return inv;
}

inventaire creerInvCoffre(){
	inventaire inv=stockVide();

	ajoutRef(inv, potSante);
	ajoutQte(inv, potSante, rand()%2);
	
	ajoutRef(inv, fantassin);
	ajoutQte(inv, fantassin, rand()%2);
	
	ajoutRef(inv, guerrier);
	ajoutQte(inv, guerrier, rand()%2);
	
	ajoutRef(inv, barbare);
	ajoutQte(inv, barbare, rand()%2);
	
	ajoutRef(inv, tour);	
	ajoutQte(inv, tour, rand()%2);

	ajoutRef(inv, sorcier);
	ajoutQte(inv, sorcier, rand()%2);
	
	return inv;
}

