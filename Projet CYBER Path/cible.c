#include "fonctions.h"

// Vérifie les cases autour de la case spécifié et retourne 1 si toutes les cases sont vides, 0 sinon
int casesVides(char** tab, int m, int n){
	char vide = 1;
	for (int i = m-1; i <= m+1; i++){
		for (int j = n-1; j <= n+1; j++){
			if (tab[i][j] != 0){
				vide = 0;
				break;
			}
		}
	}
	return vide;
}

// Génère aléatoirement 18 cibles sur le plateau
char** generer_Cibles(int nb) {
	char** tab = NULL;
	int a;
	int b;
    tab = generer_Tableau(nb);
	for (int i = 0; i < nb; i++){
		for (int j = 0; j < nb; j++){
			tab[i][j] = 0;
		}
	}
	for (int cibles = 1; cibles <= 18; cibles++){
		do {
			a = generer_Nombre(1, nb-2);
			b = generer_Nombre(1, nb-2);
		}
		while (casesVides(tab, a, b) != 1);
		tab[a][b] = cibles;
	}
  	return tab;
}
