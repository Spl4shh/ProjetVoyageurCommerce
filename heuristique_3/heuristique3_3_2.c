#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../Programme_Fourni/graphe.h"
#include "../Programme_Fourni/affichage.c"
#include "../Programme_Fourni/lectureFichier.c"
#include "../Programme_Fourni/permutation.c"
#include "../Programme_Fourni/calculTemps.c"

#include "../Fonction/recherche.c"
#include "../Fonction/affichageCombine.c"
#include "../Fonction/table.c"
#include "../Fonction/poids.c"

#include "Fonction/heuristique3_3_2.h"

#define TIMER_LIMIT 5.0

int main(int argc, char const *argv[])
{
    //Variables
    char nom[30];
	Graphe G = NULL;
	int n, m;
	int err;
	int ville_actuelle = 0, ville_suivante;
	clock_t timer;
	srand((unsigned int)time(NULL));
    //End Variable

    //lecture du fichier
    do{
		printf("Saisir le nom de fichier de donnees : ");
		scanf("%s", nom); 
		while(getchar() != '\n');
		err = lire_data(nom, &G, &n, &m);
	}while(err == 0);

	/*
	Liste_ville sert a verifier les villes dans lesquelles on est deja passé
	ordre_ville sert a sauvegarder l'ordre dans lequel on est passé
	*/
	int *ordre_ville = NULL;
	ordre_ville = malloc(n * sizeof(int));
	ordre_ville[0] = ville_actuelle;

	// Declenche l'horloge
	timer = clock();

    assemblageAvantageux(G, n, ordre_ville);

    // Affichage
    affichageTimer(timer);
    afficheCheminPoids(G, n, ordre_ville);
    return 0;
}