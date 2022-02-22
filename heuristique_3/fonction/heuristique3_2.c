#ifndef HEURISTIQUE3_2_C
	#define HEURISTIQUE3_2_C

	#include "../../Programme_Fourni/graphe.h"
	#include <stdio.h>

	void rechercheCheminVoisinPlusProche(Graphe G, int n, int ordre_ville[]){
		// Variables
		int ville_actuelle, ville_suivante;
		int firstAssign = 1;

		int *liste_ville = NULL, *new_ordre_ville = NULL;
		// END Variables

		for (int i = 0; i < n; i++){
			
			liste_ville = malloc(n * sizeof(int));
			new_ordre_ville = malloc(n * sizeof(int));

			// Initialise le tableau de la liste des villes visitée
			for (int h = 0; h < n; h++){
				liste_ville[h] = 0;
			}
			
			ville_actuelle = i;
			liste_ville[ville_actuelle] = 1;
			new_ordre_ville[0] = ville_actuelle;

			/*
				Construit pour le sommet de depart actuel 
				le chemin a partir des plus proche voisin
			*/
			for(int j = 0; j < n; j++){	
				ville_suivante = rechercheVoisinProche(G, n, ville_actuelle, liste_ville);

				//On rentre ici seulement si l'on a pas exploré toutes les villes
				if (ville_suivante != -1){
					ville_actuelle = ville_suivante;
					liste_ville[ville_actuelle] = 1;
					new_ordre_ville[j+1] = ville_actuelle;;
				}
			}

			/*
				Assigne l'ordre de ville testé si c'est le premier test
				Ou si le poids du nouveau chemin est plus faible que l'ancien
			*/
			if (!firstAssign){
				if (getPoidsTotal(G, n, ordre_ville) > getPoidsTotal(G, n, new_ordre_ville)){
					copieTable(ordre_ville, new_ordre_ville, n);
				}
			}else{
				copieTable(ordre_ville, new_ordre_ville, n);
				firstAssign = 0;
			}

			// Libere l'espace (et donc le contenu) alloué aux tableaux
			free(liste_ville);
			free(new_ordre_ville);
		}
	}

#endif