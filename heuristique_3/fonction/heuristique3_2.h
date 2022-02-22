#ifndef HEURISTIQUE3_2_H
      #define HEURISTIQUE3_2_H
      
      #include "../../Programme_Fourni/graphe.h"

      /*
            Cet fonction permet de construire le tableau ordre_ville afin d'avoir le chemin
            construit en fonction du plus proche voisin.
            @param G Graphe des villes et de leurs chemins avec le poids
            @param n Le nombre de ville dans le graphe
            @param ordre_ville[] La table contenant l'ordre de visite des villes
      */
      void rechercheCheminVoisinPlusProche(Graphe G, int n, int ordre_ville[]);

#endif