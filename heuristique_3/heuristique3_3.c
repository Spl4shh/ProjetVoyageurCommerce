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


//décale les élément d'une table vers la gauche
void decalageVersGauche(int *table, int n);

//insert un élément qui viens de la droite de la table
void insererElementDroite(int decalage, int rangDep, int *liste);

//appel cheminParInsertion en boucle pendant TIMER_LIMIT avec des listes différentes, variant aléatoirement
void rechercheCheminInsertion(Graphe g, int n, int *liste_ville, clock_t timer);

//cherche un chemin rapide en inserant de nouvelle ville une par une, en vérifiant quelle insertion est la plus rapide
void cheminParInsertion(Graphe g, int n, int *liste_ville);

int main(int argc, char const *argv[]){
    // Variables
    char nom[30];
    Graphe g = NULL;
    int n, m;
    int err;
    clock_t t1;
	double cpu_boucle;
    // END Variable

    do{
		printf("saisir le nom de fichier de donnees : ");
		scanf("%s", nom); 
		while(getchar() != '\n');
		err = lire_data(nom, &g, &n, &m);
	}while(err == 0);
   
    int *liste_ville = NULL;

	liste_ville = malloc(n * sizeof(int));
    

    for (int i = 0; i < n; i++){
        liste_ville[i] = i;
    }
   
    t1 = clock();

    rechercheCheminInsertion(g, n, liste_ville, t1);

    affichageTimer(t1);
    afficheCheminPoids(g, n, liste_ville);
}


void rechercheCheminInsertion(Graphe g, int n, int *liste_ville, clock_t timer){
    
    int chemin_test[n];
    copieTable(chemin_test, liste_ville, n);//initilisation de la table de test
    

    while (getTempsEcoule(timer) < TIMER_LIMIT){    
        
        cheminParInsertion(g, n, chemin_test);  //création du résultat de la seed (= trie de la table donnée aléarement)

        if(getPoidsTotal(g, n, liste_ville) > (getPoidsTotal(g, n, chemin_test))){
            copieTable(liste_ville, chemin_test, n);            //on sauvegarde la meilleure perf
        } 
        permut_complete(chemin_test, n);        //nouvelle seed
        
    }
}
    


void cheminParInsertion(Graphe g, int n, int *liste_ville){
  
    int chemin_test[n];
    copieTable(chemin_test, liste_ville, n);   //initilisation de la table de test
    
        for(int checked = 2; checked < n-1; checked++){     //pour chaque ville ajoutée
            for(int j = 0; j < checked; j++){               //pour chaque position de ville testée
                insererElementDroite(1, checked-j, chemin_test);

                if(getPoidsTotal(g, checked, chemin_test) < getPoidsTotal(g, checked, liste_ville)){
                    copieTable(liste_ville, chemin_test, n);    //on sauvegarde la meilleure performance
                }
            }
         
        }
}

void decalageVersGauche(int *table, int n){
        int save=table[0];  //on stock la donnée qui va être écrasée dans une variable
      for(int i=0; i<n; i++){
        table[i]=table[i+1];
      }
      table[n-1]=save;  //on ressort la donnée precedemment écrasée
}

void insererElementDroite(int decalage, int rangDep, int *liste){
    for (int i=rangDep; i>rangDep-decalage; i--){
        decalageVersGauche(&liste[i], 2);   //on cherche à inverser la positon  de 2 éléments de la partie de la table
    }
}