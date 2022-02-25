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
    Graphe G = NULL;
    int n, m;
    clock_t t1;
    // END Variable

    lireFichier(nom, &G, &n, &m);
   
    int *ordre_ville = NULL;
	ordre_ville = malloc(n * sizeof(int)); 
   
    t1 = clock();
    rechercheCheminInsertion(G, n, ordre_ville, t1, TIMER_LIMIT);

    // Affichage
    affichageTimer(t1);
    afficheCheminPoids(G, n, ordre_ville);
}