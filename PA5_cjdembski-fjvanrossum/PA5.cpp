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

//Used for printing messages
#include <iostream>

//Random libraries
#include <cstdlib>
#include "Grid.h"
#include "Organism.h"

int main(){
	Grid PlayGrid(5,5);
	Organism *Bug1 = PlayGrid.BugGrid[1][1];
	delete PlayGrid.BugGrid[1][1];
	bool bool1 = true;
	if(PlayGrid.BugGrid[1][1]==NULL){
		bool1 = false;
	}
	else{
		bool1 = true;
	}
	/*for(int i = 0; i<5; i++){
			for(int j = 0; j<5; j++){
				std::cout<<PlayGrid->grid[i][j]->isPrey();
			}
		}*/
	int i = 0;

}
