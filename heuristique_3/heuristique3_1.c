#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#include "../Programme_Fourni/graphe.h"
#include "../Programme_Fourni/affichage.c"
#include "../Programme_Fourni/lectureFichier.c"
#include "../Programme_Fourni/permutation.c"
#include "../Programme_Fourni/calculTemps.c"

#include "../Fonction/affichageCombine.c"
#include "../Fonction/table.c"
#include "../Fonction/poids.c"

#include "Fonction/heuristique3_1.c"

#define TIMER_LIMIT 15.0

int main(int argc, char const *argv[]){
    // Variables
    char nom[30];
    Graphe G = NULL;
    int n, m;
    int err;
    clock_t t1;
    // END Variables
    
    srand((unsigned int)time(NULL));
    
    do{
		printf("saisir le nom de fichier de donnees : ");
		scanf("%s", nom); 
		while(getchar() != '\n');
		err = lire_data(nom, &G, &n, &m);
	}while(err == 0);
   
    // Creer la table qui va contenir le chemin final
    int *ordre_ville;
    ordre_ville = malloc(n * sizeof(int));

    // Ranger les villes dans l'ordre
    for (int i = 0; i < n; i++){
        ordre_ville[i] = i;
    }
   
    t1 = clock();

    // Fait des recherches pendant TIMER_LIMIT
    meilleurCheminRandom(G, n, ordre_ville, t1, TIMER_LIMIT);

    // Affichage
    affichageTimer(t1);
    afficheCheminPoids(G, n, ordre_ville);
}