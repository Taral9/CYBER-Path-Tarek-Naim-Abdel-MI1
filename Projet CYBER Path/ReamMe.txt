							Bienvenue sur le jeu CYBER Path.

Ceci est un jeu de réflexion ayant pour but déplacer des robots vers des cibles sur un labyrinthe.
Pour chaque manche du jeu, une cible et un robot sont désignées aléatoirement et le but pour chaque joueur est de trouver comment y accéder en le moins de mouvements possibles.
Le jeu se joue à 4 maximum en local. Chaque joueur possède un nombre de points visibles et ce sera celui qui en aura le plus à la fin qui gagnera.

Déroulement du jeu :
	D'abord, le jeu vous demande le nombre de joueurs que vous êtes, le nombre de manches à disputer et enfin le niveau de dificulté souhaité.
	La difficulté paramètre le chronomètre de la réflexion sur la grille (60 secondes en mode facile, 45 en mode moyen et 30 en mode difficile)
	Une fois répondu à ces questions, le jeu affiche une grille, indiquele robot et la cible choisis et lance le chrono (en fonction du niveau de difficulté). C'est à ce moment_là qu'il faut réfléchir au nombre de mouvements nécessaires au robot pour rejoindre la cible.
	Quand le chronomètre arrive à 0, la grille est cachée et il est demandé à chaque joueur d'entrer le nombre de déplacements qu'il pense avoir besoin pour atteindre la cible
	Attention, si vous entrez un nombre important et que vous parvenez à atteindre la cible avec moins de mouvements, vous perdez 1 point. Il faut donc bien réfléchir.
	Si vous ne voyez pas comment ateindre la cible, vous pouvez également entrer '0' pour abandonner la manche. Ainsi vous ne prenez pas de risque d'être pioché et de perdre des points bêtement.
	Si tous les joueurs passent leur tour, la manche est invalidée et on recommence.
	Si plusieurs joueurs ont le même nombre de mouvements, un tirage est effectué.
	Le joueur qui réussit parfaitement à atteindre la cible dans le nombre de mouvements fixé gagne 2 points, sinon 1 point est distribué à tous les autres joueurs.

Ce schéma se répète jusqu'à la fin du nombre de manche fixé. Le gagant est alors celui qui a accumué le plus de points jusque là.

Pour lancer le programme :
	1/ Ouvrir le terminal Linux dans le dossier du jeu
	2/ Taper 'make' dans la console pour compiler les fichiers
	3/ Executer le jeu en tapant './exe' dans la console

Vous pouvez supprimer les fichiers compilés une fois que vous avez fini de jouer en tapant 'make clean'.
