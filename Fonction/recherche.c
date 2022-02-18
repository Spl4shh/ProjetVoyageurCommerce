#ifndef RECHERCHE_C
#define RECHERCHE_C

#include <stdio.h>
#include <stdlib.h>
#include "../Programme_Fourni/graphe.h"

/*
      Recherche la ville la plus proche de la ville "num_ville"
      liste_ville[] est un tableau contenant les numeros des villes deja visité en indice, et 1 en valeur de liste_ville[i] si elle a été visité
*/
int rechercheVoisinProche(Graphe g, int n, int num_ville, int liste_ville[]){
	int i;
	int numVoisinProche = -1;

	for(i = 0; i < n; i++)
	{
		// Permet de s'assurer qu'on ne vas pas boucler sur la ville elle meme
		if ( g[num_ville][i] != 0 && liste_ville[i] != 1)
		{
			// Si la ville la plus proche n'a pas été définie 
			// ou que la ville selectionné est plus proche que la ville en mémoire,
			// on modif la valeur
			if (numVoisinProche == -1 || (g[num_ville][i] < g[num_ville][numVoisinProche]) )
			{
				numVoisinProche = i;
			}
		}
	}
	return numVoisinProche;
}

#endif