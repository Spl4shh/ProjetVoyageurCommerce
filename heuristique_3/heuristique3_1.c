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

#define TIMER_LIMIT 15.0

/*
    Créé un chemin rapide passant par tout les points, de façon aléatoire 
    @param g Graphe des villes et de leurs chemins avec le poids
    @param n Le nombre de ville dans le graphe
    @param ordre_ville La table contenant l'ordre de visite des villes
    @param timer Le minuteur afin d'arreter les recherches
*/
void meilleurCheminRandom(Graphe G, int n, int ordre_ville[], clock_t timer);


int main(int argc, char const *argv[]){
    // Variables
    char nom[30];
    Graphe G = NULL;
    int n, m;
    int err;
    clock_t t1;
    int *liste_ville;
    // END Variables
    
    srand((unsigned int)time(NULL));
    
    do{
		printf("saisir le nom de fichier de donnees : ");
		scanf("%s", nom); 
		while(getchar() != '\n');
		err = lire_data(nom, &G, &n, &m);
	}while(err == 0);
   
    liste_ville = malloc(n * sizeof(int));
   
    for (int i = 0; i < n; i++){
        liste_ville[i] = i;
    }
   
    t1 = clock();

    // Fait des recherches pendant TIMER_LIMIT
    meilleurCheminRandom(G, n, liste_ville, t1);

    // Affichage
    affichageTimer(t1);
    afficheCheminPoids(G, n, liste_ville);
}

void meilleurCheminRandom(Graphe G, int n, int ordre_ville[], clock_t timer){
    int chemin_test[n];
    copieTable(chemin_test, ordre_ville, n);

	while (getTempsEcoule(timer) < TIMER_LIMIT){
        // permutation de toute la table sauf du premier élément
        permut_complete(&chemin_test[1], n-1);
        
        if(getPoidsTotal(G, n, ordre_ville) > (getPoidsTotal(G, n, chemin_test))){
            copieTable(ordre_ville, chemin_test, n);
        }    
    }  
}