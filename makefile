main:main.o salle.o graphics.o univers.o combat.o global.o
	gcc -o test $^

main.o:main.c
	gcc -Wall -g -c main.c

salle.o: salle.c salle.h objet.h global.h
	gcc -Wall -g -c salle.c

graphics.o:graphics.c  graphics.h
	gcc -Wall -g -c graphics.c 

univers.o: univers.c salle.h univers.h
	gcc -Wall -g -c univers.c

combat.o: combat.c objet.h combat.h
	gcc -Wall -g -c combat.c
global.o:global.c global.h graphics.h
	gcc -Wall -g -c global.c
