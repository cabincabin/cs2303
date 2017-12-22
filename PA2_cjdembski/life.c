/**
 *@file life.c
 *@Author Clayton Dembski
 *@date Sep 11, 2017
 * when the program is run with a given x size, y size, generation number,
 *input file, and print/pause condition, it will play conways game of life
 *until an end condition is met: all die, the pattern repeates, the goal number
 *of gens is reached.
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
	//check if inputs valid
	if(argc < 5){
		printf("not enough inputs, must be of size 5 or more\n");
		fflush(stdout);
		exit(0);
	}

	int** arrAPPGen = getArrToAppend(argv[4]);//get life array initialized/filled
	int rFileSize = getArrRow(argv[4]);//get row bound for life array
	int cFileSize = getArrCol(argv[4]);//get col bound fot life array
	int rSize = atoi(argv[2]);//r=y axis
	int cSize = atoi(argv[1]);//c = x axis
	if(rSize < rFileSize || cSize < cFileSize){
		printf("Given x and y size are too small for file r and c\n");
		printf("x and y must be non negitive\n");
		fflush(stdout);
		exit(0);
	}
	int numGen = atoi(argv[3]);//get number of gens to play
	int genComplete = 0;//for the total number of gens played, depends on end cond
	int i; //intexer for multiple forloops
	int r; //row bound of game board
	int c; //column bound of game board
	char print = 'n'; //should each gen be printed?
	char pause = 'n'; //should there be a wait for user keystroke between gen
	int allDead = 0; //is all life on the board dead?
	int repeatGenBA = 0; //does the board repeat immidiatly?
	int repeatGenBC = 0; //does the board repeat after 1 gen?


	if(argc>=7){
		if (strcmp(argv[5],"y") == 0)
			print = 'y';
		if (strcmp(argv[6],"y") == 0)
			pause = 'y';
	}

	int** genA = (int **)malloc(rSize*sizeof(int *));//gameboard1, starting board
		//preecondition: genA is a 2d array allocated to store arrays of pointers
											//in each row.
	if (genA) for (i=0; i<rSize; i++){
		genA[i] = (int*)malloc(cSize * sizeof(int));
		if (!genA[i]) exit(-1);
	}//loopInvariant: genA will be a 2d array of pointers.

	int** genB = (int **)malloc(rSize*sizeof(int *));//gameboard2, updates gen
	//preecondition: genB is a 2d array allocated to store arrays of pointers
									//in each row.
		if (genB) for (i=0; i<rSize; i++){
			genB[i] = (int*)malloc(cSize * sizeof(int));
			if (!genB[i]) exit(-1);
	}//loopInvariant: genB will be a 2d array of pointers.
	int** genC = (int **)malloc(rSize*sizeof(int *));//gameboard 3, temp, store
																									//old array.
	//preecondition: genC is a 2d array allocated to store arrays of pointers
									//in each row.
		if (genC) for (i=0; i<rSize; i++){
			genC[i] = (int *)malloc(cSize * sizeof(int));
			if (!genC[i]) exit(-1);
		}//loopInvariant: genC will be a 2d array of pointers.

//precondition: all three boards are empty
		for(r=0;r<rSize;r++){
			for(c=0;c<cSize;c++){
				genA[r][c]=0;
				genB[r][c]=0;
				genC[r][c]=0;
			}
		}
//loop invariant all three boards are filled with 0s

   centerFile(genA, rSize, cSize, arrAPPGen, rFileSize, cFileSize);

	 //play the game
	 //*******************************************************//
//precondition: the gameboard is initialized with the life file
	for(r=0;r<rSize;r++){
		for(c=0;c<cSize;c++){
				allDead = allDead + genA[r][c];
				//loop invariant: any gameboard initialized with proper life
													//will not be dead, generations will be allowed.
		}
	}

	printf("\n Conway's Game Of Life \n");

	printf("\n Generation 0\n");
	printLifeArray(rSize, cSize, genA);

	if(pause == 'y'  && !(allDead == 0)){
		getchar();
	}
