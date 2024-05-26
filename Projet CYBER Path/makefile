all : exec


main.o : main.c fonctions.h affichage.h menu.h robots.h cible.h murs.h
	gcc -c main.c -o main.o

fonctions.o : fonctions.c fonctions.h affichage.h menu.h
	gcc -c fonctions.c -o fonctions.o

cible.o : cible.c fonctions.h
	gcc -c cible.c -o cible.o

murs.o : murs.c fonctions.h
	gcc -c murs.c -o murs.o

robots.o : robots.c fonctions.h
	gcc -c robots.c -o robots.o

menu.o : menu.c fonctions.h affichage.h
	gcc -c menu.c -o menu.o

exec: main.o fonctions.o cible.o murs.o robots.o menu.o
	gcc fonctions.o main.o murs.o cible.o robots.o menu.o -o exe

clean :
	rm -f *.o
	rm exe
