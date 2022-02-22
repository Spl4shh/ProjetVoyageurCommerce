#ifndef HEURISTIQUE3_3_1_C
	#define HEURISTIQUE3_3_1_C

	#include "../../Programme_Fourni/graphe.h"
	#include <stdio.h>
	#include <time.h>

	#include "heuristique3_3_1.h"
	#include "../../Fonction/table.c"
	#include "../../Fonction/poids.c"

      // Décale les élément d'une table vers la gauche
	void decalageVersGauche(int *table, int n){
		int save = table[0];  // On stock la donnée qui va être écrasée dans une variable
		for(int i = 0; i < n; i++){
			table[i] = table[i+1];
		}
		table[n-1] = save;  // On ressort la donnée precedemment écrasée
	}

      // Insert un élément qui viens de la droite de la table
	void insererElementDroite(int decalage, int rangDep, int *liste){
		for (int i = rangDep; i > (rangDep - decalage); i--){
			decalageVersGauche(&liste[i], 2);   // On cherche à inverser la positon de 2 éléments de la partie de la table
		}
	}
	
	// Cherche un chemin rapide en inserant de nouvelle ville une par une, en vérifiant quelle insertion est la plus rapide
	void cheminParInsertion(Graphe g, int n, int ordre_ville[]){
		int chemin_test[n];
		copieTable(chemin_test, ordre_ville, n);   // Initilisation de la table de test

		for(int checked = 2; checked < n-1; checked++){     // Pour chaque ville ajoutée
			for(int j = 0; j < checked; j++){               // Pour chaque position de ville testée
				insererElementDroite(1, checked-j, chemin_test);

				if(getPoidsTotal(g, checked, chemin_test) < getPoidsTotal(g, checked, ordre_ville)){
					copieTable(ordre_ville, chemin_test, n);    // On sauvegarde la meilleure performance
				}
			}
		}
	}

      // Appel cheminParInsertion en boucle pendant Timer_Limit avec des listes différentes, variant aléatoirement
	void rechercheCheminInsertion(Graphe g, int n, int ordre_ville[], clock_t timer, int Timer_Limit){
		int chemin_test[n];
		for (int i = 0; i < n; i++){
			ordre_ville[i] = i;
		}

		copieTable(chemin_test, ordre_ville, n);    // Initilisation de la table de test
		
		while (getTempsEcoule(timer) < Timer_Limit){    
			cheminParInsertion(g, n, chemin_test);  // Création du résultat de la seed (= trie de la table donnée aléarement)

			if(getPoidsTotal(g, n, ordre_ville) > (getPoidsTotal(g, n, chemin_test))){
				copieTable(ordre_ville, chemin_test, n);    // On sauvegarde la meilleure perf
			} 
			permut_complete(chemin_test, n);    // Nouvelle seed
		}
	}

#endif