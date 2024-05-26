#include "fonctions.h"
#include "affichage.h"
#include "menu.h"
#include "robots.h"
#include "cible.h"
#include "murs.h"

int main(){
	srand(time(NULL));
	Plateau p;
	Points_joueurs pts;
	Choix c;
	Choix_Joueur cj;
	Coordonnees co_robot;
	Coordonnees co_cible;
	char lettres[18] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R'};
	char nb = generer_Nombre(15, 20); // Nombre de case du plateau de jeu
	char dep; // Déplacement des robots
	int nb_joueurs; // Nombre de joueurs
	int nb_manche; // Nombre de manches de la partie
	int temps; // temps de réflexion (en rapport avec la difficulté choisie)
	pts.p1 = 0;
	pts.p2 = 0;
	pts.p3 = 0;
	pts.p4 = 0;
	p.cibles = generer_Tableau(nb);
	p.murs = generer_Tableau(nb);
	p.robots = generer_Tableau(nb);
	effacer();
	printf("\n");
	nb_joueurs = qst_nbJoueurs();
	nb_manche = qst_nbManches();
	temps = qst_difficulte();
	p.cibles = generer_Cibles(nb);
	p.murs = generer_Murs(p.cibles, nb);
	p.robots = generer_Robots(p.cibles, nb);
	effacer();
	// Boucle pour chaque manche
	for (int i = 1; i <= nb_manche; i++){
		c.robot = generer_Nombre(1, 4); // Choix d'un robot
		c.cible = generer_Nombre(0, 17); // Choix d'une cible
		co_cible = chercher_Tableau(p.cibles, c.cible+1, nb); // Récupère les coordonnées de la cible tirée au sort
		affichage_Jeu(p, pts, c, i, nb, nb_joueurs);
		printf("\n\n");
		printf(ESPACE);
		printf("Le robot choisi est le %d. La cible choisie est %c\n", c.robot, lettres[c.cible]);
		compteARebours(75-temps*15);
		effacer();
		cj = choix_Joueur(cj, nb_joueurs);
		if (cj.j == 0){
			printf("\n\n");
			printf(ESPACE);
			printf("Tous les joueurs déclarent forfait. La manche va donc être rejouée\n");
			sleep(3);
			i--;
		}
		else {
			effacer();
			// Séquence de jeu d'un des joueurs
			for (int j = 1; j <= cj.mvt; j++){
				affichage_Jeu(p, pts, c, i, nb, nb_joueurs);
				printf("\n\n");
				printf(ESPACE);
				printf("Le robot choisi est le %d. La cible choisie est %c\n", c.robot, lettres[c.cible]);
				printf(ESPACE);
				printf("Joueur choisi : %d\n", cj.j);
				dep = qst_depRobots(j);
				dep_Robots(p, c, dep, nb);
				co_robot = chercher_Tableau(p.robots, c.robot, nb);
				if ((co_cible.i == co_robot.i) && (co_cible.j == co_robot.j)){
					effacer();
					printf("\n\n\n\n\n\n\n\n\n\n\n");
					printf(ESPACE);
					if (j == cj.mvt){
						printf("Manche gagnée ! Le joueur #%d gagne 2 point !\n", cj.j);
						if (cj.j == 1){
							pts.p1 += 2;
						}
						if (cj.j == 2){
							pts.p2 += 2;
						}
						if (cj.j == 3){
							pts.p3 += 2;
						}
						if (cj.j == 4){
							pts.p4 += 2;
						}
					}
					else if (j < cj.mvt){
						printf("Le joueur #%d a effectué moins de déplacements qu'annoncé. Il perd donc 1 point !\n", cj.j);
						if (cj.j == 1){
							pts.p1--;
						}
						if (cj.j == 2){
							pts.p2--;
						}
						if (cj.j == 3){
							pts.p3--;
						}
						if (cj.j == 4){
							pts.p4--;
						}
					}
					break;
				}
			}
			if ((co_cible.i != co_robot.i) || (co_cible.j != co_robot.j)) {
				effacer();
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				printf(ESPACE);
				printf("Manche perdue ! Tous les joueurs sauf #%d gagnent 1 point !\n", cj.j);
				if (cj.j == 1){
					pts.p2++;
					pts.p3++;
					pts.p4++;
				}
				if (cj.j == 2){
					pts.p1++;
					pts.p3++;
					pts.p4++;
				}
				if (cj.j == 3){
					pts.p1++;
					pts.p2++;
					pts.p4++;
				}
				if (cj.j == 4){
					pts.p1++;
					pts.p2++;
					pts.p3++;
				}
			}
			affichagePointsJoueurs(pts, nb_joueurs);
			sleep(3);
			if (i != nb_manche){
				printf("\n");
				printf(ESPACE);
				printf("Prochaine manche dans 5s !\n");
				sleep(5);
			}
		}
	}
	affichageGagnant(pts, nb_joueurs);
	free(p.cibles);
	free(p.murs);
	free(p.robots);
	return 0;
}
