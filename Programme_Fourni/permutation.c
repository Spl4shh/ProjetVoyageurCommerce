#ifndef PERMUTATION_H
#define PERMUTATION_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// fonction qui retourne un entier au hasard entre a et b
int rnd(int a, int b); 

// fonction qui réalise une permutation des éléments de la table t 
void permut_complete(int * t, int taille);

// fonction qui affiche les éléments d'un tableau
void affiche_tableau(int * t, int taille); 

/* Main de test
int main()
{
	int tab[] = {21,45,18,37,52,89,63,97,78,11};
	int i, nb_perm;
	clock_t t1, t2;
	double cpu_perm;
	
	srand((unsigned int)time(NULL));
	
	printf("nombre de permutations a generer : ");
	scanf("%d", &nb_perm);
	
	t1 = clock();
	
	for(i = 0; i < nb_perm; i++){
		permut_complete(tab, 10);
		affiche_tableau(tab, 10);
		printf("\n");
	}

	t2 = clock();
	
	cpu_perm = (double)(t2-t1)/(double)(CLOCKS_PER_SEC);
	printf("les %d permutations ont ete genere en %f secondes\n", nb_perm, cpu_perm);
}
*/

// Question : quel sera le résultat pour l'appel affiche_tableau(tab+1, 3) ?
// Question : quel sera le résultat pour l'appel permut(tab+1, 3) ?

int rnd(int a, int b){
    return (a + rand() % (b + 1 - a));
}

void permut_complete(int * t, int taille){
	int i, j, tempo;

	for(i = 0; i < taille-1; i++){
		j = rnd(i, taille-1);
		tempo = t[i];
		t[i] = t[j];
		t[j] = tempo;
	}
}

void affiche_tableau(int * t, int taille){
	int i;

	for(i = 0; i < taille; i++){
		printf("%d ", t[i]);
	}
}

#endif