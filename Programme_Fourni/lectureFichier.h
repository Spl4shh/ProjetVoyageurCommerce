#ifndef LECTUREFICHIER_H
      #define LECTUREFICHIER_H
      #include "graphe.h"

      // lecture des données dans un fichier et construction du graphe
      int lire_data(char * nom, Graphe * g, int *n, int *m);

      // lit le nombre d'itération que l'on doit faire
      int lireNbrIteration();
      
      // lit le fichier
      void lireFichier(char * nom, Graphe * G, int *n, int *m);

#endif