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
void centerFile(int **genA, int rSize, int cSize, int **genAppend,
	int rFileSize, int cFileSize);

///////////////////////////////////////////////////////////////
/** prints out the game of life for a given file and generation count
*@param argc the size of the input values, if less than five
				an error should be thrown.
				if 7, pause and play parameters are allowed
*@param char *argv[5 or 7] is an array holding
				@param x, the number of columns for the playing board
				@param y, the number of rows for the playing board
				@param gens, the number of generations to play if no end state hit
				@param input, the file to place in the center of the playing board
				@param print, whether the intermediate generations should be played
											from the first gen to the end condition (y/n)
				@param pause, if a key stroke should be pressed to advance gens(y/n)
*/
int main(int argc, char *argv[]){
	//initialize everything
	//*******************************************************//
	if(argc < 5){
		printf("not enough inputs, must be of size 5 or more\n");
		fflush(stdout);
		exit(0);
	}

	int** arrAPPGen = getArrToAppend(argv[4]);
	int rFileSize = getArrRow(argv[4]);
	int cFileSize = getArrCol(argv[4]);
	int rSize = atoi(argv[2]);//r=y axis
	int cSize = atoi(argv[1]);//c = x axis
	if(rSize < rFileSize || cSize < cFileSize){
		printf("Given r and c size is too small for file r and c\n");
		fflush(stdout);
		exit(0);
	}
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

	if(argc>=7){
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



   centerFile(genA, rSize, cSize, arrAPPGen, rFileSize, cFileSize);
	 //play the game
	 //*******************************************************//

	for(r=0;r<rSize;r++){
		for(c=0;c<cSize;c++){
				allDead = allDead + genA[r][c];
		}
	}

	printf("\n Conway's Game Of Life \n");

	printf("\n Generation 0\n");
	printLifeArray(rSize, cSize, genA);

	if(pause == 'y'  && !(allDead == 0)){
		getchar();
	}

	for(i=0;i<numGen && !(allDead == 0) && !(repeatGenBA>=rSize*cSize)&&
			!(repeatGenBC>=rSize*cSize);i++){

		repeatGenBA = 0;
		repeatGenBC = 0;
		allDead = 0;
		genComplete++;

		nextgen(rSize, cSize, genA, genB);
		if(print == 'y'){
			printf("\n Generation %d\n", genComplete);
			printLifeArray(rSize, cSize, genB);

		}

		for(r=0;r<rSize;r++){
			for(c=0;c<cSize;c++){
				if(genA[r][c]==genB[r][c]){
					repeatGenBA++;
				}
				if(genB[r][c]==genC[r][c]){
					repeatGenBC++;
				}
				allDead = allDead + genB[r][c];
				genC[r][c]=genA[r][c];
				genA[r][c]=genB[r][c];
			}
		}

		//printf("%d", repeatGenBA);
		if(pause == 'y' && i+1<numGen && !(allDead == 0) && !(repeatGenBA>=rSize*cSize)&&
				!(repeatGenBC>=rSize*cSize))
			getchar();

	}
	if(print == 'n'){
		printf("\n Generation %d\n", genComplete);
		printLifeArray(rSize, cSize, genB);
	}
	if(allDead == 0){
		printf("\nReason for termination: Death\n");
	}
	if(repeatGenBA>=rSize*cSize||repeatGenBC>=rSize*cSize){
		printf("\nReason for termination: Steady State\n");
	}
	if(genComplete == numGen){
		printf("\nReason for termination: End of Generations\n");
	}
	printf("\nGenerations complete:  %d\n\n", genComplete);
	fflush(stdout);
	free(genA);
	free(genB);
	free(genC);
 	return 0;
}

/////////////////////////////////////////////////////////////////

/**generates the next generation of life from the given gen
@param rSize, the row size of the array
@param cSize, the column size of the array
@param genA,  the current generation
@param genB, the array where whe next generation should be produced into
*/
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

		}
	}
}

///////////////////////////////////////////////////////////////

/**places a life set onto the approxamate center of a play board,
	 if the life array does not go into the board evenly, it is placced at the
	 left apprxamation
*@param genA the empty playboard, must be larger than the life array
*@param rSize, the row size of the playerboard
*@param cSize, the column size of the playerboard
*@param genAppend the life array to be cented on the board.
*@param rFileSize, the row size of the playerboard
*@param cFileSize, the column size of the playerboard
*/
void centerFile(int **genA, int rSize, int cSize, int **genAppend,
	int rFileSize, int cFileSize){
		int rDisp = (rSize-rFileSize)/2;
		int cDisp = (cSize-cFileSize)/2;
		int r=0;
		int c=0;
		for(r=0;r<rFileSize;r++){
			for(c=0;c<cFileSize-1;c++){
				genA[r+rDisp][c+cDisp]=genAppend[r][c];
			}
		}
}

///////////////////////////////////////////////////////////////
/*prints out the life array as given, translating 0s to os and 1s to xs
*@param rSize, the row size of the array passed
*@param cSize, the column size of the array passed
*@param gen, the generation array to be printed on the screen
*/
void printLifeArray(int rSize, int cSize,int **gen){
	int i;
	int j;
	printf("\n");
	for(i = 0; i<rSize; i++){
		printf("\n");
		for(j = 0; j<cSize; j++){
			if(gen[i][j] == 1){
				printf("x");
			}
			else if(gen[i][j] == 0){
				printf("o"); //change this to a dot to see more clearly
			}
		}
	}
	printf("\n");
}