//precondition: the gameboard is initialized properly with life
	for(i=0;i<numGen && !(allDead == 0) && !(repeatGenBA>=rSize*cSize)&&
			!(repeatGenBC>=rSize*cSize);i++){
//loop invariant: genA is the current Generation genB will be
									//the next Generation, genC is the past generation
		repeatGenBA = 0;
		repeatGenBC = 0;
		allDead = 0;
		genComplete++;

		nextgen(rSize, cSize, genA, genB);
		if(print == 'y'){
			printf("\n Generation %d\n", genComplete);
			printLifeArray(rSize, cSize, genB);

		}
//loopInvariant, precondition: genA is the past generation,
//genB is the current generation genC is the very past generation
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
//loopInvariant: the death and repitition of the gameboard can be checked
		}

		//printf("%d", repeatGenBA);
		if(pause == 'y' && i+1<numGen && !(allDead == 0) && !(repeatGenBA>=rSize*cSize)&&
				!(repeatGenBC>=rSize*cSize))
			getchar();

	}
	//show the end status of the boardgame.
	 //*******************************************************//
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
	int r;//scroll through rows
	int c;//scroll through columns
	int jIndex=0;//row indexer for relitive position neigbor getter
	int kIndex=0; //the column indexer for relitive position neigbor getter
	int nghbrs=0;//the number of neighbors for a given geeration array location
//Precondition: the index of both generation arrays are at the first index
	for(r = 0; r < rSize; r++){
		//Precondition: both generation arrays are at the first col index
		for(c = 0; c < cSize; c++){

			nghbrs = 0;
			if(r-1 < 0){
				jIndex = r;
			}
			else{
				jIndex = r-1;
			}
			//precondition: there are no neighbors and the index of the
											//neighborsearch is set relitive to the location of the
											//current position and bounded by the gameboard
			for(; jIndex < rSize && jIndex<=r+1; jIndex++){
				//sroll through all neighbors (and diagnols) to the current pos
				if(c-1 < 0){
					kIndex = c;
				}
				else{
					kIndex = c-1;
				}
				//precondition: there are no neighbors and the index of the relitive
												//column is bounded by the gameboard and current pos
				for(; kIndex < cSize && kIndex<=c+1; kIndex++){

					if(!(jIndex==r && kIndex == c) && genA[jIndex][kIndex]==1){
						nghbrs++;
						//loopInvariant: the number of neigbors for a given point rc
														//is found
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
			//loop invariant: the new generation is updated for a given point based
												//bosed on its neighbors
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
		int rDisp = (rSize-rFileSize)/2; //row displacement of the life array
		//on the board
		int cDisp = (cSize-cFileSize)/2;//column displacement of the life array
		//on the board
		int r=0; //row incrementer
		int c=0; //column incrementer
		//Precondition: the index of the life array is zero
		for(r=0;r<rFileSize;r++){
			//loop Invariant: will go through every item in the life array
			//loop Invaraint: ends at last index of life array
			//Precondition: the column of the life matrix is 0, to be projected onto
											//onto the board
			for(c=0;c<cFileSize-1;c++){
				//loop Invariant: the array will be appended to the center, alligned
													//alligned left of the game board
				//loop invariant: starts at the upper left hand corner of the array with
				 									//offset for cenetring
				//loop invariant: starts at the lower right hand corner of the array
				genA[r+rDisp][c+cDisp]=genAppend[r][c];
			}//
		}
}

///////////////////////////////////////////////////////////////
/*prints out the life array as given, translating 0s to os and 1s to xs
*@param rSize, the row size of the array passed
*@param cSize, the column size of the array passed
*@param gen, the generation array to be printed on the screen
*/
void printLifeArray(int rSize, int cSize,int **gen){
	int i; //rows or array
	int j; //columns of array
	printf("\n");
	//Precondition: the index of the gen array is zero
	for(i = 0; i<rSize; i++){

		printf("\n");
		//Precondition: the column of the gen matrix is 0,
		for(j = 0; j<cSize; j++){
			if(gen[i][j] == 1){//translate 1s to xs
				printf("x");
			}
			else if(gen[i][j] == 0){//translate  0s to os
				printf("."); //change this to a dot to see more clearly
			}

		}
		//loop invariant: the board will be printed, in xs and os to the screen
	}
	printf("\n");
}

/**@source Assignment2--GemaOfLife.docx
*@source  https://stackoverflow.com/questions/7109964/creating-your-own-header-file-in-c
*@source  https://stackoverflow.com/questions/3463426/in-c-how-should-i-read-a-text-file-and-print-all-strings
*@source  https://www.tutorialspoint.com/c_standard_library/c_function_fgetc.htm
*@source 	https://commandline.codeplex.com/
*@source	https://stackoverflow.com/questions/8004237/how-do-i-properly-compare-strings
*@source	https://stackoverflow.com/questions/18801483/press-any-key-to-continue-function-in-c
*@source http://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
*@source http://publications.gbdirect.co.uk/c_book/chapter5/sizeof_and_malloc.html
*/
