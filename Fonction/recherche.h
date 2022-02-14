#ifndef RECHERCHE_H
      #define RECHERCHE_H

      #include "../Programme_Fourni/graphe.h";

      /*
            Recherche la ville la plus proche de la ville "num_ville"
            liste_ville[] est un tableau contenant les numeros des villes deja visité en indice, et 1 en valeur de liste_ville[i] si elle a été visité
      */
      int rechercheVoisinProche(Graphe g, int n, int num_ville, int liste_ville[]);

#endif