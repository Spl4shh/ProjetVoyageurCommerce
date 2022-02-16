#ifndef AFFICHAGE_C
#define AFFICHAGE_C

#include "../Programme_Fourni/graphe.h"

void afficheCheminPoids(Graphe G, int n, int ordre_ville[]){
	printf("\nL'ordre de visite est : ");
	for (int i = 0; i < n; i++){
		printf(" -> %d", ordre_ville[i]);
	}
	printf("\nLe distance totale est de %4d km", getPoidsTotal(G, n, ordre_ville));
}

#endif