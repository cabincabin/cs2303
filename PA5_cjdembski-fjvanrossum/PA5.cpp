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

int main(){

	Grid* PlayGrid = new Grid(5,5);
	PlayGrid -> BugGrid[1][1] = new Ant(PlayGrid, 1, 1);
	PlayGrid -> BugGrid[1][2] = new Ant(PlayGrid, 1, 2); // This causes 1 prey to appear with GetAllPrey()

	delete PlayGrid -> BugGrid[1][1];

	PlayGrid -> BugGrid[1][1] = NULL;
	bool bool1 = true;

	if(PlayGrid -> BugGrid[1][1] == NULL){
		bool1 = false;
	}
	else{
		bool1 = true;
	}
	std::vector<Organism*> pred = PlayGrid -> GetAllPred();
	std::vector<Organism*> prey = PlayGrid -> GetAllPrey();

	int predsize = pred.size();
	cout << "Number of predators: " << predsize << "\n";

	int preysize = prey.size();
	cout << "Number of prey: " << preysize << "\n";

	while(predsize!=0){
		for(int i = 0; i<predsize; i++){
			pred.at(i)->move();
		}
		for(int i = 0; i<preysize; i++){
			prey.at(i)->move();
		}
		prey.clear();
		prey = PlayGrid->GetAllPrey();
		pred.clear(); //should not delete objects themselves if so, this could cause error
		pred = PlayGrid->GetAllPred();

	}

}
