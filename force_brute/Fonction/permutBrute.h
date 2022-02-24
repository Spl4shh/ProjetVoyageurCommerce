#ifndef PERMUTBRUTE_H
      #define PERMUTBRUTE_H

      #include <stdio.h>
      #include <time.h>
      #include <stdlib.h>
      #include "../../Programme_Fourni/graphe.h"

      /*
            Brute force :
            Utilise une methode permutation en ordre lexicographique
            Afin de retrouver toutes les possibilitees d'ordre unique
      */
      int prochainePermut(int a[], int len);
      
      void bruteForce(Graphe G, int n, int ordre_ville[], clock_t timer, int TIMER_LIMIT);
    
#endif