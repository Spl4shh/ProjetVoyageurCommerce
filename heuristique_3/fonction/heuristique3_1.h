#ifndef HEURISTIQUE3_1_C
      #define HEURISTIQUE3_1_C
      #include <time.h>
      #include "../../Programme_Fourni/graphe.h"

      /*
            Créé un chemin rapide passant par tout les points, de façon aléatoire 
            @param G Graphe des villes et de leurs chemins avec le poids
            @param n Le nombre de ville dans le graphe
            @param ordre_ville La table contenant l'ordre de visite des villes
            @param timer Le minuteur afin d'arreter les recherches
      */
      void meilleurCheminRandom(Graphe G, int n, int ordre_ville[], clock_t timer);

#endif