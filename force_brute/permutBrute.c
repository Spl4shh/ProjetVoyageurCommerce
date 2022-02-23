#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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

void quicksort( int a[], int start, int end ) {

    int i, j, pivot, temp;

    if (start < end ) {

        pivot = start;

        i = start ;

        j = end;

        while( i < j ) {

            while(a[i] <= a[pivot] && i < end) {

                i++;
            }

            while( a[j] > a[pivot]) {

                j--;
            }

            if( i < j ) {

                temp = a[i];

                a[i] = a[j];

                a[j] = temp;

            }

        }

        temp = a[pivot];

        a[pivot] = a[j];

        a[j] = temp;

        quicksort(a,start,j-1);

        quicksort(a,j+1,end);

    }

}

/*
void brutePermut( int a[], int len ) {

    quicksort(a, 0, len - 1);

    printf("Permutations possible sont : \n");

    do {
        for ( int i = 0; i < len; i ++ ) {
            printf("%d ", a[i]);
        }
        printf("\n");
    } while ( prochainePermut(a, len));
}
*/

void brutePermut( int a[], int len ) {
   
   
   /*
    if ( prochainePermut(a, len)) {
        for ( int i = 0; i < len; i ++ ) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    */
    
    prochainePermut(a, len);
}

/*
int main() {

   int tab[] = {1,2,3,4};
   int len = sizeof(tab) / sizeof(tab[0]);
   int i;
   
   quicksort(tab, 0, len - 1);
   
   int fact = 1;
   for (i = 1; i <= len; i++) {
      fact = fact * i;
   }
   
   for ( i = 0; i < fact; i++ ) {
   
      brutePermut(tab, len);
      
   }

}
*/