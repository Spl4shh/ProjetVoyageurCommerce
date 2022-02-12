#include<stdio.h>
#include<stdlib.h>

// définition du type Graphe comme un tableau à 2 dimensions
// allocation dynamique faite au moment de la lecture des
// données dans un fichier
typedef int ** Graphe;

// lecture des données dans un fichier et construction du graphe
int lire_data(char * nom, Graphe * g, int *n, int *m);

// affichage du graphe, i.e. du tableau des distances
void affiche_km(int ** g, int n);

// affichage de la distance entre la ville en question et les autre villes
void affiche_une_ville(int ** g, int n, int num_ville);

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

void affiche_km(Graphe g, int n)
{
	int i, j;
	
	int ville_choisie = 5;

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++) {
			printf("%5d ", g[i][j]);
		}
		printf("\n");
	}		
	printf("\n");
}

void affiche_une_ville(Graphe g, int n, int num_ville)
{
	int i;
	
	for(i = 0; i < n; i++)
	{
		printf("%5d ", g[num_ville][i]);
	}
	printf("\n");
}