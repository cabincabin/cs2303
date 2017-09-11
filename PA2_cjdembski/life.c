/*
 * life.c
 *
 *  Created on: Sep 11, 2017
 *      Author: Clayton Dembski
 */

int main(){
	char genA;
	char genB;
	char genC;

	while(1){
		nextGen(sizeOf(genA)/sizeOf(genA[1]), sizeOf(genA[1])/sizeOf(genA[1][1]), genA, genB);
		genC = genA;
		genA = genB;
		genB = genC;
	}

return 0;
}

/*************************************************************/

void nextgen(int rSize, int cSize, char genA[][], char genB[][]){
	int r;
	int c;
	int jIndex;
	int kIndex;
	char nghbrs;

	for(r = 0; r < rSize; r++){
		nghbrs = 0;
		for(c = 0; c < cSize; c++){
			if(r-1 < 0){
				jIndex = r;
			}
			else{
				jIndex = r-1;
			}

			for(; jIndex < rSize || jIndex<=r+1; jIndex++){
				if(c-1 < 0){
					kIndex = r;
				}
				else{
					kIndex = r-1;
				}
				for(; kIndex < cSize || kIndex<=r+1; kIndex++){
					if(genA[jIndex][kIndex]==0)
						nghbrs++;
				}
			}

			if(genA[r][c] == 1){
				if(!(nghbrs == 2 || nghbrs ==3))
					genB[r][c] = 0;
			}
			else{
				if(nghbrs == 3)
					genB[r][c] = 1;
			}
		}
	}
}

void printLifeArray(char gen[][]){


}
