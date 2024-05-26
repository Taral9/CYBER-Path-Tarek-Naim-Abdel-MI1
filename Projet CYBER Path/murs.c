#include "fonctions.h"

// Vérifie les cases autour des murs à l'extrémité de la grille pour éviter d'avoir des cases sans issue avec 3 murs
int casesVidesMurs(char** tab, int m, int n, int code){
	int verif = 1;
	switch (code){
		case 5:
			for (int i = m; i <= m+1; i++){
				for (int j = n-1; j <= n; j++){
					if (tab[i][j] != 0){
						verif = 0;
						break;
					}
				}
			}
			break;
		case 6:
			for (int i = m-1; i <= m; i++){
				for (int j = n-1; j <= n; j++){
					if (tab[i][j] != 0){
						verif = 0;
						break;
					}
				}
			}
			break;
		case 7:
			for (int i = m-1; i <= m; i++){
				for (int j = n; j <= n+1; j++){
					if (tab[i][j] != 0){
						verif = 0;
						break;
					}
				}
			}
			break;
		case 8:
			for (int i = m; i <= m+1; i++){
				for (int j = n; j <= n+1; j++){
					if (tab[i][j] != 0){
						verif = 0;
						break;
					}
				}
			}
			break;
	}
	return verif;
}

// Initialise correctement les murs de la case passé en paramètre
// Codes -> 0 : Libre / 1 : Gauche / 2 : Haut / 3 : Droite / 4 : Bas / 5 : Gauche & haut / 6 : Haut & droite / 7 : Droite & bas / 8 : Bas & gauche / 9 : Haut & bas / 10 : Gauche & droite
char** init_Murs(char** tab, int i, int j, int code, int nb){
	tab[i][j] = code;
	switch(code){
		// Initialise les murs alentours dans le cas où le mur sur la case passée en paramètres est perpendiculaire à gauche et en haut
		case 5:
			if (i > 0 && j > 0){
				if (tab[i-1][j] == 0){
					tab[i-1][j] = 4;
				}
				else if (tab[i-1][j] == 2){
					tab[i-1][j] = 9;
				}
				if (tab[i][j-1] == 0){
					tab[i][j-1] = 3;
				}
				else if (tab[i][j-1] == 1){
					tab[i][j-1] = 10;
				}
			}
			else if (i == 0){
				tab[i][j-1] = 6;
			}
			break;
		// Initialise les murs alentours dans le cas où le mur sur la case passée en paramètres est perpendiculaire à droite et en haut
		case 6:
			if (i > 0 && j < nb-1){
				if (tab[i][j+1] == 0){
					tab[i][j+1] = 1;
				}
				else if (tab[i][j+1] == 3){
					tab[i][j+1] = 10;
				}
				if (tab[i-1][j] == 0){
					tab[i-1][j] = 4;
				}
				else if (tab[i-1][j] == 2){
					tab[i-1][j] = 9;
				}
			}
			else if (j == nb-1){
				tab[i-1][j] = 7;
			}
			break;
		// Initialise les murs alentours dans le cas où le mur sur la case passée en paramètres est perpendiculaire à droite et en bas
		case 7:
			if (i < nb-1 && j < nb-1){
				if (tab[i][j+1] == 0){
					tab[i][j+1] = 1;
				}
				else if (tab[i][j+1] == 3){
					tab[i][j+1] = 10;
				}
				if (tab[i+1][j] == 0){
					tab[i+1][j] = 2;
				}
				else if (tab[i+1][j] == 4){
					tab[i+1][j] = 9;
				}
			}
			else if (i == nb-1){
				tab[i][j+1] = 8;
			}
			break;
		// Initialise les murs alentours dans le cas où le mur sur la case passée en paramètres est perpendiculaire à gauche et en bas
		case 8:
			if (i < nb-1 && j > 0){
				if (tab[i][j-1] == 0){
					tab[i][j-1] = 3;
				}
				else if (tab[i][j-1] == 1){
					tab[i][j-1] = 10;
				}
				if (tab[i+1][j] == 0){
					tab[i+1][j] = 2;
				}
				else if (tab[i+1][j] == 4){
					tab[i+1][j] = 9;
				}
			}
			else if (j == 0){
				tab[i+1][j] = 5;
			}
			break;
	}
	return tab;
}

