#ifndef PERMUTBRUTE_C
      #define PERMUTBRUTE_C

    #include "permutBrute.h"

int prochainePermut(int a[], int len) {

    // Find non-increasing suffix
    if (len == 0) {
        return 0;
    }
    int i = len - 1;
    while (i > 0 && a[i - 1] >= a[i]) {
        i--;
    }
    if (i == 0) {
        return 0;
    }
    
    // Find successor to pivot
    int j = len - 1;
    
    while (a[j] <= a[i - 1]) {
        j--;
    }
    
    // Swap i-1 and j
    int temp = a[i - 1];
    a[i - 1] = a[j];
    a[j] = temp;
    
    // Reverse suffix
    j = len - 1;
    while (i < j) {
    
        // Swap i and j
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
    return 1;
}

void bruteForce(Graphe G, int n, int ordre_ville[], clock_t timer, int TIMER_LIMIT) {

    int chemin_test[n];
    copieTable(chemin_test, ordre_ville, n);
    
      while ( prochainePermut(chemin_test, n) && ( getTempsEcoule(timer) < TIMER_LIMIT ) ) {
         if (getPoidsTotal(G, n, ordre_ville) > getPoidsTotal(G, n, chemin_test)) {
				   copieTable(ordre_ville, chemin_test, n);
            }
      }
      
}

/*
int main() {

   int tab[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
   int len = sizeof(tab) / sizeof(tab[0]);
   int i,j;
   
   while ( prochainePermut(tab, len)) {}
   
   for ( i = 0; i < len; i++ ) {
   
      printf("%d ", tab[i]);
   
   } printf("\n");
}
*/

#endif
