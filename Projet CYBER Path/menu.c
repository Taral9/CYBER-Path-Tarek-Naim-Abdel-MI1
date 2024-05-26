#include "fonctions.h"
#include "affichage.h"

// Toutes les fonctions qu'il y a à faire dans ce fichier :
// Question nombre joueur
int qst_nbJoueurs(){
    int nb_joueurs;
    int s;
    printf(ESPACE);
    printf("Entrez le nombre de joueurs (2-4) : ");
    s = scanf("%d", &nb_joueurs);
    while (nb_joueurs < 2 || nb_joueurs > 4 || s != 1) {
        effacer_ligne();
        printf(ESPACE);
        printf("Entrez le nombre de joueurs (2-4) : ");
        videScanf();
        s = scanf("%d", &nb_joueurs);
    }
    return nb_joueurs;
}



// Question nombre de manches à jouer
int qst_nbManches(){
    int nb_manche;
    int s;
    printf(ESPACE);
    printf("Quel sera le nombre de manches (<10) ? : ");
    videScanf();
    s = scanf("%d", &nb_manche);
    while (s != 1 || nb_manche < 1 || nb_manche > 10){
        effacer_ligne();
        printf(ESPACE);
        printf("Quel sera le nombre de manches (<10) ? : ");
        videScanf();
        s = scanf("%d", &nb_manche);
    }
    return nb_manche;
}

// Question déplacement robots
char qst_depRobots(int n){
	char dep_Robots;
    int s;
    printf(ESPACE);
    if (n == 1){
    	printf("Entrer le 1er déplacement : ");
    }
    else{
    	printf("Entrer le %dème déplacement : ", n);
    }
    videScanf();
    s = scanf("%c", &dep_Robots);
    while (s != 1 || (dep_Robots != 'Z' && dep_Robots != 'z'
        && dep_Robots != 'S' && dep_Robots != 's'
        && dep_Robots != 'Q' && dep_Robots != 'q'
        && dep_Robots != 'D' && dep_Robots != 'd')){
    	effacer_ligne();
    	if (s != 1){
		    printf(ESPACE);
		    printf("Entrée incorrecte. Réessayez : ");
		    videScanf();
		    s = scanf("%c", &dep_Robots);
		}
		else if (dep_Robots != 'Z' || dep_Robots != 'z'
    		|| dep_Robots != 'S' || dep_Robots != 's'
            || dep_Robots != 'Q' || dep_Robots != 'q'
    		|| dep_Robots != 'D' || dep_Robots != 'd'){
    		printf(ESPACE);
		    printf("Les caractères acceptés sont ZQSD. Réessayez : ");
            videScanf();
		    s = scanf("%c", &dep_Robots);
    	}
    }
    return dep_Robots;
}

