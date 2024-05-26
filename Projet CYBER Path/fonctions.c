#include "fonctions.h"
#include "affichage.h"
#include "menu.h"

// Génère un tableau en 2D
char** generer_Tableau(int nb){
	char **tab = NULL;
	tab = malloc(nb * sizeof(char*));
	for (int i = 0; i < nb; i++){
		*(tab+i) = malloc(nb * sizeof(char));
	}
	return tab;
}

// Génère un nombre aléatoire entre a et b (inclus)
int generer_Nombre(int a, int b){
	int c = rand() % (b-a+1) + a;
	return c;
}

void effacer_ligne(){
	printf("\x1b[1F"); // Passer au début de la ligne précédente
	printf("\x1b[2K"); // Efface toute la ligne
}

void videScanf(){
	char c;
	int s;
	do {
		s = scanf("%c", &c);
	} while (c != '\n' && s == 1);
}

Coordonnees chercher_Tableau(char** tab, int r, int nb){
	Coordonnees co;
	for (int i = 0; i < nb; i++){
		for (int j = 0; j < nb; j++){
			if (tab[i][j] == r){
				co.i = i;
				co.j = j;
				break;
			}
		}
	}
	return co;
}

// Affiche la grille de jeu à partir des données qui sont dans le tableau en entrée
void afficher_Grille(Plateau c, Choix ch, int N){
	printf("\n");
	char lettres[18] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R'};
	char* couleur_robots[4] = {"37;41", "30;42", "30;43", "37;44"};
	for (int i = 0; i <= 2*N; i++){
		printf(ESPACE);
		printf(ESPACE);
		printf(ESPACE);
		for (int j = 0; j <= 4*N; j++){
			couleur(COULEUR_FOND);
			// Gère les murs horizontaux
			if (i%2 == 0){
				// Gère les symboles des murs
				if (j%2 == 0){
					// Cas du symbole sur les 4 coins
					if (((i == 0) || (i == 2*N)) && ((j == 0) || (j == 4*N))){
						couleur(COULEUR_MUR);
						// Bord en haut à gauche
						if ((i == 0) && (j == 0)){
							printf("╔");
						}
						// Bord en haut à droite
						if ((i == 0) && (j == 4*N)){
							printf("╗");
						}
						// Bord en bas à gauche
						if ((i == 2*N) && (j == 0)){
							printf("╚");
						}
						// Bord en bas à droite
						if ((i == 2*N) && (j == 4*N)){
							printf("╝");
						}
						couleur(REINITIALISATION);
					}
					// Cas du symbole sur les bords en haut et en bas
					if (((i == 0) || (i == 2*N)) && ((j != 0) && (j != 4*N))){
						couleur(COULEUR_MUR);
						// Croisement avec les murs verticaux de la grille
						if (j%4 == 0){
							// Bord en haut
							if (i == 0){
								printf("╦");
							}
							// Bord en bas
							if (i == 2*N){
								printf("╩");
							}
						}
						// Simple bord
						else {
							printf(MUR_HORIZONTAL);
						}
						couleur(REINITIALISATION);
					}
					// Cas du symbole sur le bord gauche ou droit
					if ((j == 0 && (i != 0 && i != 2*N)) || (j == 4*N && (i != 0 && i != 2*N))){
						couleur(COULEUR_MUR);
						// Bord gauche
						if (j == 0){
							printf("╠");
						}
						// Bord droit
						if (j == 4*N){
							printf("╣");
						}
						couleur(REINITIALISATION);
					}
					// Cas du symbole horizontal entre deux cases au centre de la grille
					if ((j%4 == 2) && ((i != 0) && (i != 2*N))){
						if (c.murs[i/2][j/4] == 5 || c.murs[i/2][j/4] == 2 || c.murs[i/2][j/4] == 6 || c.murs[i/2][j/4] == 9 || c.murs[i/2-1][j/4] == 4 || c.murs[i/2-1][j/4] == 7 || c.murs[i/2-1][j/4] == 8 || c.murs[i/2-1][j/4] == 9){
							couleur(COULEUR_MUR);
							printf(MUR_HORIZONTAL);
							couleur(REINITIALISATION);
						}
						else {
							couleur(COULEUR_BASE);
							printf(CASE_HORIZONTAL);
							couleur(REINITIALISATION);
						}
					}
					// Cas du symboles à la croisée de quatre cases au centre de la grille
					if ((j%4 == 0) && ((j != 0) && (j != 4*N)) && ((i != 0) && (i != 2*N))){
						if (c.murs[i/2][j/4] == 6 || c.murs[i/2][j/4] == 2 || c.murs[i/2][j/4] == 5 || c.murs[i/2][j/4] == 1 || c.murs[i/2][j/4] == 8 || c.murs[i/2][j/4] == 9 || c.murs[i/2][j/4] == 10 || c.murs[i/2-1][j/4] == 1 || c.murs[i/2-1][j/4] == 4 || c.murs[i/2-1][j/4] == 5 || c.murs[i/2-1][j/4] == 7 || c.murs[i/2-1][j/4] == 8 || c.murs[i/2-1][j/4] == 9 || c.murs[i/2-1][j/4] == 10 || c.murs[i/2-1][j/4-1] == 3 || c.murs[i/2-1][j/4-1] == 4 || c.murs[i/2-1][j/4-1] == 6 || c.murs[i/2-1][j/4-1] == 7 || c.murs[i/2-1][j/4-1] == 8 || c.murs[i/2-1][j/4-1] == 9 || c.murs[i/2-1][j/4-1] == 10 || c.murs[i/2][j/4-1] == 2 || c.murs[i/2][j/4-1] == 3 || c.murs[i/2][j/4-1] == 5 || c.murs[i/2][j/4-1] == 6 || c.murs[i/2][j/4-1] == 7 || c.murs[i/2][j/4-1] == 9 || c.murs[i/2][j/4-1] == 10){
							couleur(COULEUR_MUR);
							printf(MUR_CROISEMENT);
							couleur(REINITIALISATION);
						}
						else {
							couleur(COULEUR_BASE);
							printf(CASE_CROISEMENT);
							couleur(REINITIALISATION);
						}
					}
				}
				// Gère les petits espaces horizontaux entre les symboles du mur (aspect purement esthétique)
				else {
					// Cas sur les bords haut & bas
					if ((i == 0) || (i == 2*N)){
						couleur(COULEUR_MUR);
						printf(MUR_HORIZONTAL);
						couleur(REINITIALISATION);
					}
					// Cas au centre de la grille
					else {
						if (c.murs[i/2][j/4] == 2 || c.murs[i/2][j/4] == 5 || c.murs[i/2][j/4] == 6 || c.murs[i/2][j/4] == 9 || c.murs[i/2-1][j/4] == 4 || c.murs[i/2-1][j/4] == 7 || c.murs[i/2-1][j/4] == 8 || c.murs[i/2-1][j/4] == 9){
							couleur(COULEUR_MUR);
							printf(MUR_HORIZONTAL);
							couleur(REINITIALISATION);
						}
						else {
							couleur(COULEUR_BASE);
							printf(CASE_HORIZONTAL);
							couleur(REINITIALISATION);
						}
					}
				}
			}
			// Gère les cases et les murs verticaux
			else {
				// Gère les murs verticaux
				if (j%4 == 0){
					// Gère le cas du bord gauche et droit
					if ((j == 0) || (j == 4*N)){
						couleur(COULEUR_MUR);
						printf(MUR_VERTICAL);
						couleur(REINITIALISATION);
					}
					// Gère le cas du mur vertical entre les cases
					else {
						if (c.murs[i/2][j/4] == 1 || c.murs[i/2][j/4] == 5 || c.murs[i/2][j/4] == 8 || c.murs[i/2][j/4] == 10 || c.murs[i/2][j/4-1] == 3 || c.murs[i/2][j/4-1] == 6 || c.murs[i/2][j/4-1] == 7 || c.murs[i/2][j/4-1] == 10){
							couleur(COULEUR_MUR);
							printf(MUR_VERTICAL);
							couleur(REINITIALISATION);
						}
						else {
							couleur(COULEUR_BASE);
							printf(CASE_VERTICAL);
							couleur(REINITIALISATION);
						}
					}
				}
				// Gère le contenu des cases (robots ou cibles)
				else if (j%4 == 2){
					// Cas lorsqu'il y a une cible sur cette case
					if ((c.cibles[i/2][j/4] != 0) && (c.robots[i/2][j/4] == 0)){
						if (c.cibles[i/2][j/4] == ch.cible+1){
							couleur("5");
							couleur("37");
							printf("%c", lettres[(c.cibles[i/2][j/4])-1]);
						}
						else {
							couleur("37");
							printf("%c", lettres[(c.cibles[i/2][j/4])-1]);
						}
					}
					// Cas lorsqu'il y a un robot sur cette case
					if ((c.cibles[i/2][j/4] == 0) && (c.robots[i/2][j/4] != 0)){
						if (c.robots[i/2][j/4] == ch.robot){
							couleur("5");
							couleur(couleur_robots[c.robots[i/2][j/4]-1]);
							printf("%d", c.robots[i/2][j/4]);
							couleur(REINITIALISATION);
						}
						else {
						couleur(couleur_robots[c.robots[i/2][j/4]-1]);
						printf("%d", c.robots[i/2][j/4]);
						couleur(REINITIALISATION);
						}
					}
					if ((c.cibles[i/2][j/4] != 0) && (c.robots[i/2][j/4] != 0)){
						if (c.robots[i/2][j/4] == ch.robot){
							couleur("5");
							couleur(couleur_robots[c.robots[i/2][j/4]-1]);
							printf("%d", c.robots[i/2][j/4]);
							couleur(REINITIALISATION);
						}
						else {
							couleur(couleur_robots[c.robots[i/2][j/4]-1]);
							printf("%d", c.robots[i/2][j/4]);
							couleur(REINITIALISATION);
						}
					}
					// Cas d'une case vide
					if ((c.cibles[i/2][j/4] == 0) && (c.robots[i/2][j/4] == 0)){
						couleur(COULEUR_BASE);
						printf(" ");
						couleur(REINITIALISATION);
					}
				}
				// Gère les petits espacements verticaux entre le contenu des cases et les murs (aspect purement esthétique)
				else {
					couleur(COULEUR_BASE);
					printf(" ");
					couleur(REINITIALISATION);
				}
			}
			couleur(REINITIALISATION);
		}
		printf("\n");
	}
	printf("\n\n");
}
