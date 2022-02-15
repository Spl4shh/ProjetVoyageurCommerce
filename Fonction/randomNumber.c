#ifndef RANDOMNUMBER_C
#define RANDOMNUMBER_C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Retourne un nombre aléatoire
int randomNumber(int borneBasse, int borneHaute){
    return (borneBasse + rand() % (borneHaute + 1 - borneBasse));
}

#endif