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

/*
	Cet fonction permet de construire le tableau ordre_ville afin d'avoir le chemin
	construit en fonction du plus proche voisin.
	@param G Graphe des villes et de leurs chemins avec le poids
    	@param n Le nombre de ville dans le graphe
    	@param ordre_ville[] La table contenant l'ordre de visite des villes
*/
void rechercheCheminVoisinPlusProche(Graphe G, int n, int ordre_ville[]);

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

void rechercheCheminVoisinPlusProche(Graphe G, int n, int ordre_ville[]){
	// Variables
	int ville_actuelle, ville_suivante;
	int firstAssign = 1;
	int *liste_ville = NULL, *new_ordre_ville = NULL;

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