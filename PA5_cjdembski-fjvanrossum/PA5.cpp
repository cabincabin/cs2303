/*
 * PA5.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: Clayton Dembski and Floris van Rossum
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

int main(int argc, char *argv[]){
int gridsize = 20;
int numDood = 5;
int numAnt = 100;
int timeSteps = 1000;
int seed = 1;
int pauses = 0;
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

	if(argc >=7){
		pauses = atoi(argv[6]);
	}

	if(gridsize*gridsize < numAnt+numDood){
		cout<<"ERROR: TOO MANY BUGS"<<endl;
		exit(0);
	}

	srand(seed);



	Grid* PlayGrid = new Grid(gridsize,gridsize);
	for(int i = 0; i < numDood; i++){
		int rowOrg = rand()%gridsize;
		int colOrg = rand()%gridsize;
		while(PlayGrid->BugGrid[rowOrg][colOrg]!=NULL){
				rowOrg = rand()%gridsize;
				colOrg = rand()%gridsize;
		}
		(new Doodlebug(PlayGrid, rowOrg, colOrg))->AddSelfToGrid();
	}
	for(int i = 0; i < numAnt; i++){
		int rowOrg = rand()%gridsize;
		int colOrg = rand()%gridsize;
		while(PlayGrid->BugGrid[rowOrg][colOrg]!=NULL){
				rowOrg = rand()%gridsize;
				colOrg = rand()%gridsize;
		}
		(new Ant(PlayGrid, rowOrg, colOrg))->AddSelfToGrid();
	}

	std::vector<Organism*> pred = PlayGrid -> GetAllPred();
	std::vector<Organism*> prey = PlayGrid -> GetAllPrey();
	printGrid(PlayGrid);
	int predsize = pred.size();

	int preysize = prey.size();
	int tstep = 0;
	int pauseLoop = 0;
	while(predsize > 0 && preysize > 0 && tstep < timeSteps){
		if(pauses!=0){
			if(pauseLoop%pauses==0 && pauseLoop!=0){//don't print on first time through
				getchar();
				printGrid(PlayGrid);
			}
			pauseLoop++;
		}
		for(int i = 0; i<predsize; i++){
			pred.at(i)->move();
		}
		prey = PlayGrid->GetAllPrey();
		preysize = prey.size();
		for(int i = 0; i<preysize; i++){
			prey.at(i)->move();
		}
		prey.clear();

		pred.clear(); //should not delete objects themselves if so, this could cause error
		pred = PlayGrid->GetAllPred();
		predsize = pred.size();
		tstep++;
	}
	if(tstep!=0)
	printGrid(PlayGrid);
	cout<<"Gridsize: "<<gridsize<<" #doodlebugs: "<<numDood<<
			" #ants: "<<numAnt<<" #time_steps: "<< timeSteps<<
			" seed: "<<seed<<" pause: "<<pauses<<endl;
	cout<<"Total Number of Steps Performed: "<<tstep<<endl;
	cout<<"Net Number of Ants On Board: "<<PlayGrid->getTotAnts()<<endl;
	cout<<"Net Number of DoodleBugs On Board: "<<PlayGrid->getTotDoods()<<endl;
	cout<<"Current Number Of Ants On Board: "<<(PlayGrid -> GetAllPrey()).size()<<endl;
	cout<<"Current Number Of DoodleBugs On Board: "<<predsize<<endl;
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
