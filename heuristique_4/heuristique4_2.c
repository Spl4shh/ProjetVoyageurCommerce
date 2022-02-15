#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../Programme_Fourni/graphe.h"
#include "../Programme_Fourni/affichage.c"
#include "../Programme_Fourni/calculTemps.c"
#include "../Programme_Fourni/lectureFichier.c"
#include "../Fonction/poids.c"
#include "../Fonction/recherche.c"

#define TIMER_LIMIT 1.0
/*
	Pour l'heuristique 4.2, on reutilise l'heucaristique 3.2 et on créé les fonctions nécéssaires
*/

/* Permutter 2 points avec un deplacement afin de (dé)croiser une arrete
   Le point a correspond a depart de la premiere arrete et le point b correspond au depart de la deuxieme arrete
   Conditions : 
	point_a >= 0 
	point_a < n-1
	point_b < n-1
	point_a < point_b
	point_b - point_a > 1
   Avec n la taille du tableau
*/
int* croiserPoint(int point_a, int point_b, int n, int ordre_ville[]);

// Permet de copier un tableau d'entier
void copieTableau(int** tab1, int* tab2, int taille);

int main(int argc, char const *argv[])
{
      //Variables
      char nom[30];
	Graphe G = NULL;
	int n, m;
	int err;
	int ville_actuelle = 0, ville_suivante;
	clock_t timer;
      //End Variable

      //lecture du fichier
      do{
		printf("Saisir le nom de fichier de donnees : ");
		scanf("%s", nom); 
		while(getchar() != '\n');
		err = lire_data(nom, &G, &n, &m);
	}while(err == 0);

	/*
	Liste_ville sert a verifier les villes dans lesquelles on est deja passé
	ordre_ville sert a sauvegarder l'ordre dans lequel on est passé
	*/
	int *liste_ville = NULL, *ordre_ville = NULL;
	
	// Declenche l'horloge
	timer = clock();

	liste_ville = malloc(n * sizeof(int));
	ordre_ville = malloc(n * sizeof(int));

	liste_ville[ville_actuelle] = 1;
	ordre_ville[0] = ville_actuelle;

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
	printf("\nL'ordre de visite de base est : ");
	for (int i = 0; i < n; i++)
	{
		printf(" -> %d", ordre_ville[i]);
	}
	printf("\nLe distance totale est de %4d km", distance_totale);
	
	int *new_ordre_ville = NULL;
	new_ordre_ville = malloc(n * sizeof(int));

	int new_distance;

	//Fait des recherches pendant TIMER_LIMIT secondes
	while (getTempsEcoule(timer) < TIMER_LIMIT){
		
		//Choisir 2 point au hasard
		
		
		new_ordre_ville = croiserPoint(1, 3, n, ordre_ville);
		
		printf("\nL'ordre de visite est : ");
		for (int i = 0; i < n; i++){
			printf(" -> %d", new_ordre_ville[i]);
		}
		new_distance = getPoidsTotal(G, n, new_ordre_ville);
		printf("\nLe distance totale est de %4d km", new_distance);

		if (distance_totale > new_distance){
			ordre_ville = new_ordre_ville;
		} 
	}



      return 0;
}

int* croiserPoint(int point_a, int point_b, int n, int ordre_ville[]){
	if (point_a >= 0 && point_a < n-1 && point_b < n-1 && point_a < point_b && (point_b - point_a) > 1)
	{ 
		int tempo;

		tempo = ordre_ville[point_a + 1];
		ordre_ville[point_a + 1] = ordre_ville[point_b + 1];
		ordre_ville[point_b + 1] = ordre_ville[point_b];
		ordre_ville[point_b] = tempo;

		return ordre_ville;
	}else{
		printf("Les conditions d'utilisation de la fonction ne sont pas respecte, Merci de verifier le code.\nTableau d'origine retourne\n");
		return(ordre_ville);
	}	
}