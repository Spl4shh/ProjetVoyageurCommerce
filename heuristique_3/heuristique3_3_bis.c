#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#include "../Programme_Fourni/graphe.h"
#include "../Programme_Fourni/affichage.c"
#include "../Programme_Fourni/lectureFichier.c"
#include "../Programme_Fourni/permutation.c"
#include "../Programme_Fourni/calculTemps.c"

#include "../Fonction/recherche.c"
#include "../Fonction/affichageCombine.c"
#include "../Fonction/table.c"
#include "../Fonction/poids.c"

#define TIMER_LIMIT 5.0


int main(int argc, char const *argv[])
{
    //Variables
    char nom[30];
	Graphe G = NULL;
	int n, m;
	int err;
	int ville_actuelle = 0, ville_suivante;
	clock_t timer;
	srand((unsigned int)time(NULL));
    //End Variable

    //lecture du fichier
    do{
		printf("Saisir le nom de fichier de donnees : ");
		scanf("%s", nom); 
		while(getchar() != '\n');
		err = lire_data(nom, &G, &n, &m);
	}while(err == 0);

	/*
	Liste_ville sert a verifier les villes dans lesquelles on est deja passé
	ordre_ville sert a sauvegarder l'ordre dans lequel on est passé
	*/
	int *liste_ville = NULL, *ordre_ville = NULL;

	liste_ville = malloc(n * sizeof(int));
	ordre_ville = malloc(n * sizeof(int));

	liste_ville[ville_actuelle] = 1;
	ordre_ville[0] = ville_actuelle;

	// Declenche l'horloge
	timer = clock();

    // Ici i correspondra à la valeur que l'on affecteras, on va donc devoir travailler avec i+1 quand on parlera de taille d'element
    for (int i = 0; i < n; i++)
    {
        int firstTest = 1;

        int * table_insertion = NULL;
        table_insertion = malloc((i+1) * sizeof(int));
        
        int * table_test = NULL;
        table_test = malloc((i+1) * sizeof(int));

        copieTable(table_insertion, ordre_ville, i+1);

        if (liste_ville[i] != 1){ // Si l'on a pas encore traité la ville
            for (int j = 1; j < i+1; j++){
                copieTable(table_test, ordre_ville, i+1);

                //Decalage
                for (int k = i; k > j /*Position de la valeur*/; k--){
                    table_test[k] = table_test[k-1];
                }
                table_test[j] = i;
                
                if (firstTest){
                    copieTable(table_insertion, table_test, i+1);                  
                    firstTest = 0; 
                }else{
                    if (getPoidsTotal(G, i, table_insertion) > getPoidsTotal(G, i, table_test)){
                        copieTable(table_insertion, table_test, i+1);
                    }  
                }
            }    
        }
        copieTable(ordre_ville, table_insertion, i+1); 

        free(table_insertion);
        free(table_test);
    } 

    afficheCheminPoids(G, n, ordre_ville);
    affichageTimer(timer);
    return 0;
}