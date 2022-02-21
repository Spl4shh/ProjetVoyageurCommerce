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

//créer un chemin rapide passant par tout les points, de façon aléatoire 
//avec g le graphe, n le nombre de ville (longueur de la table qui suit), ordre_ville la table de ville que l'on veut renvoyer
//et timer, le minuteur pour arreter la fonction avec le temps
void meilleurCheminRandom(Graphe g, int n, int *liste_ville, clock_t timer);


int main(int argc, char const *argv[]){
    // Variables
    char nom[30];
    Graphe g = NULL;
    int n, m;
    int err;
    clock_t t1;
	double cpu_boucle;
    // END Variables
    
    do{
		printf("saisir le nom de fichier de donnees : ");
		scanf("%s", nom); 
		while(getchar() != '\n');
		err = lire_data(nom, &g, &n, &m);
	}while(err == 0);
   
    int liste_ville[n];
    for (int i = 0; i < n; i++){
        liste_ville[i] = i;
    }
   
    t1 = clock();

    // Fait des recherches pendant TIMER_LIMIT
    meilleurCheminRandom(g, n, liste_ville, t1);

    // Affichage
    affichageTimer(t1);
    afficheCheminPoids(g, n, liste_ville);
}

void meilleurCheminRandom(Graphe g, int n, int *liste_ville, clock_t timer){
    int poids = getPoidsTotal(g, n, liste_ville);

    int chemin_test[n];
    copieTable(chemin_test, liste_ville, n);

	while (getTempsEcoule(timer) < TIMER_LIMIT){
        permut_complete(&liste_ville[1], n-1);
        if(getPoidsTotal(g, n, liste_ville) > (getPoidsTotal(g, n, chemin_test))){
            copieTable(liste_ville, chemin_test, n);
        }    
    }  
}