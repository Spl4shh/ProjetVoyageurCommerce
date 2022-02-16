#ifndef AFFICHAGECOMBINE_H
      #define AFFICHAGECOMBINE_H
      
      #include "../Programme_Fourni/graphe.h"
      #include <time.h>

      // Affichage du chemin en parametre ainsi que son poids total
      void afficheCheminPoids(Graphe G, int n, int ordre_ville[]);

      // Affiche le temps écoulé depuis le lancement de timer
      void affichageTimer(clock_t timer);
#endif