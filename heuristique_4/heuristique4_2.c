#include <stdio.h>
#include <stdlib.h>

#include "../Programme_Fourni/graphe.h"
#include "../Programme_Fourni/affichage.c"
#include "../Programme_Fourni/lectureFichier.c"
#include "../Fonction/poids.c"
#include "../Fonction/recherche.c"

/*
	Pour l'heuristique 4.2, on reutilise l'heucaristique 3.2 et on créé les fonctions nécéssaires
*/

/* permutter 2 points avec un deplacement afin de (dé)croiser une arrete
   le point a correspond a depart de la premiere arrete et le point b correspond au depart de la deuxieme arrete
*/
void croiserPoint(int point_a, int point_b, int n, int ordre_ville[]);

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

	liste_ville[ville_actuelle] = 1;
	ordre_ville[0] = ville_actuelle;

	printf("ville ou je suis : %d\n", ville_actuelle);
	for(int i = 0; i < n; i++)
	{	
		ville_suivante = rechercheVoisinProche(G, n, ville_actuelle, liste_ville);
		
		//On rentre ici seulement si l'on a pas exploré toutes les villes
		if (ville_suivante != -1)
		{
			ville_actuelle = ville_suivante;
			liste_ville[ville_actuelle] = 1;
			ordre_ville[i+1] = ville_actuelle;;
		}
	}
	
	// Calcul distance totale
	int distance_totale = getPoidsTotal(G, n, ordre_ville);

	// Affichage resultat
	printf("\nL'ordre de visite est : ");
	for (int i = 0; i < n; i++)
	{
		printf(" -> %d", ordre_ville[i]);
	}
	printf("\nLe distance totale est de %4d km", distance_totale);
	
      return 0;
}

void croiserPoint(int point_a, int point_b, int n, int ordre_ville[]){
	int tempo;

	tempo = ordre_ville[point_a + 1];
	ordre_ville[point_a + 1] = ordre_ville[point_b + 1];
}