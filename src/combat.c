#include <stdio.h>
#include <stdlib.h>
#include"combat.h"

paquet paquetVide() {
	return NULL;
}

paquet ajouterCarte(paquet P,carte C) {
	paquet P2,tmp;
	P2 = (paquet) malloc(sizeof(strPaquet));
	if (P==NULL) {
		P2->card=C;
		P2->suiv=P2;
		free(P);
	}
	else {
		tmp=P->suiv;
		P->suiv=P2;
		P2->suiv=tmp;
	}
	return P2;
}

paquet supprimerCarte(paquet P) {
	paquet tmp;
	if (P!=NULL) {
		tmp=P->suiv;
		P->suiv=P->suiv->suiv;
		free(tmp);
	}
	return P;
}

carte sommetPaquet(paquet P) {
	return P->suiv->card;
}

Bool testVide(paquet P) {
	return (P==NULL)?1:0;
}

paquet rotationPaquet(paquet P) {
	return P->suiv;
}


paquet paquetGen(inventaire inv) {
	int i,j; int k=0;
	paquet P=paquetVide();
	carte *C=(carte*) calloc(TAILLE_INVENTAIRE,sizeof(carte));
	
	//on insère les cartes dans un tableau
	for(i=0;i<TAILLE_INVENTAIRE;i++) {
		if ((inv->it[i].tp.ref!=0)&&(inv->it[i].tp.tpIt==CARTE)&&(inv->it[i].qte>0)) {
			for(j=0;j<inv->it[i].qte;j++) {
				if (k<TAILLE_INVENTAIRE) {
					C[k]=inv->it[i].tp.card;
					k++;
				}
			}
		}
	}

	//on cree la liste de combat aléatoirement a partir du tableau
	while(k>0) {
		j=rand()%(k+1);
		P=ajouterCarte(P,C[j]);
		C[j]=C[k];
		k--;
	}
	P=ajouterCarte(P,C[0]);
	
	free(C);

	return P;
}

int combat(monstre mobs, hero oreh) {
	paquet pqtMobs, pqtHero; carte cardMobs, cardHero;
	pqtMobs=paquetGen(mobs->invMobs);
	pqtHero=paquetGen(oreh->invHero);
	
	while ((pqtMobs!=NULL)&&(pqtHero!=NULL)) {
		cardHero=sommetPaquet(pqtHero);
		cardMobs=sommetPaquet(pqtMobs);
		if (cardMobs.attaque>cardHero.defense) {
			cardHero.HP=cardHero.HP-(cardMobs.attaque-cardHero.defense);
		}
		if (cardMobs.defense<cardHero.attaque) {
			cardMobs.HP=cardMobs.HP-(cardHero.attaque-cardMobs.defense);
		}
		if (cardHero.HP<=0) {
			supprimerCarte(pqtHero);
			if (cardMobs.HP<=0) supprimerCarte(pqtMobs);
			else rotationPaquet(pqtMobs);
		}
		else {
			rotationPaquet(pqtHero);
			if (cardMobs.HP<=0) supprimerCarte(pqtMobs);
			else rotationPaquet(pqtMobs);
		}
	}

	if (pqtMobs==NULL) {
		mobs->HP--;
		return 0;
	}
	else {
		oreh->HP--;
		return 1;
	}
}

int bataille(monstre *mobs, hero oreh) {
	int r;
	monstre m=mobs[rand()%10];
	while ((m->HP>0)&&(oreh->HP>0)) {
		r=combat(m,oreh);
	}
	return r;
}
