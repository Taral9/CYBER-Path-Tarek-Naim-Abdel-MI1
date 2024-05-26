#include "fonctions.h"
#include "affichage.h"

// Vérifie si la case est vide alors retourne 1, 0 sinon
int caseVide(char** tab, int i, int j){
	if (i < 0 || j < 0){
		exit(3);
	}
	int rep = 1;
	if (tab[i][j] != 0){
		rep = 0;
    }
    return rep;
}

// Gère le déplacement des robots
char** dep_Robots(Plateau p, Choix c, char dep, int nb){
	Coordonnees co;
	if (nb <= 0){
		exit(3);
	}
	// Recherche dans le tableau des robots le robot demandé et récupère ses coordonnées
	co = chercher_Tableau(p.robots, c.robot, nb);
	// Gère le cas du déplacement vers le haut
	if ((dep == 'Z') || (dep == 'z')){
		while (((p.murs[co.i][co.j] != 2) && (p.murs[co.i][co.j] != 5) && (p.murs[co.i][co.j] != 6)) && (p.robots[co.i-1][co.j] == 0)){
			p.robots[co.i-1][co.j] = c.robot;
			p.robots[co.i][co.j] = 0;
            co.i--;
            // Bloque l'affiche pendant 0.2 s (200000 microsecondes)
			usleep(200000);
			effacer();
			afficher_Grille(p, c, nb);
		}
	}
	// Gère le cas du déplacement vers le bas
	else if ((dep == 'S') || (dep == 's')){
		while (((p.murs[co.i][co.j] != 4) && (p.murs[co.i][co.j] != 7) && (p.murs[co.i][co.j] != 8)) && (p.robots[co.i+1][co.j] == 0)){
			p.robots[co.i+1][co.j] = c.robot;
			p.robots[co.i][co.j] = 0;
            co.i++;
			usleep(200000);
			effacer();
			afficher_Grille(p, c, nb);
		}
	}
	// Gère le cas du déplacement vers la droite
	else if ((dep == 'D') || (dep == 'd')){
		while (((p.murs[co.i][co.j] != 3) && (p.murs[co.i][co.j] != 6) && (p.murs[co.i][co.j] != 7)) && (p.robots[co.i][co.j+1] == 0)){
			p.robots[co.i][co.j+1] = c.robot;
			p.robots[co.i][co.j] = 0;
            co.j++;
			usleep(200000);
			effacer();
			afficher_Grille(p, c, nb);
		}
	}
	// Gère le cas du déplacement à gauche
	else if ((dep == 'Q') || (dep == 'q')){
		while (((p.murs[co.i][co.j] != 1) && (p.murs[co.i][co.j] != 5) && (p.murs[co.i][co.j] != 8)) && (p.robots[co.i][co.j-1] == 0)){
			p.robots[co.i][co.j-1] = c.robot;
			p.robots[co.i][co.j] = 0;
            co.j--;
			usleep(200000);
			effacer();
			afficher_Grille(p, c, nb);
		}
	}
	return p.robots;
}


// Génère aléatoirement 4 robots sur le plateau
char** generer_Robots(char** cibles, int nb) {
	char** tab = NULL;
	tab = generer_Tableau(nb);
    int a, b;
	if (tab == NULL){
		exit(1);
	}
	if (nb <= 0){
		exit(3);
	}
    for (int robots = 1; robots <= 4; robots++){
        do {
            a = generer_Nombre(1, nb-2);
            b = generer_Nombre(1, nb-2);
        } while (caseVide(cibles, a, b) != 1);
        tab[a][b] = robots;
    }
    return tab;
}
