#ifndef AFFICHAGE_C
#define AFFICHAGE_C

#include "graphe.h"

void affiche_km(Graphe g, int n)
{
	int i, j;
	
	int ville_choisie = 5;

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++) {
			printf("%5d ", g[i][j]);
		}
		printf("\n");
	}		
	printf("\n");
}

void affiche_une_ville(Graphe g, int n, int num_ville)
{
	int i;
	
	for(i = 0; i < n; i++)
	{
		printf("%5d ", g[num_ville][i]);
	}
	printf("\n");
}

#endif