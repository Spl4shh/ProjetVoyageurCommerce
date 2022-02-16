#ifndef AFFICHAGECOMBINE_C
	#define AFFICHAGECOMBINE_C

	#include "../Programme_Fourni/graphe.h"

      // Affichage du chemin en parametre ainsi que son poids total
	void afficheCheminPoids(Graphe G, int n, int ordre_ville[]){
		printf("\nL'ordre de visite est : ");
		for (int i = 0; i < n; i++){
			printf(" -> %d", ordre_ville[i]);
		}
		printf("\nLe distance totale est de %4d km", getPoidsTotal(G, n, ordre_ville));
	}

	// Affiche le temps écoulé depuis le lancement de timer
      void affichageTimer(clock_t timer){
		printf("\nDuree du calcul : %f secondes", getTempsEcoule(timer));
	}

#endif