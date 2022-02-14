#ifndef POIDS_C
#define POIDS_C

#include <stdio.h>
#include <stdlib.h>
#include "../Programme_Fourni/graphe.h"

int get_poids_total(Graphe g, int n, int ordre_ville[]){
	int somme_poids = 0;
	int point_a, point_b;

	for (int i = 0; i < n-1; i++)
	{
		point_a = ordre_ville[i];
		point_b = ordre_ville[i+1];
				
		somme_poids += g[point_a][point_b];
		
		/* Debug
		printf("\nPoint a : %d, Point b : %d", point_a, point_b);
		printf("\nPoids actuel : %d", somme_poids);
		*/
	}

	return somme_poids;
}

#endif