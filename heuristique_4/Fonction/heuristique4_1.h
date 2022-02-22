#ifndef HEURISTIQUE4_1_H
      #define HEURISTIQUE4_1_H
      #include <time.h>
      #include "../../Programme_Fourni/graphe.h"

      /* 
            Permutter 2 points
            Conditions : 
                  point_a >= 0 
                  point_b >= 0 
                  point_a < n
                  point_b < n
                  point_a != point_b            
            Avec n la taille du tableau
      */
      void permutationPoint(int point_a, int point_b, int n, int ordre_ville[], int nouveau_tableau[]);

      /*
            Recherche le parcous avec le plus faible poids.
            Effectue des permutations aleatoires et compare son poids avec le poids du chemion actuel.
            Effectue des permutations pendant TIMER_LIMIT.
      */
      void rechercheParcoursPermutation(Graphe G, int n, int ordre_ville[], clock_t timer, int Timer_Limit);

#endif