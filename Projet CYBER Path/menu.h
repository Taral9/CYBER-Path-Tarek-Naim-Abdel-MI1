int qst_nbJoueurs();

int qst_nbManches();

char qst_depRobots(int n);

Choix_Joueur choix_Joueur(Choix_Joueur cj, int joueurs);

void compteARebours(int t);

int qst_difficulte();

void affichageGagnant(Points_joueurs pts, int joueurs);

void affichagePointsJoueurs(Points_joueurs pts, int joueurs);

void affichage_Jeu(Plateau p, Points_joueurs pts, Choix c, int manche, int nb, int joueurs);
