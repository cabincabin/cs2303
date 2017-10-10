/*
 * PA5.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: Clayton Dembski and Floris vanRossum
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <climits>
#include <vector>

//Random libraries
#include <cstdlib>

//printing stuff
#include <iostream>
using namespace std;

#include "Grid.h"
#include "Organism.h"
#include "Doodlebug.h"
#include "Ant.h"
void printGrid(Grid* PlayGrid);

int main(){

	Grid* PlayGrid = new Grid(5,5);
	PlayGrid -> BugGrid[1][1] = new Ant(PlayGrid, 1, 1);
	PlayGrid -> BugGrid[1][2] = new Ant(PlayGrid, 1, 2); // This causes 1 prey to appear with GetAllPrey()
	PlayGrid -> BugGrid[1][3] = new Doodlebug(PlayGrid, 1, 3);
	PlayGrid -> BugGrid[2][4] = new Doodlebug(PlayGrid, 2, 4);
	std::vector<Organism*> pred = PlayGrid -> GetAllPred();
	std::vector<Organism*> prey = PlayGrid -> GetAllPrey();
	printGrid(PlayGrid);
	int predsize = pred.size();
	cout << "Number of predators: " << predsize << "\n";

	int preysize = prey.size();
	cout << "Number of prey: " << preysize << "\n";

	while(predsize!=0){
		/*for(int i = 0; i<predsize; i++){
			pred.at(i)->move();
		}*/
		for(int i = 0; i<preysize; i++){
			prey.at(i)->move();
		}
		//prey.clear();
		prey = PlayGrid->GetAllPrey();
		//pred.clear(); //should not delete objects themselves if so, this could cause error
		pred = PlayGrid->GetAllPred();
		printGrid(PlayGrid);
	}

}

void printGrid(Grid* PlayGrid){//copied from game of life, comments not changed
	int i; //rows or array
	int j; //columns of array
	printf("\n");
	//Precondition: the index of the gen array is zero
	for(i = 0; i<PlayGrid->getrow(); i++){

		printf("\n");
		//Precondition: the column of the gen matrix is 0,
		for(j = 0; j<PlayGrid->getcol(); j++){
			if(PlayGrid->BugGrid[i][j] == NULL){//translate 1s to xs
				printf(".");
			}
			else if(PlayGrid->BugGrid[i][j]->isPrey()){//translate  0s to os
				printf("o"); //change this to a dot to see more clearly
			}
			else if(!PlayGrid->BugGrid[i][j]->isPrey()){//translate  0s to os
				printf("x"); //change this to a dot to see more clearly
			}

		}
		//loop invariant: the board will be printed, in xs and os to the screen
	}
	printf("\n");
}
