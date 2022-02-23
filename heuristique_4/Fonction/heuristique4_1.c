#ifndef HEURISTIQUE4_1_C
    #define HEURISTIQUE4_1_C

    #include <time.h>
    #include "../../Programme_Fourni/graphe.h"
    #include "../../Fonction/poids.c"
    #include "../../Programme_Fourni/calculTemps.c"
    #include "heuristique4_1.h"
    #include "../../heuristique_3/Fonction/heuristique3_2.c"

    void permutationPoint(int point_a, int point_b, int n, int ordre_ville[], int nouveau_tableau[]){
        copieTable(nouveau_tableau, ordre_ville, n);

        if (point_a >= 0 && point_a < n && point_b >= 0 && point_b < n){ 
            int tempo;
            
            tempo = nouveau_tableau[point_a];
            nouveau_tableau[point_a] = nouveau_tableau[point_b];
            nouveau_tableau[point_b] = tempo;
        }else{
            printf("\nLes conditions d'utilisation de la fonction ne sont pas respecte, Merci de verifier le code.\n Point 1 = %d, Point 2 = %d\n", point_a, point_b);
        }	
    }

    void rechercheParcoursPermutation(Graphe G, int n, int ordre_ville[], clock_t timer, int Timer_Limit){
        int *new_ordre_ville = NULL;
        new_ordre_ville = malloc(n * sizeof(int));

        int i = 0, j = 0;
        
        // On peut s'arreter a i = n car cela veux dire qu'on auras tout parcouru
        while (getTempsEcoule(timer) < Timer_Limit && (i < n)){
            
            
            permutationPoint(i, j, n, ordre_ville, new_ordre_ville);
            
            /* DEBUG  Affiche chaque ordre de visite testé lors des permutations
            printf("\nL'ordre de visite teste est : ");
            for (int i = 0; i < n; i++){
                printf(" -> %d", new_ordre_ville[i]);
            }
            printf("\nLe distance totale teste est de %4d km", getPoidsTotal(G, n, new_ordre_ville));
            */

            if (getPoidsTotal(G, n, ordre_ville) >= getPoidsTotal(G, n, new_ordre_ville)){
                copieTable(ordre_ville, new_ordre_ville, n);
                
                /*DEBUG Affiche lorsqu'il y a un changement d'ordre de ville lors de la permutation
                printf("\nL'ordre de visite retenue est : ");
                for (int i = 0; i < n; i++){
                    printf(" -> %d", ordre_ville[i]);
                }
                printf("\nLe distance retenue est de %4d km", getPoidsTotal(G, n, ordre_ville));
                */
            }

            // Modification de la valeur des points
            j++;

            // Pour ne pas echanger le point avec lui meme
            if (j == i){
                j++;
            }

            // Changement de point de base
            if (!(j < n)){
                i++;
                j = i;
            }
        }
    }

#endif