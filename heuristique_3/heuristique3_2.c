#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../Programme_Fourni/graphe.h"
#include "../Programme_Fourni/affichage.c"
#include "../Programme_Fourni/lectureFichier.c"
#include "../Programme_Fourni/calculTemps.c"

#include "../Fonction/poids.c"
#include "../Fonction/table.c"
#include "../Fonction/recherche.c"
#include "../Fonction/affichageCombine.c"

#include "Fonction/heuristique3_2.c"

int main(int argc, char const *argv[])
{
      //Variables
      char nom[30];
	Graphe G = NULL;
	int n, m;
	int err;
	clock_t timer;
      //End Variable

      //lecture du fichier
      do{
		printf("Saisir le nom de fichier de donnees : ");
		scanf("%s", nom); 
		while(getchar() != '\n');
		err = lire_data(nom, &G, &n, &m);
	}while(err == 0);

	
	// ordre_ville sert a sauvegarder le chemin optimal
	int *ordre_ville = NULL;
	ordre_ville = malloc(n * sizeof(int));

	// Declenche l'horloge
	timer = clock();

	rechercheCheminVoisinPlusProche(G, n, ordre_ville);
	
	// Affichage resultat
	affichageTimer(timer);
	afficheCheminPoids(G, n, ordre_ville);
	
      return 0;
}