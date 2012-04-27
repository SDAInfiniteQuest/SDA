#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"inventaire.h"

inventaire stockVide() {
	inventaire inv=(inventaire) calloc(1,sizeof(str_inventaire));
	inv->place=TAILLE_INVENTAIRE;
	return inv;
}

inventaire ajoutRef(inventaire inv, type t) {
	if (existe(inv,t)!=1) {
		if (t.tpIt==CARTE) inv->it[t.ref].tp=t;
		if (t.tpIt==POTION) inv->it[t.ref].tp=t;
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
	if (inv->it[t.ref].tp.ref==t.ref) return 1;
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
/*
inventaire creerInvHero() {
	inventaire inv=stockVide();

	ajoutRef(inv, potSante);
	ajoutQte(inv, potSante, 7);
	
	ajoutRef(inv, tabCarte[0]);
	ajoutRef(inv, tabCarte[1]);	
	ajoutRef(inv, tabCarte[2]);
	ajoutRef(inv, tabCarte[3]);
	
	ajoutQte(inv, tabCarte[0], 7);
	ajoutQte(inv, tabCarte[1], 4);
	ajoutQte(inv, tabCarte[2], 4);
	ajoutQte(inv, tabCarte[3], 2);
	
	return inv;
}

inventaire creerInvMobs(){
	inventaire inv=stockVide();
	int i,qte;
	
	for(i=0;i<NOMBRE_DE_CARTES;i++) {
		qte=rand()%6;
		ajoutRef(inv, tabCarte[i]);
		ajoutQte(inv, tabCarte[i], qte);
	}

	return inv;
}
*/
