#include<stdlib.h>
#include<stdio.h>
#include"univers.h"
#include<time.h>
#include"global.h"

int main(){
int entree=0;
int valmenu=0;
srand(time(NULL));
univ test=initUniv();

ActiverModeRaw();

	while(valmenu!=1){
		entree=RecupererAppuiTouche();
		EffacerEcran();
	if (entree==TOUCHE_M_MIN)
				valmenu=menu();
		else
				afficheSalle(test->s);
		}
		EffacerEcran();
DesactiverModeRaw();
return 0;	
	}
