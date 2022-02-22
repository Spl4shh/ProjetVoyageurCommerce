#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../Programme_Fourni/graphe.h"
#include "../Programme_Fourni/affichage.c"
#include "../Programme_Fourni/lectureFichier.c"
#include "../Programme_Fourni/permutation.c"
#include "../Programme_Fourni/calculTemps.c"

#include "../Fonction/recherche.c"
#include "../Fonction/affichageCombine.c"
#include "../Fonction/table.c"
#include "../Fonction/poids.c"

#include "Fonction/heuristique3_3_1.c"

#define TIMER_LIMIT 5.0

int main(int argc, char const *argv[]){
    // Variables
    char nom[30];
    Graphe g = NULL;
    int n, m;
    int err;
    clock_t t1;
    // END Variable

    do{
		printf("saisir le nom de fichier de donnees : ");
		scanf("%s", nom); 
		while(getchar() != '\n');
		err = lire_data(nom, &g, &n, &m);
	}while(err == 0);
   
    int *ordre_ville = NULL;
	ordre_ville = malloc(n * sizeof(int)); 

    for (int i = 0; i < n; i++){
        ordre_ville[i] = i;
    }
   
    t1 = clock();
    rechercheCheminInsertion(g, n, ordre_ville, t1, TIMER_LIMIT);

    // Affichage
    affichageTimer(t1);
    afficheCheminPoids(g, n, ordre_ville);
}