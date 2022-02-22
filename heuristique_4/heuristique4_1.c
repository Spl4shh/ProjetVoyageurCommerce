#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "../Programme_Fourni/graphe.h"
#include "../Programme_Fourni/affichage.c"
#include "../Programme_Fourni/lectureFichier.c"
#include "../Programme_Fourni/calculTemps.c"

#include "../Fonction/poids.c"
#include "../Fonction/table.c"
#include "../Fonction/recherche.c"
#include "../Fonction/randomNumber.c"
#include "../Fonction/affichageCombine.c"

#include "../heuristique_3/heuristique3_1.c"
#include "../heuristique_3/heuristique3_2.c"
#include "../heuristique_3/heuristique3_3_1.c"
#include "../heuristique_3/heuristique3_3_2.c"

#define TIMER_LIMIT 1.0
/*
	Pour l'heuristique 4.1, on reutilise l'heucaristique 3.2 et on créé les fonctions nécéssaires
*/

/* 
   Permutter 2 points
   Conditions : 
	point_a >= 0 
	point_b >= 0 
	point_a < n
	point_b < n
      point_a != point_b            
   Avec n la taille du tableau
*/
void permutationPoint(int point_a, int point_b, int n, int ordre_ville[], int nouveau_tableau[]);

/*
	Recherche le parcous avec le plus faible poids.
	Effectue des permutations aleatoires et compare son poids avec le poids du chemion actuel.
	Effectue des permutations pendant TIMER_LIMIT.
*/
void rechercheParcoursPermutation(Graphe G, int n, int ordre_ville[], clock_t timer);

int main(int argc, char const *argv[])
{
      //Variables
      char nom[30];
	Graphe G = NULL;
	int n, m;
	int err;
	int ville_actuelle = 0, ville_suivante;
	clock_t timer;
	srand((unsigned int)time(NULL));
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

	liste_ville = malloc(n * sizeof(int));
	ordre_ville = malloc(n * sizeof(int));

	liste_ville[ville_actuelle] = 1;
	ordre_ville[0] = ville_actuelle;

	//Declenche l'horloge
	timer = clock();

	rechercheCheminVoisinPlusProche(G, n, ordre_ville);
	meilleurCheminRandom(G, n, ordre_ville, timer);
	rechercheCheminInsertion(G, n, ordre_ville, timer);
	assemblageAvantageux(G, n, ordre_ville);

	// Affichage l'ordre selon le voisin le plus proche
	printf("\nAvec la recherche du plus proche voisin :");	
	afficheCheminPoids(G, n, ordre_ville);

	//Fait des recherches pendant TIMER_LIMIT secondes
	rechercheParcoursPermutation(G, n, ordre_ville, timer);

	// Affichage resultat aprezs permutation
	printf("\n\nAvec des permutations aleatoire :");	
	affichageTimer(timer);
	afficheCheminPoids(G, n, ordre_ville);

      return 0;
}

void permutationPoint(int point_a, int point_b, int n, int ordre_ville[], int nouveau_tableau[]){
	copieTable(nouveau_tableau, ordre_ville, n);

	if (point_a >= 0 && point_a < n && point_b >= 0 && point_b < n && point_a != point_b){ 
		int tempo;
		
		tempo = nouveau_tableau[point_a];
		nouveau_tableau[point_a] = nouveau_tableau[point_b];
		nouveau_tableau[point_b] = tempo;
	}else{
		printf("\nLes conditions d'utilisation de la fonction ne sont pas respecte, Merci de verifier le code.\n Point 1 = %d, Point 2 = %d\n", point_a, point_b);
	}	
}

void rechercheParcoursPermutation(Graphe G, int n, int ordre_ville[], clock_t timer){
	int **listePermutation = NULL;
	listePermutation = malloc(n*n*sizeof(int));

	int *new_ordre_ville = NULL;
	new_ordre_ville = malloc(n * sizeof(int));

	int i = 0, j = 0;
	
	// On peut s'arreter a i = n car cela veux dire qu'on auras tout parcouru
	while (getTempsEcoule(timer) < TIMER_LIMIT || (i != n)){
		//Choisir 2 points au hasard

		int nb1 = randomNumber(0, n-1); // n-4 pour laisser la place a l'autre nombre d'etre selectionné
		int nb2 = randomNumber(0, n-1);
		while(nb2 == nb1){
			nb2 = randomNumber(0, n-1);
		}

		permutationPoint(nb1, nb2, n, ordre_ville, new_ordre_ville);
		
		/* DEBUG  Affiche chaque ordre de visite testé lors des permutations
		printf("\nL'ordre de visite teste est : ");
		for (int i = 0; i < n; i++){
			printf(" -> %d", new_ordre_ville[i]);
		}
		printf("\nLe distance totale teste est de %4d km", getPoidsTotal(G, n, new_ordre_ville));
		*/

		if (getPoidsTotal(G, n, ordre_ville) >= getPoidsTotal(G, n, new_ordre_ville)){
			copieTable(ordre_ville, new_ordre_ville, n);
			
			/*DEBUG Affiche lorsqu'il y a un changement d'ordre de ville lors de la permutation
			printf("\nL'ordre de visite retenue est : ");
			for (int i = 0; i < n; i++){
				printf(" -> %d", ordre_ville[i]);
			}
			printf("\nLe distance retenue est de %4d km", getPoidsTotal(G, n, ordre_ville));
			*/
		}

		// Modification de la valeur des points
		j++;

		if (j == n){
			j = 0;
			i++;
		}
	}
}