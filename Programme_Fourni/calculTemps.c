#include<stdio.h>
#include<time.h>

void getTempsEcoule(clock_t t1){
	clock_t t2 = clock();
	double cpu_boucle;
	
	cpu_boucle = (double)(t2-t1)/(double)(CLOCKS_PER_SEC);
	
	/* DEBUG
		printf("Temps entre T1 et T2 : %f secondes\n", cpu_boucle);
	*/

	return cpu_boucle;
}