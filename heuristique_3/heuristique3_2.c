#include <stdio.h>
#include <stdlib.h>

#include "../Programme_Fourni/graphe.h"
#include "../Programme_Fourni/affichage.c"
#include "../Programme_Fourni/lectureFichier.c"

// recherche la ville la plus proche de la ville "num_ville"
int recherche_voisin_proche(Graphe g, int n, int num_ville, int liste_ville[]);

// calcul du poids total d'un chemin en fcontion d'un graphe, du nb de sommet et de l'ordre des sommets traversé
int calcul_poids_total(Graphe g, int n, int ordre_ville[]);

int main(int argc, char const *argv[])
{
      //Variables
      char nom[30];
	Graphe G = NULL;
	int n, m;
	int err;
	int ville_actuelle = 0, ville_suivante;
      //End Variable

      //lecture du fichier
      do{
		printf("saisir le nom de fichier de donnees : ");
		scanf("%s", nom); 
		while(getchar() != '\n');
		err = lire_data(nom, &G, &n, &m);
	}while(err == 0);

	/*
	Liste_ville sert a verifier les villes dans lesquelles on est deja passé
	ordre_ville sert a sauvegarder l'ordre dans lequel on est passé
	*/
	int *liste_ville = NULL, *ordre_ville = NULL;
	

	liste_ville = malloc(n * sizeof(int));
	ordre_ville = malloc(n * sizeof(int));
	printf("Here");

	liste_ville[ville_actuelle] = 1;
	ordre_ville[0] = ville_actuelle;

	printf("ville ou je suis : %d\n", ville_actuelle);
	for(int i = 0; i < n; i++)
	{	
		ville_suivante = recherche_voisin_proche(G, n, ville_actuelle, liste_ville);
		
		//On rentre ici seulement si l'on a pas exploré toutes les villes
		if (ville_suivante != -1)
		{
			ville_actuelle = ville_suivante;
			liste_ville[ville_actuelle] = 1;
			ordre_ville[i+1] = ville_actuelle;;
			printf("ville ou je suis : %d\n", ville_actuelle);
		}
	}
	
	// Calcul distance totale
	int distance_totale = calcul_poids_total(G, n, ordre_ville);

	// Affichage resultat
	printf("\nL'ordre de visite est : ");
	for (int i = 0; i < n; i++)
	{
		printf(" -> %d", ordre_ville[i]);
	}
	printf("\nLe distance totale est de %4d km", distance_totale);
	
      return 0;
}

int recherche_voisin_proche(Graphe g, int n, int num_ville, int liste_ville[]){
	int i;
	int num_voisin_proche = -1;

	for(i = 0; i < n; i++)
	{
		// Permet de s'assurer qu'on ne vas pas boucler sur la ville elle meme
		if (g[num_ville][i] != 0 && liste_ville[i] != 1)
		{
			// Si la ville la plus proche n'a pas été définie 
			// ou que la ville selectionné est plus proche que la ville en mémoire,
			// on modif la valeur
			if (num_voisin_proche == -1 || (g[num_ville][i] < g[num_ville][num_voisin_proche]) )
			{
				num_voisin_proche = i;
			}
		}
	}
	return num_voisin_proche;
}

int calcul_poids_total(Graphe g, int n, int ordre_ville[]){
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