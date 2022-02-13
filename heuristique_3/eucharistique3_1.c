#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include "../Programme_Fourni/graphe.h"
#include "../Programme_Fourni/affichage.c"
#include "../Programme_Fourni/lectureFichier.c"


int main(int argc, char const *argv[]){
    char nom[30];
    Graphe g = NULL;
    int n, m;
    int err;
    
    do{
		printf("saisir le nom de fichier de donnees : ");
		scanf("%s", nom); 
		while(getchar() != '\n');
		err = lire_data(nom, &G, &n, &m);
	}while(err == 0);
   
   int liste_ville[n];
   for (int i=0; i<n; i++){
       liste_ville[n]=-1;
   }

   srand(time(NULL));
   int r;

   for(i=0; i<n; i++){
       while ((isNotIn (r, liste_ville, n))==0){
           r = rand()%n
       }
       liste_ville[i]=r;
   }

}


isNotIn(int r, int *p, int l){
    for (int i=0; i<l; i++){
        if (r==p[i]){
            return 0;
        }
    }
    return 1;
}