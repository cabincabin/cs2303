/*
 * life.c
 *
 *  Created on: Sep 11, 2017
 *      Author: Clayton Dembski
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "readFile.h"

void nextgen(int rSize, int cSize, int **genA, int **genB);
void printLifeArray(int rSize, int cSize,int **gen);

int main(int argc, char *argv[]){
	if(argc < 5){
		printf("Input is too small, must be of size 5 or more\n");
		fflush(stdout);
		exit(-0);
	}

	int** arrAPPGen = getArrToAppend(argv[4]);
	printLifeArray(4, 3, arrAPPGen);
	int rSize = atoi(argv[2]);
	int cSize = atoi(argv[1]);
	int numGen = atoi(argv[3]);
	int genComplete = 0;
	int i;
	int r;
	int c;
	char print = 'n';
	char pause = 'n';
	int allDead = 0;
	int repeatGenBA = 0;
	int repeatGenBC = 0;

	if(argc<=7){
		if (strcmp(argv[5],"y") == 0)
			print = 'y';
		if (strcmp(argv[6],"y") == 0)
			pause = 'y';
	}

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


		for(r=0;r<rSize;r++){
			for(c=0;c<cSize;c++){
				genA[r][c]=0;
				genB[r][c]=0;
				genC[r][c]=0;
			}
		}

	genA[0][0]=0;
	genA[1][0]=1;
	genA[2][0]=1;
	genA[0][1]=1;
	genA[1][1]=1;
	genA[2][1]=0;
	genA[0][2]=0;
	genA[1][2]=1;
	genA[2][2]=0;

	for(r=0;r<rSize;r++){
		for(c=0;c<cSize;c++){
				allDead = allDead + genA[r][c];
		}
	}

	printLifeArray(rSize, cSize, genA);
	if(pause == 'y'  && !(allDead == 0)){
		getchar();
	}

	for(i=0;i<numGen && !(allDead == 0) && !(repeatGenBA>=rSize*cSize)&&
			!(repeatGenBC>=rSize*cSize);i++){
		repeatGenBA = 0;
		repeatGenBC = 0;
		allDead = 0;

		nextgen(rSize, cSize, genA, genB);
		if(print == 'y')
			printLifeArray(rSize, cSize, genB);

		for(r=0;r<rSize;r++){
			for(c=0;c<cSize;c++){
				if(genB[r][c]==genA[r][c])
					repeatGenBA++;
				if(genB[r][c]==genC[r][c])
					repeatGenBC++;
				allDead = allDead + genB[r][c];
				genC[r][c]=genA[r][c];
				genA[r][c]=genB[r][c];
			}
		}
		if(pause == 'y' && i+1<numGen && !(allDead == 0) && !(repeatGenBA>=rSize*cSize)&&
				!(repeatGenBC>=rSize*cSize))
			getchar();
	genComplete++;
	}
	if(print == 'n')
		printLifeArray(rSize, cSize, genB);
	printf("%d\n", genComplete);
	fflush(stdout);
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
			if(genA[r][c] == 1){
				if(!(nghbrs == 2 || nghbrs == 3)){
					genB[r][c] = 0;
				}
				else
					genB[r][c] = 1;
			}
			else if(genA[r][c] == 0){
				if(nghbrs == 3){
					genB[r][c] = 1;
				}
				else{
					genB[r][c] = 0;
				}
			}
			//printf("%d\n", nghbrs);
			//printLifeArray(rSize, cSize, genB);

		}
	}
}

void printLifeArray(int rSize, int cSize,int **gen){
	int i;
	int j;
	printf("\n");
	for(i = 0; i<3; i++){
		printf("\n");
		for(j = 0; j<3; j++){
			if(gen[i][j] == 1){
				printf("x");
			}
			else{
				printf("o");
			}
		}
	}
	printf("\n");
}
