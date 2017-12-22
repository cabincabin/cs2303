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
void Ant::move(){
	// Find all the empty locations surrounding the ant
	std::vector<int*> OpenSpaces = grid->GetAllEmptyLoc(rPos(),cPos());
	// Determine if there is a free location around the ant where it can move to
	int size = OpenSpaces.size();
	if(size!=0){
		// Generate a random direction for the ant to travel in
		int* loc = OpenSpaces.at((long)(rand()%size));
		grid->BugGrid[loc[0]][loc[1]]=this; // Move the ant to the new location
		grid->BugGrid[rPos()][cPos()]=NULL;// Set the previous location of the ant
		// to null

		// Update the ant object fields
		r = loc[0];
		c = loc[1];
		breed(); // Update the breed status of the ant
	}
	OpenSpaces.clear();
}

/*****************************************************************************/
/** void breed()
 * Purpose: Breed the ant, spawn another one nearby
 * @return void
 */
void Ant::breed(){
	breedcount++; // Update the breed count variable
	// If the breed count is above 3, breed the ant
	if(breedcount >=3){
		// Find all empty locations surrounding the ant
		std::vector<int*> OpenSpaces = grid->GetAllEmptyLoc(rPos(),cPos());
		// Determine if there is a free location around the ant where it can breed to
		int size = OpenSpaces.size();
		if(size!=0){
			// Breed a new ant in a random direction
			int* loc = OpenSpaces.at((long)(rand()%size));
			(new Ant(grid,loc[0], loc[1]))->AddSelfToGrid();
			breedcount = 0; // Reset the ant breed count
		}
	}
}

/*****************************************************************************/
/** ~Ant()
 * Purpose: Deconstructor of the ant object
 * @return void
 */
Ant::~Ant() {
}
