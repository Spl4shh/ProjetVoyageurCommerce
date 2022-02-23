#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "../Programme_Fourni/graphe.h"
#include "../Programme_Fourni/affichage.c"
#include "../Programme_Fourni/lectureFichier.c"
#include "../Programme_Fourni/calculTemps.c"

#include "../Fonction/poids.c"
#include "../Fonction/table.c"
#include "../Fonction/recherche.c"
#include "../Fonction/randomNumber.c"
#include "../Fonction/departPoint.c"
#include "../Fonction/affichageCombine.c"

#include "../heuristique_3/Fonction/heuristique3_1.c"
#include "../heuristique_3/Fonction/heuristique3_2.c"
#include "../heuristique_3/Fonction/heuristique3_3_1.c"
#include "../heuristique_3/Fonction/heuristique3_3_2.c"

#include "Fonction/heuristique4_1.c"

#define TIMER_LIMIT 5

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
	int *liste_ville = NULL, *ordre_ville = NULL;

	liste_ville = malloc(n * sizeof(int));
	ordre_ville = malloc(n * sizeof(int));

	liste_ville[ville_actuelle] = 1;
	ordre_ville[0] = ville_actuelle;

	//Declenche l'horloge
	timer = clock();

	// Decommenter la version que l'on veux tester
	//rechercheCheminVoisinPlusProche(G, n, ordre_ville);
	//meilleurCheminRandom(G, n, ordre_ville, timer);
	//rechercheCheminInsertion(G, n, ordre_ville, timer);
	assemblageAvantageux(G, n, ordre_ville);

	demarrerPoint(ordre_ville, n, 0);

	// Affichage l'ordre selon le voisin le plus proche
	printf("\nAvec la recherche de base :");	
	afficheCheminPoids(G, n, ordre_ville);

	//Fait des recherches pendant TIMER_LIMIT secondes
	rechercheParcoursPermutation(G, n, ordre_ville, timer, TIMER_LIMIT);

	// Affichage resultat apres permutation
	printf("\n\nAvec des permutations aleatoire :");	
	affichageTimer(timer);
	afficheCheminPoids(G, n, ordre_ville);

      return 0;
}