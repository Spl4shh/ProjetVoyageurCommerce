#ifndef FORCEBRUTE_C
    #define FORCEBRUTE_C

    #include "forceBrute.h"

    int brutePermut(int a[], int len){
        // Find non-increasing suffix
        if (len == 0) {
            return 0;
        }
        int i = len - 1;

        while (i > 0 && a[i - 1] >= a[i]){
            i--;
        }
        if (i == 0){
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

    void quicksort(int a[], int start, int end){
        int i, j, pivot, temp;

        if (start < end ) {
            pivot = start;
            i = start ;
            j = end;

            while( i < j ) {
                while(a[i] <= a[pivot] && i < end) {
                    i++;
                }

                while( a[j] > a[pivot]){
                    j--;
                }

                if( i < j ){
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

    void bruteForce(Graphe G, int n, int ordre_ville[]){
        int chemin_test[n];
        for (int i = 0; i < n; i++){
            ordre_ville[i] = i;
        }
        copieTable(chemin_test, ordre_ville, n);
        int fact = 1;
        
        for (int j = 1; j <= n; j++){
            fact = fact * j;
        }
    
        for (int i = 0; i < fact; i++){
            brutePermut(chemin_test, n);

            if (getPoidsTotal(G, n, ordre_ville) > getPoidsTotal(G, n, chemin_test)){
                copieTable(ordre_ville, chemin_test, n);
            }
        }
    }

#endif