// Choix du joueur
Choix_Joueur choix_Joueur(Choix_Joueur cj, int joueurs){
    cj.j = 0;
    int s = 0; // Test scanf
    int d[4] = {0}; // Nombre de mouvement de chaque joueur
    int a = 0; // Nombre de joueurs à égalité
    int ch[4]; // Tableau pour les éventuels égalités
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf(ESPACE);
    printf("Chaque joueur doit maintenant entrer le nombre de déplacements qu'il pense pouvoir faire pour atteindre la cible. Le joueur en proposant le moins sera sélectionné.\n");
    printf(ESPACE);
    printf("En cas d'égalité, un tirage au sort sera fait.\n");
    printf("\n");
    printf(ESPACE);
    printf("Si un joueur réussit à atteindre la cible dans le nombre de mouvements indiqué, il recevra 2 point. Sinon, ce sera tous les autres joueurs qui recevront 1 point\n");
    printf(ESPACE);
    couleur("31");
    printf("Attention : Si un joueur atteint la cible en faisant moins de mouvement qu'indiqué, il perd 1 point. Réfléchissez bien !\n");
    couleur("0");
    printf("\n");
    printf(ESPACE);
    printf("Les joueurs peuvent également entrer 0. Cela signifie qu'ils passent leur tour car ils considèrent que la grille est infaisable\n");
    printf(ESPACE);
    printf("Si tous les joueurs passent leur tour, la manche n'est pas comptée et une nouvelle grille est proposée.\n");
    printf("\n");
    // Chaque joueur entre son nombre de déplacements
    for (int i = 1; i <= joueurs; i++){
        printf(ESPACE);
        if (i == 1){
            printf("Joueur #%d : ", i);
            videScanf();
            s = scanf("%d", d);
            while (s != 1 || d[0] < 0){
                effacer_ligne();
                printf(ESPACE);
                printf("Joueur #%d : ", i);
                videScanf();
                s = scanf("%d", d);
            }
        }
        if (i == 2){
            printf("Joueur #%d : ", i);
            videScanf();
            s = scanf("%d", &d[1]);
            while (s != 1 || d[1] < 0){
                effacer_ligne();
                printf(ESPACE);
                printf("Joueur #%d : ", i);
                videScanf();
                s = scanf("%d", &d[1]);
            }
        }
        if (i == 3){
            printf("Joueur #%d : ", i);
            videScanf();
            s = scanf("%d", &d[2]);
            while (s != 1 || d[2] < 0){
                effacer_ligne();
                printf(ESPACE);
                printf("Joueur #%d : ", i);
                videScanf();
                s = scanf("%d", &d[2]);
            }
        }
        if (i == 4){
            printf("Joueur #%d : ", i);
            videScanf();
            s = scanf("%d", &d[3]);
            while (s != 1 || d[3] < 0){
                effacer_ligne();
                printf(ESPACE);
                printf("Joueur #%d : ", i);
                videScanf();
                s = scanf("%d", &d[3]);
            }
        }
    }
    printf("\n");
    cj.mvt = 0;
    // Vérification du plus petit nombre de mouvements
    for (int i = 0; i < joueurs; i++){
        if (cj.mvt > 0){
            if (d[i] < cj.mvt && d[i] > 0){
                cj.j = i+1;
                cj.mvt = d[i];
                a = 1;
                ch[a-1] = i+1;
            }
            else if (d[i] == cj.mvt && d[i] > 0){
                a++;
                ch[a-1] = i+1;
            }
        }
        else if (d[i] > 0 && cj.mvt == 0){
            cj.j = i+1;
            cj.mvt = d[i];
            a = 1;
            ch[a-1] = i+1;
        }
    }
	srand(time(NULL));
    if (a > 1){
        cj.j = ch[generer_Nombre(0, a-1)];
    }
    return cj;
}

// Compte à rebours pour effacer la grille
void compteARebours(int t){
	printf(ESPACE);
	printf("Veuillez ne rien taper dans la console avant la fin du chronomètre\n");
    while (t >= 0){
        printf(ESPACE);
        if (t < 10){
            couleur("33"); // Couleur jaune
        }
        if (t < 5){
            couleur("31"); // Couleur rouge
        }
        printf("Vous avez %d secondes pour regarder la grille et décider du nombre de mouvements.\n", t);
        couleur("0");
        sleep(1);
        t--;
        effacer_ligne();
    }
	videScanf();
}

// Demande difficulté du jeu (Facile/Moyen/Difficile)
int qst_difficulte(){
    int s;
    int t;
    printf(ESPACE);
    printf("Niveau de difficulté (1 : Facile | 2 : Moyen | 3 : Difficile) : ");
    videScanf();
    s = scanf("%d", &t);
    while (s != 1 || t < 1 || t > 3){
        effacer_ligne();
        printf(ESPACE);
        printf("Entrée incorrecte. Réessayez (1-3) : ");
        videScanf();
        s = scanf("%d", &t);
    }
    return t;

}

