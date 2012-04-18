#include<stdlib.h>
#include<stdio.h>
#include"univers.h"
#include<time.h>

int main(){

srand(time(NULL));
univ test=initUniv();
afficheSalle(test->s);
	
return 0;	
	}
