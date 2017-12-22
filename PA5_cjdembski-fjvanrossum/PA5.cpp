/*
 * PA5.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: Clayton Dembski and Floris van Rossum
 */
/*****************************************************************************/
// Include Statements
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

/*****************************************************************************/
/** void printGrid(Grid* PlayGrid)
 * Purpose: Print out the grid
 * @param Grid* PlayGrid The playing grid that is to be printed
 * @return void
 */
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

/*****************************************************************************/
/** int main(int argc, char *argv[])
 * Purpose: Start and main loop of the program
 * @param int argc The number of command line arguments entered
 * @param int *argv[] Pointer to an array of strings of the arguments entered in
 * the command line
 * @return void
 */
int main(int argc, char *argv[]){
	// Command line argument:
	// ./PA5 gridSize #doodlebugs #ants #time_steps seed pause

	// CLEAR THESE LATER
	// Declaring variables for storing command line input
	int gridsize = 20;
	int numDood = 5;
	int numAnt = 100;
	int timeSteps = 1000;
	int seed = 1;
	int pauses = 0;

	// Parsing and storing the command line arguments based
	// on number of arguments entered by the user
	if(argc >= 2)
		gridsize = atoi(argv[1]);
	if(argc >= 3)
		numDood = atoi(argv[2]);
	if(argc >= 4)
		numAnt = atoi(argv[3]);
	if(argc >= 5)
		timeSteps = atoi(argv[4]);
	if(argc >=6)
		seed = atoi(argv[5]);
	if(argc >=7)
		pauses = atoi(argv[6]);

	// Determine if there are too many doodlebugs specified
	if(gridsize*gridsize < numAnt+numDood){
		cout<<"ERROR: TOO MANY BUGS"<<endl;
		exit(-1);
	}

	// Set up a random seed with user specified seed
	srand(seed);

	// Initialize the grid
	Grid* PlayGrid = new Grid(gridsize,gridsize);

	// Add user specified number of doodle bugs to the grid in random locations
	for(int i = 0; i < numDood; i++){
		// Generate a random row and column
		int rowOrg = rand()%gridsize;
		int colOrg = rand()%gridsize;
		// Check if the row and columns are empty, otherwise keep generating new
		// rows and columns
		while(PlayGrid->BugGrid[rowOrg][colOrg]!=NULL){
				rowOrg = rand()%gridsize;
				colOrg = rand()%gridsize;
		}
		// Instantiate a doodlebug object with random location and add it to the grid
		(new Doodlebug(PlayGrid, rowOrg, colOrg))->AddSelfToGrid();
	}

	// Add user specified number of ants to random locations on the grid
	for(int i = 0; i < numAnt; i++){
		// Generate a random row and column location
		int rowOrg = rand()%gridsize;
		int colOrg = rand()%gridsize;
		// Check if the row and column location is empty, otherwise
		// keep generating new rows and columns
		while(PlayGrid->BugGrid[rowOrg][colOrg]!=NULL){
				rowOrg = rand()%gridsize;
				colOrg = rand()%gridsize;
		}
		// Instantiate an Ant object with a random location and add it to the grid
		(new Ant(PlayGrid, rowOrg, colOrg))->AddSelfToGrid();
	}

	// Create two vectors of all predators and prey
	std::vector<Organism*> pred = PlayGrid -> GetAllPred();
	std::vector<Organism*> prey = PlayGrid -> GetAllPrey();

	// Print the grid
	cout << "Initial Grid:";
	printGrid(PlayGrid);

	// Set-up variables equal to the number of predators and prey
	int predsize = pred.size();
	int preysize = prey.size();
	int tstep = 0;
	int pauseLoop = 0;


	// Main loop:
	// Runs until there are no more predators or prey or if the number of time
	// steps is greater than the user specified number of time steps
	while(predsize > 0 && preysize > 0 && tstep < timeSteps){
		// Conditional statement that determines whether to pause in between
		// grid print outs
		if(pauses != 0){
			// This statement ensures that we do not print on the first pause loop
			if(pauseLoop % pauses == 0 && pauseLoop != 0){
				getchar(); // Wait for user input
				cout << "Grid: " << tstep << endl;
				printGrid(PlayGrid);
			}
			pauseLoop++;
		}

		// Move each predator
		for(int i = 0; i < predsize; i++){
			pred.at(i) -> move();
		}

		// Update the number of prey
		prey = PlayGrid -> GetAllPrey();
		preysize = prey.size();

		// Move each prey
		for(int i = 0; i < preysize; i++){
			prey.at(i) -> move();
		}

		// Clear the used organism vectors
		// should not delete objects themselves if so, this could cause error
		prey.clear();
		pred.clear();

		// Update the predator vector
		pred = PlayGrid -> GetAllPred();
		predsize = pred.size();
		tstep++;
	}

	cout << endl << "Final Grid:";
	// Do not print out the playing field on the first run through
	if(tstep != 0)
		printGrid(PlayGrid);

	// Print out the statistics of the run
	cout << endl << endl << "Gridsize: " << gridsize << " #doodlebugs: " << numDood <<
			" #ants: " << numAnt << " #time_steps: " << timeSteps <<
			" seed: " << seed << " pause: " << pauses << endl;
	cout << "Total Number of Steps Performed: " << tstep << endl;
	cout << "Net Number of Ants On Board: " << PlayGrid -> getTotAnts() << endl;
	cout << "Net Number of DoodleBugs On Board: " << PlayGrid -> getTotDoods() << endl;
	cout << "Current Number Of Ants On Board: " << (PlayGrid -> GetAllPrey()).size() << endl;
	cout << "Current Number Of DoodleBugs On Board: " << predsize << endl;
	delete PlayGrid;
}


