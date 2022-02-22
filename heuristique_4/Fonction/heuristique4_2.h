#ifndef HEURISTIQUE4_2_H
      #define HEURISTIQUE4_2_H
      #include <time.h>
      #include "../../Programme_Fourni/graphe.h"

      /* 
      Permutter 2 points avec un deplacement afin de (dé)croiser une arrete
      Le point a correspond au depart de la premiere arrete et le point b correspond au depart de la deuxieme arrete
      Conditions : 
            point_a >= 0 
            point_a < n-1
            point_b < n-1
            point_a < point_b
            point_b - point_a > 1
      Avec n la taille du tableau
      */
      void croiserPoint(int point_a, int point_b, int n, int ordre_ville[], int nouveau_tableau[]);

      /*
            Recherche le parcous avec le plus faible poids.
            Effectue des permutations aleatoires et compare son poids avec le poids du chemion actuel.
            Effectue des permutations pendant TIMER_LIMIT.
      */
      void rechercheParcoursCroisement(Graphe G, clock_t timer, int n, int ordre_ville[], int Timer_Limit);

#endif