// Génère le tableau de gestion des murs de la grille
char** generer_Murs(char** cibles, int nb){
	char** tab = NULL;
	tab = generer_Tableau(nb);
	char m1, m2;
	// Génère les murs sur les bords de la grille
	for (int i = 0; i < nb; i++){
		for (int j = 0; j < nb; j++){
			if (i == 0){
				if (j == 0){
					tab[i][j] = 5;
				}
				else if (j == nb-1){
					tab[i][j] = 6;
				}
				else{
					tab[i][j] = 2;
				}
			}
			else if (i == nb-1){
				if (j == 0){
					tab[i][j] = 8;
				}
				else if (j == nb-1){
					tab[i][j] = 7;
				}
				else{
					tab[i][j] = 4;
				}
			}
			else{
				if (j == 0){
					tab[i][j] = 1;
				}
				else if (j == nb-1){
					tab[i][j] = 3;
				}
				else{
					tab[i][j] = 0;
				}
			}
		}
	}
	// Génère les murs aléatoires perpendiculaires du côté gauche
	do {
		m1 = generer_Nombre(2, nb-3);
		m2 = generer_Nombre(2, nb-3);
		while (casesVidesMurs(cibles, m1, 0, 8) != 1){
			m1 = generer_Nombre(2, nb-3);
		}
		while (casesVidesMurs(cibles, m2, 0, 8) != 1){
			m2 = generer_Nombre(2, nb-3);
		}
	} while (m2 - m1 < 4 && m1 - m2 < 4);
	for (int i = 2; i <= nb-3; i++){
		if (i == m1 || i == m2){
			init_Murs(tab, i, 0, 8, nb);
		}
	}
	// Génère les murs aléatoires perpendiculaires du côté haut
	do {
		m1 = generer_Nombre(2, nb-3);
		m2 = generer_Nombre(2, nb-3);
		while (casesVidesMurs(cibles, 0, m1, 5) != 1){
			m1 = generer_Nombre(2, nb-3);
		}
		while (casesVidesMurs(cibles, 0, m2, 5) != 1){
			m2 = generer_Nombre(2, nb-3);
		}
	} while (m2 - m1 < 4 && m1 - m2 < 4);
	for (int j = 2; j <= nb-3; j++){
		if (j == m1 || j == m2){
			init_Murs(tab, 0, j, 5, nb);
		}
	}
	// Génère les murs aléatoires perpendiculaires du côté droit
	do {
		m1 = generer_Nombre(2, nb-3);
		m2 = generer_Nombre(2, nb-3);
		while (casesVidesMurs(cibles, m1, nb-1, 6) != 1){
			m1 = generer_Nombre(2, nb-3);
		}
		while (casesVidesMurs(cibles, m2, nb-1, 6) != 1){
			m2 = generer_Nombre(2, nb-3);
		}
	} while (m2 - m1 < 4 && m1 - m2 < 4);
	for (int i = 2; i <= nb-3; i++){
		if (i == m1 || i == m2){
			init_Murs(tab, i, nb-1, 6, nb);
		}
	}
	// Génère les murs aléatoires perpendiculaires du côté bas
	do {
		m1 = generer_Nombre(2, nb-3);
		m2 = generer_Nombre(2, nb-3);
		while (casesVidesMurs(cibles, nb-1, m1, 7) != 1){
			m1 = generer_Nombre(2, nb-3);
		}
		while (casesVidesMurs(cibles, nb-1, m2, 7) != 1){
			m2 = generer_Nombre(2, nb-3);
		}
	} while (m2 - m1 < 4 && m1 - m2 < 4);
	for (int j = 2; j <= nb-3; j++){
		if (j == m1 || j == m2){
			init_Murs(tab, nb-1, j, 7, nb);
		}
	}
	// Génère aléatoirement les murs en angle droit autour des cibles
	for (int i = 0; i < nb; i++){
		for (int j = 0; j < nb; j++){
			if (cibles[i][j] != 0){
				init_Murs(tab, i, j, generer_Nombre(5, 8), nb);
			}
		}
	}
	return tab;
}
