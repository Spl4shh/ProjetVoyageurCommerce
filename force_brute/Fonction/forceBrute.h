#ifndef FORCEBRUTE_H
      #define FORCEBRUTE_H

      #include <stdio.h>
      #include <time.h>
      #include <stdlib.h>
      #include "../../Programme_Fourni/graphe.h"

      int brutePermut(int a[], int len);

      void quicksort(int a[], int start, int end);

      /*
            Brute force :
            Utilise une methode permutation en ordre lexicographique
            Afin de retrouver toutes les possibilitees d'ordre unique
      */
      void bruteForce(Graphe G, int n, int ordre_ville[], clock_t timer, int Timer_Limit);
    
#endif