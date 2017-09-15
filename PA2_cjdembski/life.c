/*
 * life.c
 *
 *  Created on: Sep 11, 2017
 *      Author: Clayton Dembski
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void nextgen(int rSize, int cSize, int **genA, int **genB);
void printLifeArray(int rSize, int cSize,int **gen);

int main(){
	int rSize = 3;
	int cSize = 3;
	int i;

	int** genA = (int **)malloc(rSize*sizeof(int *));
	if (genA) for (i=0; i<rSize; i++){
		genA[i] = (int*)malloc(cSize * sizeof(int));
		if (!genA[i]) exit(-1);
	}
	int** genB = (int **)malloc(rSize*sizeof(int *));
		if (genB) for (i=0; i<rSize; i++){
			genB[i] = (int*)malloc(cSize * sizeof(int));
			if (!genB[i]) exit(-1);
	}
	int** genC = (int **)malloc(rSize*sizeof(int *));
		if (genC) for (i=0; i<rSize; i++){
			genC[i] = (int *)malloc(cSize * sizeof(int));
			if (!genC[i]) exit(-1);
		}

	genA[0][0]=1;
	genA[1][0]=1;
	genA[2][0]=1;
	genA[0][1]=1;
	genA[1][1]=1;
	genA[2][1]=1;
	genA[0][2]=1;
	genA[1][2]=1;
	genA[2][2]=1;

	nextgen(rSize, cSize, genA, genB);
	printLifeArray(rSize, cSize,genB);
	free(genA);
	free(genB);
	free(genC);
 	return 0;
}

/////////////////////////////////////////////////////////////////

void nextgen(int rSize, int cSize, int ** genA, int ** genB){
	int r;
	int c;
	int jIndex=0;
	int kIndex=0;
	int nghbrs=0;

	for(r = 0; r < rSize; r++){

		for(c = 0; c < cSize; c++){
			nghbrs = 0;
			if(r-1 < 0){
				jIndex = r;
			}
			else{
				jIndex = r-1;
			}

			for(; jIndex < rSize && jIndex<=r+1; jIndex++){
				if(c-1 < 0){
					kIndex = c;
				}
				else{
					kIndex = c-1;
				}
				for(; kIndex < cSize && kIndex<=c+1; kIndex++){
					if(!(jIndex==r && kIndex == c) && genA[jIndex][kIndex]==1){
						nghbrs++;
					}
				}
			}
			fflush(stdout);
			if(genA[r][c] == 1){
				if(!(nghbrs == 2 || nghbrs == 3)){
					genB[r][c] = 0;
				}
				else
					genB[r][c] = 1;
			}
			else if(genA[r][c] == 0){
				if(nghbrs == 3)
					genB[r][c] = 1;
			}
			printf("%d\n", nghbrs);
			//printLifeArray(rSize, cSize, genB);
			fflush(stdout);
		}
	}
}

void printLifeArray(int rSize, int cSize,int **gen){
	int i;
	int j;
	printf("\n");
	for(i = 0; i<3; i++){
		printf("\n");
		for(j = 0; j<3; j++)
			printf("%d", gen[i][j]);
	}
	printf("\n");

}
