#ifndef POIDS_H
      #define POIDS_H

      #include "../Programme_Fourni/graphe.h";

      // calcul du poids total d'un chemin en fcontion d'un graphe, du nb de sommet et de l'ordre des sommets traversé
      int get_poids_total(Graphe g, int n, int ordre_ville[]);

#endif