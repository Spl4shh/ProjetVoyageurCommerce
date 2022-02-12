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


int main(int argc, char const *argv[])
{
      //Variables
      char nom[30];
	Graphe G = NULL;
	int n, m;
	int err;
      //End Variable

      //lecture du fichier
      do{
		printf("saisir le nom de fichier de donnees : ");
		scanf("%s", nom); 
		while(getchar() != '\n');
		err = lire_data(nom, &G, &n, &m);
	}while(err == 0);

      //affichage
      affiche_km(G, n);

      return 0;
}

int lire_data(char * nom, Graphe * g, int *n, int *m){
	char str[15];
	int i, s1, s2, km;
	FILE * f = fopen(nom, "r");
	
	if (f == NULL) return 0; // le fichier n'existe pas
	
	// la première ligne contient le nombre de sommets n et le nombre d'arêtes m
	fgets(str, 15, f);
	sscanf(str, "%d %d", n, m);
	
	// allocation dynamique d'un tableau n x n rempli de 0
	*g = (int **)calloc(sizeof(int *), *n);
	for (i = 0; i < *n; i++) (*g)[i] = (int *)calloc(sizeof(int), *n);

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

void affiche_km(Graphe g, int n){
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

void affiche_une_ville(Graphe g, int n, int num_ville){
	int i;
	
	for(i = 0; i < n; i++)
	{
		printf("%5d ", g[num_ville][i]);
	}
	printf("\n");
}

void recherche_voisin_proche(Graphe g, int n, int num_ville){
	int i;
	int num_voisin_proche = -1;

	for(i = 0; i < n; i++)
	{
		// Permet de s'assurer qu'on ne vas pas boucler sur la ville elle meme
		if (g[num_ville][i] != 0)
		{
			// Si la ville la plus proche n'a pas été définie 
			// ou que la ville selectionné est plus proche que la ville en mémoire,
			// on modif la valeur
			if (num_voisin_proche == -1 || (g[num_ville][i] < g[num_voisin_proche][i]) )
			{
				num_voisin_proche = i;
			}
		}
		printf("Le num de la ville la plus proche est : %d \nA une distance de : %5dkm", num_voisin_proche, g[num_voisin_proche][i]);
	}
}