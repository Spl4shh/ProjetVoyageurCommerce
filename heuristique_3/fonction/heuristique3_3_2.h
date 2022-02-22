#ifndef HEURISTIQUE3_3_2_H
      #define HEURISTIQUE3_3_2_H
      
      #include "../../Programme_Fourni/graphe.h"
      #include <stdio.h>

      /* 
            Assemble les points 1 par 1, cherche la position la plus avantageuse pour chaque poids lorsqu'il est place
            Par exemple si on a ACB pour D, on va tester ADCB, ACDB, ACBD et on garde celui avec le poids le plus faible
            Peut etre assimilié a un plus proche voisin "optimisé"
            @param G le graphe
            @param n Le nombre de sommet dans le Graphe
            @param ordre_ville Le tableau qui contiendras le chemin. Doit au moins avoir la case 0 de rempli afin de donner la ville de depart
      */
      void assemblageAvantageux(Graphe G, int n, int ordre_ville[]);

#endif