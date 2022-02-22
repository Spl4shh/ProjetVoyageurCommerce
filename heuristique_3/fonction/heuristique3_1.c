#ifndef HEURISTIQUE3_1_C
    #define HEURISTIQUE3_1_C

    #include <time.h>
    #include "../../Programme_Fourni/graphe.h"
    #include "heuristique3_1.h"

    void meilleurCheminRandom(Graphe G, int n, int ordre_ville[], clock_t timer, int TIMER_LIMIT){
        int chemin_test[n];
        copieTable(chemin_test, ordre_ville, n);

        while (getTempsEcoule(timer) < TIMER_LIMIT){
            // Permutation de toute la table sauf du premier élément
            permut_complete(&chemin_test[1], n-1);
            
            if(getPoidsTotal(G, n, ordre_ville) > (getPoidsTotal(G, n, chemin_test))){
                copieTable(ordre_ville, chemin_test, n);
            }    
        }  
    }

#endif