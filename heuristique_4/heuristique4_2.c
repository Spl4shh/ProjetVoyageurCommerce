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

#define TIMER_LIMIT 60.0
/*
	Pour l'heuristique 4.2, on reutilise l'heucaristique 3.2 et on créé les fonctions nécéssaires
*/

/* 
   Permutter 2 points avec un deplacement afin de (dé)croiser une arrete
   Le point a correspond au depart de la premiere arrete et le point b correspond au depart de la deuxieme arrete
   Conditions : 
	point_a >= 0 
	point_a < n-1
	point_b < n-1
	point_a < point_b
	point_b - point_a > 1
   Avec n la taille du tableau
*/
void croiserPoint(int point_a, int point_b, int n, int ordre_ville[], int nouveau_tableau[]);

/*
	Recherche le parcous avec le plus faible poids.
	Effectue des permutations aleatoires et compare son poids avec le poids du chemion actuel.
	Effectue des permutations pendant TIMER_LIMIT.
*/
void rechercheParcoursCroisement(Graphe G, clock_t timer, int n, int ordre_ville[], int new_ordre_ville[]);

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
	

	// Affichage l'ordre selon le voisin le plus proche
	printf("\nAvec la recherche du plus proche voisin :");	
	afficheCheminPoids(G, n, ordre_ville);

	// Definition du nouveau tableau pour faire les tests
	int *new_ordre_ville = NULL;
	new_ordre_ville = malloc(n * sizeof(int));

	//Fait des recherches pendant TIMER_LIMIT secondes
	rechercheParcoursCroisement(G, timer, n, ordre_ville, new_ordre_ville);

	// Affichage resultat aprezs permutation
	printf("\n\nAvec des permutations aleatoire :");	
	affichageTimer(timer);
	afficheCheminPoids(G, n, ordre_ville);

      return 0;
}

void croiserPoint(int point_a, int point_b, int n, int ordre_ville[], int nouveau_tableau[]){
	copieTable(nouveau_tableau, ordre_ville, n);

	if (point_a >= 0 && point_a < n-1 && point_b < n-1 && point_a < point_b && (point_b - point_a) > 1){ 
		int tempo;
		
		tempo = ordre_ville[point_a + 1];
		nouveau_tableau[point_a + 1] = nouveau_tableau[point_b + 1];
		nouveau_tableau[point_b + 1] = nouveau_tableau[point_b];
		nouveau_tableau[point_b] = tempo;

	}else{
		printf("\nLes conditions d'utilisation de la fonction ne sont pas respecte, Merci de verifier le code.\n Point 1 = %d, Point 2 = %d\n", point_a, point_b);
	}	
}

void rechercheParcoursCroisement(Graphe G, clock_t timer, int n, int ordre_ville[], int new_ordre_ville[]){
	while (getTempsEcoule(timer) < TIMER_LIMIT){
		//Choisir 2 points au hasard

		int nb1 = randomNumber(0, n-4); // n-4 pour laisser la place a l'autre nombre d'etre selectionné
		int nb2 = randomNumber(0, n-2);
		while(nb2 <= (nb1 + 1)){
			nb2 = randomNumber(0, n-2);
		}
		
		croiserPoint(nb1, nb2, n, ordre_ville, new_ordre_ville);
		
		/* DEBUG  Affiche chaque ordre de visite testé lors des permutations
		printf("\nL'ordre de visite teste est : ");
		for (int i = 0; i < n; i++){
			printf(" -> %d", new_ordre_ville[i]);
		}
		printf("\nLe distance totale teste est de %4d km", getPoidsTotal(G, n, new_ordre_ville));
		*/

		if (getPoidsTotal(G, n, ordre_ville) > getPoidsTotal(G, n, new_ordre_ville)){
			copieTable(ordre_ville, new_ordre_ville, n);
			
			/*DEBUG Affiche lorsqu'il y a un changement d'ordre de ville lors de la permutation
			printf("\nL'ordre de visite retenue est : ");
			for (int i = 0; i < n; i++){
				printf(" -> %d", ordre_ville[i]);
			}
			printf("\nLe distance retenue est de %4d km", getPoidsTotal(G, n, ordre_ville));
			*/
		}
	}
}