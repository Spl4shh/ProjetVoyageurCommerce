#ifndef HEURISTIQUE4_2_C
    #define HEURISTIQUE4_2_C

    #include <time.h>
    #include "../../Programme_Fourni/graphe.h"
    #include "../../Programme_Fourni/calculTemps.h"
    #include "../../Fonction/table.c"
    #include "../../Fonction/poids.c"
    #include "../../Fonction/randomNumber.c"
    
    void croiserPoint(int point_a, int point_b, int n, int ordre_ville[], int nouveau_tableau[]){
        copieTable(nouveau_tableau, ordre_ville, n);

        if (point_a >= 0 && point_a < n-1 && point_b < n-1 && point_a < point_b){ 
            int tempo;
            
            tempo = ordre_ville[point_a + 1];
            nouveau_tableau[point_a + 1] = nouveau_tableau[point_b + 1];
            nouveau_tableau[point_b + 1] = nouveau_tableau[point_b];
            nouveau_tableau[point_b] = tempo;

        }else{
            printf("\nLes conditions d'utilisation de la fonction ne sont pas respecte, Merci de verifier le code.\n Point 1 = %d, Point 2 = %d\n", point_a, point_b);
        }	
    }

    void rechercheParcoursCroisement(Graphe G, clock_t timer, int n, int ordre_ville[], int Timer_Limit){
        int *new_ordre_ville = NULL;
        new_ordre_ville = malloc(n * sizeof(int));
        
        int i = 0, j = 1; 

        while (getTempsEcoule(timer) < Timer_Limit && i < (n-4)){
            
            if (j == (n-1)){
                i++;
                j = i+1;
            }
            
            
            croiserPoint(i, j, n, ordre_ville, new_ordre_ville);
            printf("Here / ");
            /* DEBUG  Affiche chaque ordre de visite testé lors des permutations
            printf("\nL'ordre de visite teste est : ");
            for (int i = 0; i < n; i++){
                printf(" -> %d", new_ordre_ville[i]);
            }
            printf("\nLe distance totale teste est de %4d km", getPoidsTotal(G, n, new_ordre_ville));
            */

            if (getPoidsTotal(G, n, ordre_ville) > getPoidsTotal(G, n, new_ordre_ville)){
                copieTable(ordre_ville, new_ordre_ville, n);
                
                /*DEBUG Affiche lorsqu'il y a un changement d'ordre de ville lors de la permutation
                printf("\nL'ordre de visite retenue est : ");
                for (int i = 0; i < n; i++){
                    printf(" -> %d", ordre_ville[i]);
                }
                printf("\nLe distance retenue est de %4d km", getPoidsTotal(G, n, ordre_ville));
                */
            }
            j++;
        }
    }

#endif