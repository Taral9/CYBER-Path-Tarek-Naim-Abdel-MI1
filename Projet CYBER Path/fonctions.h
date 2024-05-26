#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct {
	char** cibles;
	char** murs;
	char** robots;
} Plateau;

typedef struct {
	int p1;
	int p2;
	int p3;
	int p4;
} Points_joueurs;

typedef struct {
	int i;
	int j;
} Coordonnees;

typedef struct {
	int robot;
	char cible;
} Choix;

typedef struct {
	int j;
	int mvt;
} Choix_Joueur;

char** generer_Tableau(int nb);

Coordonnees chercher_Tableau(char** tab, int r, int nb);

void afficher_Grille(Plateau c, Choix ch, int N);

int generer_Nombre(int a, int b);

void videScanf();

void effacer_ligne();
