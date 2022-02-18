#ifndef TABLE_C
#define TABLE_C

#include <stdio.h>
#include <stdlib.h>

// Copie le tableau B dans le tableau A, de taille size
void copieTable(int a[], int b[], int size){
    for (int i = 0; i < size; i++){
        a[i] = b[i];
    }
}

#endif