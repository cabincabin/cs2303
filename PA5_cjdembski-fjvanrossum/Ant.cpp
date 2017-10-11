/*
 * Ant.cpp
 *
 *  Created on: Oct 9, 2017
 *      Author: Clayton Dembski and Floris van Rossum
 *      Purpose:
 */
/*****************************************************************************/
// Include statements
#include "Ant.h"
#include "Grid.h"
#include "Organism.h"

#include <vector>
#include <iostream>
#include <cstdlib>

/*****************************************************************************/
/** Ant()
 * Purpose: Constructor of the ant organism
 * @param Grid* gri Pointer to the grid playing field
 * @param int rpos The row position of the ant
 * @param int cpos The column position of the ant
 */
Ant::Ant(Grid* gri, int rpos, int cpos):
Organism(true,gri,rpos,cpos){
}

/*****************************************************************************/
/** void move()
 * Purpose: Move the ant according to the rules
 * @return void
 */
void Ant::move(){// if need to dynamically allocate, free openSpace here
	std::vector<int*> OpenSpaces = grid->GetAllEmptyLoc(rPos(),cPos());
	int size = OpenSpaces.size();
	if(size!=0){
		int* loc = OpenSpaces.at((long)(rand()%size));
		grid->BugGrid[loc[0]][loc[1]]=this;//move
		grid->BugGrid[rPos()][cPos()]=NULL;//previous location is null
		r = loc[0];
		c = loc[1];
		breed();
	}
	OpenSpaces.clear();
}

/*****************************************************************************/
/** void breed()
 * Purpose: Breed the ant, spawn another one nearby
 * @return void
 */
void Ant::breed(){
	breedcount++;
	if(breedcount >=3){
		std::vector<int*> OpenSpaces = grid->GetAllEmptyLoc(rPos(),cPos());//will always be at least 1 location when invoked by self
		int size = OpenSpaces.size();
		if(size!=0){//for saftey
			int* loc = OpenSpaces.at((long)(rand()%size));
			(new Ant(grid,loc[0], loc[1]))->AddSelfToGrid();
			breedcount = 0;
		}
	}
}

/*****************************************************************************/
/** ~Ant()
 * Purpose: Deconstructor of the ant object
 * @return void
 */
Ant::~Ant() {
	// TODO Auto-generated destructor stub
}

