#ifndef HEURISTIQUE3_3_2_C
	#define HEURISTIQUE3_3_2_C

	#include "heuristique3_3_2.h"

	//Peut etre essayer d'eneleer table_insertion
	void assemblageAvantageux(Graphe G, int n, int ordre_ville[]){
		int *liste_ville = NULL;
		liste_ville = malloc(n * sizeof(int));
		liste_ville[ordre_ville[0]] = 1;	// On se fixe a 0 comme pooint de depart pour 

		// Ici i correspondra à la valeur que l'on affecteras, on va donc devoir travailler avec i+1 quand on parlera de taille d'element
		for (int i = 0; i < n; i++)
		{
			int firstTest = 1;

			// Asssigne l'espace de maniere dynamique afin de pouvoir faire varier la taille des tableaux 
			int * table_insertion = NULL;
			table_insertion = malloc((i+1) * sizeof(int));
			int * table_test = NULL;
			table_test = malloc((i+1) * sizeof(int));

			copieTable(table_insertion, ordre_ville, i+1);

			if (liste_ville[i] != 1){ // Si l'on a pas encore traité la ville
				for (int j = 1; j < i+1; j++){
				copieTable(table_test, ordre_ville, i+1);

				// Decalage dse 1 vers la droite jusqu'a la place de l'element a ajouter (J)
				for (int k = i; k > j /*Position de la valeur*/; k--){
					table_test[k] = table_test[k-1];
				}
				table_test[j] = i;
				
				if (firstTest){
					copieTable(table_insertion, table_test, i+1);                  
					firstTest = 0; 
				}else{
					if (getPoidsTotal(G, i, table_insertion) > getPoidsTotal(G, i, table_test)){
						copieTable(table_insertion, table_test, i+1);
					}  
				}
				}    
			}
			copieTable(ordre_ville, table_insertion, i+1); 

			//Libere l'espace assigné une fois la valeur de ce passage sauvegarder
			free(table_insertion);
			free(table_test);
		} 
	}
#endif