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

#define TIMER_LIMIT 60.0

int main(int argc, char const *argv[]){
    // Variables
    char nom[30];
    Graphe g = NULL;
    int n, m;
    int err;
    clock_t t1;
	double cpu_boucle;
    // END Variable

    do{
		printf("saisir le nom de fichier de donnees : ");
		scanf("%s", nom); 
		while(getchar() != '\n');
		err = lire_data(nom, &g, &n, &m);
	}while(err == 0);
   
    int *liste_ville = NULL;

	liste_ville = malloc(n * sizeof(int));
    

    for (int i = 0; i < n; i++){
        liste_ville[i] = i;
    }
   
    t1 = clock();

    bruteForce(g, n, liste_ville, t1);

    // Affichage
    affichageTimer(t1);
    afficheCheminPoids(g, n, liste_ville);
}
