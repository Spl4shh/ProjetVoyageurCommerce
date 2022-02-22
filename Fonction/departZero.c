#include<stdio.h>
#include<stdlib.h>

void demarrerZero(int *table, int n, int r){

    int save;
    int c = 0;

    while(table[0] != r && c < n){
        c++;
        printf("debug\n");

        save=table[0];  //on stock la donnée qui va être écrasée dans une variable
            for(int i = 0; i < n; i++){
                table[i] = table[i+1];
            }

        table[n-1] = save;  //on ressort la donnée precedemment écrasée

    }

    if (c >= n){
        printf("La valeur recherchée n'a pas été trouvée");
    }
    
}