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

#include "./Fonction/forceBrute.c"

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
    err = lire_data(nom, &G, &n, &m);
  } while(err == 0);
   
  liste_ville = malloc(n * sizeof(int));
  
  t1 = clock();

  // Fait des recherches pendant TIMER_LIMIT
  bruteForce(G, n, liste_ville);

  // Affichage
  affichageTimer(t1);
  afficheCheminPoids(G, n, liste_ville);
}