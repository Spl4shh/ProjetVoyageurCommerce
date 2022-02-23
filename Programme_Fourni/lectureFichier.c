#ifndef LECTUREFICHIER_C
#define LECTUREFICHIER_C

#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"

/* Main de test, penser a importer affichage.h
int main()
{
	char nom[30];
	Graphe G = NULL;
	int n, m;
	int err;
		
	do{
		printf("saisir le nom de fichier de donnees : ");
		scanf("%s", nom); 
		while(getchar() != '\n');
		err = lire_data(nom, &G, &n, &m);
	}while(err == 0);
	affiche_km(G, n);

	affiche_une_ville(G, n, 2);
}
*/

int lire_data(char * nom, Graphe * g, int *nb, int *m)
{
	char str[15];
	int i, s1, s2, km;
	FILE * f = fopen(nom, "r");
	
	if (f == NULL) return 0; // le fichier n'existe pas
	
	// la première ligne contient le nombre de sommets n et le nombre d'arêtes m
	fgets(str, 15, f);
	sscanf(str, "%d %d", nb, m);
	
	// allocation dynamique d'un tableau n x n rempli de 0
	*g = (int **)calloc(sizeof(int *), *nb);
	for (i = 0; i < *nb; i++){
		(*g)[i] = (int *)calloc(sizeof(int), *nb);
	} 

	// lecture du fichier et remplissage du tableau G
	for (i = 0; i < *m; i++)
	{
		fgets(str, 15, f);
		sscanf(str, "%d %d %d", &s1, &s2, &km);
		(*g)[s1][s2] = km;
		(*g)[s2][s1] = km;
	}
	fclose(f);
	return 1;
}


int lireNbrIteration(){
	/*
	int n;
	do{
		printf("saisir le nombre d'iteration");
		scanf("%d", n); 
		//while(getchar() != '\n');
	}while(n <= 0);
	*/
	

	
	int n;
	do 
	{ 
		printf("saisir le nombre d'iteration"); 
		scanf("%d", &n); 
		while(getchar() != '\n');
	}while (n <= 0); 
	

	return n;
}

#endif