void affichageGagnant(Points_joueurs pts, int joueurs){
    printf("\n\n\n");
	printf(ESPACE);
	printf(ESPACE);
	printf(ESPACE);
	printf(ESPACE);
	if (joueurs == 2){
		if (pts.p1 < pts.p2){
			printf("Gagnant : Joueur #2 !\n");
		}
		else if (pts.p1 > pts.p2){
			printf("Gagnant : Joueur #1 !\n");
		}
		else if (pts.p1 == pts.p2){
			printf("Match nul !\n");
		}
	}
	if (joueurs == 3){
		if (pts.p1 < pts.p2 && pts.p2 > pts.p3){
			printf("Gagnant : Joueur #2 !\n");
		}
		else if (pts.p1 > pts.p2 && pts.p1 > pts.p3){
			printf("Gagnant : Joueur #1 !\n");
		}
		else if (pts.p1 < pts.p3 && pts.p2 < pts.p3){
			printf("Gagnant : Joueur #3 !\n");
		}
		else if (pts.p1 == pts.p2 && pts.p1 > pts.p3){
			printf("Joueur #1 et Joueur #2 : Ex aequo !\n");
		}
		else if (pts.p2 == pts.p3 && pts.p3 > pts.p1){
			printf("Joueur #2 et Joueur #3 : Ex aequo !\n");
		}
		else if (pts.p1 == pts.p3 && pts.p3 > pts.p2){
			printf("Joueur #1 et Joueur #3 : Ex aequo !\n");
		}
		else if (pts.p1 == pts.p2 && pts.p2 == pts.p3){
			printf("Match nul !\n");
		}
	}
	if (joueurs == 4){
		if (pts.p1 < pts.p2 && pts.p2 > pts.p3 && pts.p2 > pts.p4){
			printf("Gagnant : Joueur #2 !\n");
		}
		else if (pts.p1 > pts.p2 && pts.p3 < pts.p1 && pts.p1 > pts.p4){
			printf("Gagnant : Joueur #1 !\n");
		}
		else if (pts.p3 > pts.p2 && pts.p1 < pts.p3 && pts.p3 > pts.p4){
			printf("Gagnant : Joueur #3 !\n");
		}
		else if (pts.p4 > pts.p2 && pts.p3 < pts.p4 && pts.p4 > pts.p1){
			printf("Gagnant : Joueur #4 !\n");
		}
		else if (pts.p2 == pts.p3 && pts.p3 > pts.p1 && pts.p3 > pts.p4){
            printf("Joueur #2 et Joueur #3 : Ex aequo !\n");
        }
        else if (pts.p1 == pts.p4 && pts.p1 > pts.p3 && pts.p1 > pts.p2){
            printf("Joueur #1 et Joueur #4 : Ex aequo !\n");
        }
        else if (pts.p1 == pts.p2 && pts.p2 > pts.p3 && pts.p2 > pts.p4){
            printf("Joueur #1 et Joueur #2 : Ex aequo !\n");
        }
        else if (pts.p1 == pts.p3 && pts.p1 > pts.p2 && pts.p1 > pts.p4){
            printf("Joueur #1 et Joueur #3 : Ex aequo !\n");
        }
        else if (pts.p2 == pts.p4 && pts.p2 > pts.p3 && pts.p2 > pts.p1){
            printf("Joueur #2 et Joueur #4 : Ex aequo !\n");
        }
        else if (pts.p3 == pts.p4 && pts.p3 > pts.p2 && pts.p3 > pts.p1){
            printf("Joueur #3 et Joueur #4 : Ex aequo !\n");
        }
        else if (pts.p1 == pts.p2 && pts.p2 == pts.p3 && pts.p3 > pts.p4){
            printf("Joueur #1 ; Joueur #2 ; Joueur #3 : Ex aequo !\n");
        }
        else if (pts.p1 == pts.p2 && pts.p2 == pts.p4 && pts.p3 < pts.p4){
            printf("Joueur #1 ; Joueur #2 ; Joueur #4 : Ex aequo !\n");
        }
        else if (pts.p1 == pts.p3 && pts.p3 == pts.p4 && pts.p2 < pts.p4){
            printf("Joueur #1 ; Joueur #3 ; Joueur #4 : Ex aequo !\n");
        }
        else if (pts.p3 == pts.p2 && pts.p2 == pts.p4 && pts.p3 > pts.p1){
            printf("Joueur #2 ; Joueur #3 ; Joueur #4 : Ex aequo !\n");
        }
        else if (pts.p1 == pts.p2 && pts.p2 == pts.p3 && pts.p3 == pts.p4){
            printf("Match nul !\n");
        }
    }
	printf("\n\n\n");
}

void affichagePointsJoueurs(Points_joueurs pts, int joueurs){
    printf(ESPACE);
    printf(ESPACE);
    if (joueurs == 2){
        printf(ESPACE);
        printf(ESPACE);
        printf("Joueur #1 = %d pts  |  Joueur #2 = %d pts  ", pts.p1, pts.p2);
    }
    if (joueurs == 3){
        printf(ESPACE);
        printf("Joueur #1 = %d pts  |  Joueur #2 = %d pts  |  Joueur #3 = %d pts  ", pts.p1, pts.p2, pts.p3);
    }
    if (joueurs == 4){
        printf("Joueur #1 = %d pts  |  Joueur #2 = %d pts  |  Joueur #3 = %d pts  |  Joueur #4 = %d pts  ", pts.p1, pts.p2, pts.p3, pts.p4);
    }
    printf("\n");
}

// Gère l'affichage global du jeu
void affichage_Jeu(Plateau p, Points_joueurs pts, Choix c, int manche, int nb, int joueurs){
    effacer();
    printf(ESPACE);
    printf(ESPACE);
    printf(ESPACE);
    printf(ESPACE);
    printf(ESPACE);
    if (nb > 17){
        printf(ESPACE);
    }
    printf("Manche #%d\n", manche);
    printf("\n");
    if (nb > 17){
        printf(ESPACE);
    }
    affichagePointsJoueurs(pts, joueurs);
    afficher_Grille(p, c, nb);
}
