#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../Programme_Fourni/graphe.h"
#include "../Programme_Fourni/affichage.c"
#include "../Programme_Fourni/lectureFichier.c"
#include "../Programme_Fourni/permutation.c"
#include "../Programme_Fourni/calculTemps.c"

#include "../Fonction/affichageCombine.c"
#include "../Fonction/table.c"
#include "../Fonction/poids.c"

#include "./Fonction/permutBrute.c"

#define TIMER_LIMIT 1800.0

/*
    Brute force :
    Utilise une methode permutation en ordre strictement croissant
    Afin de retrouver toutes les possibilitees d'ordre unique
*/

int main(int argc, char const *argv[]){
    // Variables
    char nom[30];
    Graphe G = NULL;
    int n, m;
    int err;
    clock_t t1;
    int *liste_ville;
    // END Variables
    
    do{
		printf("saisir le nom de fichier de donnees : ");
		scanf("%s", nom); 
		while(getchar() != '\n');
      //nom = "../data/communes_10.txt";
		err = lire_data(nom, &G, &n, &m);
	} while(err == 0);
   
    liste_ville = malloc(n * sizeof(int));
   
    for (int i = 0; i < n; i++){
        liste_ville[i] = i;
    }
   
    t1 = clock();

    // Fait des recherches pendant TIMER_LIMIT
    bruteForce(G, n, liste_ville, t1, TIMER_LIMIT);

    // Affichage
    affichageTimer(t1);
    afficheCheminPoids(G, n, liste_ville);
}