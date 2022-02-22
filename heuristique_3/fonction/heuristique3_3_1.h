#ifndef HEURISTIQUE3_3_1_H
      #define HEURISTIQUE3_3_1_H
      
      #include <time.h>
      #include "../../Programme_Fourni/graphe.h"

      // Décale les élément d'une table vers la gauche
      void decalageVersGauche(int *table, int n);

      // Insert un élément qui viens de la droite de la table
      void insererElementDroite(int decalage, int rangDep, int *liste);

      // Appel cheminParInsertion en boucle pendant TIMER_LIMIT avec des listes différentes, variant aléatoirement
      void rechercheCheminInsertion(Graphe g, int n, int ordre_ville[], clock_t timer, int Timer_Limit);

      // Cherche un chemin rapide en inserant de nouvelle ville une par une, en vérifiant quelle insertion est la plus rapide
      void cheminParInsertion(Graphe g, int n, int *liste_ville);

#endif