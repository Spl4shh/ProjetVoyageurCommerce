#include <stdio.h>
#include <stdlib.h>

#include "../Programme_Fourni/graphe.h"
#include "../Programme_Fourni/affichage.c"
#include "../Programme_Fourni/lectureFichier.c"

// recherche la ville la plus proche de la ville "num_ville"
int recherche_voisin_proche(Graphe g, int n, int num_ville, int liste_ville[]);


int main(int argc, char const *argv[])
{
      //Variables
      char nom[30];
	Graphe G = NULL;
	int n, m;
	int err;
	int ville_actuelle = 0, ville_suivante;
      //End Variable

      //lecture du fichier
      do{
		printf("saisir le nom de fichier de donnees : ");
		scanf("%s", nom); 
		while(getchar() != '\n');
		err = lire_data(nom, &G, &n, &m);
	}while(err == 0);

	int liste_ville[n];
	liste_ville[ville_actuelle] = 1;

      //affichage
      affiche_km(G, n);


	printf("ville ou je suis : %d\n", ville_actuelle);
	for(int i = 0; i < n; i++)
	{
		ville_suivante = recherche_voisin_proche(G, n, ville_actuelle, liste_ville);
		if (ville_suivante != -1)
		{
			ville_actuelle = ville_suivante;
			liste_ville[ville_actuelle] = 1;
			printf("ville ou je suis : %d\n", ville_actuelle);
		}
		
	}
      return 0;
}

int recherche_voisin_proche(Graphe g, int n, int num_ville, int liste_ville[]){
	int i;
	int num_voisin_proche = -1;

	for(i = 0; i < n; i++)
	{
		// Permet de s'assurer qu'on ne vas pas boucler sur la ville elle meme
		if (g[num_ville][i] != 0 && liste_ville[i] != 1)
		{
			// Si la ville la plus proche n'a pas été définie 
			// ou que la ville selectionné est plus proche que la ville en mémoire,
			// on modif la valeur
			if (num_voisin_proche == -1 || (g[num_ville][i] < g[num_ville][num_voisin_proche]) )
			{
				num_voisin_proche = i;
			}
		}
	}
	return num_voisin_proche;
}