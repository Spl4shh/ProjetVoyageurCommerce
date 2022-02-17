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

#define TIMER_LIMIT 2.0

// Description de la fonction
void meilleurCheminRandom(Graphe g, int n, int *liste_ville, clock_t timer);

// Description de la fonction
int get_poids_total(Graphe g, int n, int *ordre_ville);

// Description de la fonction
int isNotIn(int r, int *p, int l);

int main(int argc, char const *argv[]){
    char nom[30];
    Graphe g = NULL;
    int n, m;
    int err;

    clock_t t1;
	double cpu_boucle;

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
    int poids = get_poids_total(g, n, liste_ville);

    int chemin_test[n];
    copieTable(chemin_test, liste_ville, n);

	while (getTempsEcoule(timer) < TIMER_LIMIT){
        permut_complete(liste_ville, n);
        if(get_poids_total(g, n, liste_ville) > (get_poids_total(g, n, chemin_test))){
            copieTable(liste_ville, chemin_test, n);
        }    
    }  
}

int get_poids_total(Graphe g, int n, int *ordre_ville){
	int somme_poids = 0;
	int point_a, point_b;
    
	for (int i = 0; i < n-1; i++){
		point_a = ordre_ville[i];
		point_b = ordre_ville[i+1];	
		somme_poids += g[point_a][point_b];
	}

	return somme_poids;
}

int isNotIn(int r, int *p, int l){
    for (int i = 0; i < l; i++){
        if (r == p[i]){
            return 0;
        }
    }
    return 1;
}