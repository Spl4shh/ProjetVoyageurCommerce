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

#include "./permutBrute.c"

#define TIMER_LIMIT 1800.0

/*
  Brute force :
  Utilise une m�thode permutation en ordre lexicographique
  Afin de retrouver toutes les possibilitees d'ordre unique
*/
void bruteForce(Graphe G, int n, int ordre_ville[], clock_t timer);

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
  
  for (int i = 0; i < n; i++){
    liste_ville[i] = i;
  }
  
  t1 = clock();

  // Fait des recherches pendant TIMER_LIMIT
  bruteForce(G, n, liste_ville, t1);

  // Affichage
  affichageTimer(t1);
  afficheCheminPoids(G, n, liste_ville);
}

void bruteForce(Graphe G, int n, int ordre_ville[], clock_t timer){
  int chemin_test[n];
  copieTable(chemin_test, ordre_ville, n);
  int fact = 1;
  
  for ( int j = 1; j <= n; j++ ){
    fact = fact * j;
  }
  
  do{
    for ( int i = 0; i < fact; i++ ){
      brutePermut(chemin_test, n);

      if (getPoidsTotal(G, n, ordre_ville) > getPoidsTotal(G, n, chemin_test)){
        copieTable(ordre_ville, chemin_test, n);
      }
    }
  }while (timer < TIMER_LIMIT);
}