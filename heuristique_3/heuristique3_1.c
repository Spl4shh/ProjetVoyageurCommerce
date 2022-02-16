#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#include "../Programme_Fourni/graphe.h"
#include "../Programme_Fourni/affichage.c"
#include "../Programme_Fourni/lectureFichier.c"
#include "../Programme_Fourni/permutation.c"
#include "../Programme_Fourni/calculTemps.c"


int get_poids_total(Graphe g, int n, int *ordre_ville){
	int somme_poids = 0;
	int point_a, point_b;
    
	for (int i = 0; i < n-1; i++)
	{
        
		point_a = ordre_ville[i];
		point_b = ordre_ville[i+1];	
		somme_poids += g[point_a][point_b];
	}

	return somme_poids;
}

void setTable(int *a, int *b, int n){
    for (int i=0; i<n; i++){
        a[i]=b[i];
    }
}


int isNotIn(int r, int *p, int l){
    for (int i=0; i<l; i++){
        if (r==p[i]){
            return 0;
        }
    }
    return 1;
}


void meilleurCheminRandom(Graphe g, int n, int *liste_ville){
   int poids = get_poids_total(g, n, liste_ville);
    unsigned long j=10000;

    int chemin_test[n];
   setTable(chemin_test, liste_ville, n);

   for(int i=1; i<j; i++){
       permut_complete(liste_ville, n);
       if(get_poids_total(g, n, liste_ville)>(get_poids_total(g, n, chemin_test))){
           setTable(liste_ville,chemin_test , n);
       }
   }

   
}

int main(int argc, char const *argv[]){
    char nom[30];
    Graphe g = NULL;
    int n, m;
    int err;
    int poid;


    clock_t t1, t2;
	double cpu_boucle;
	
    t1 = clock();
    
    do{
		printf("saisir le nom de fichier de donnees : ");
		scanf("%s", nom); 
		while(getchar() != '\n');
		err = lire_data(nom, &g, &n, &m);
	}while(err == 0);
   
   
   int liste_ville[n];
   for (int i=0; i<n; i++){
       liste_ville[i]=i;
   }
   

   
   meilleurCheminRandom( g, n, liste_ville);


    t2 = getTempsEcoule(t1);
	
	cpu_boucle = (double)(t2-t1)/(double)(CLOCKS_PER_SEC);
	printf("temps cpu de la boucle en secondes %f\n", cpu_boucle);
   
   printf("Listes des villes : ");
   affiche_tableau(liste_ville, n);
   printf("\nPoid du voyage : %d ", get_poids_total(g, n, liste_ville));
}

