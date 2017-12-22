/*
 * Doodlebug.cpp
 *
 *  Created on: Oct 9, 2017
 *      Author: Clayton Dembski and Floris van Rossum
 *      Purpose:
 */
/*****************************************************************************/
// Include statements
#include "Doodlebug.h"
#include "Grid.h"
#include "Organism.h"

#include <vector>
#include <iostream>

#include <cstdlib>

/*****************************************************************************/

/** Doodlebug(Grid* gri, int rpos, int cpos)
 * Purpose: Constructor of the doodlebug organism
 * @param Grid* gri Pointer to the grid object
 * @param int rpos Row position of the doodlebug
 * @param int cpos Column position of the doodlebug
 */
Doodlebug::Doodlebug(Grid* gri, int rpos, int cpos):
Organism(false,gri,rpos,cpos), eatcnt(0){
}

/*****************************************************************************/
/** void move()
 * Purpose: Move the doodlebug according to the rules
 * @return void
 */
void Doodlebug::move(){
	// Initialize a vector containing all the prey in surroundings
	std::vector<Organism*> prey = grid->GetAllPrey(rPos(),cPos());
	int size = prey.size();
	// Check if there is more than one prey in surrounding
	if(size!=0){
		// Generate a random location and store it
		Organism* loc = prey.at((long)(rand()%size));
		int ro = loc->rPos();
		int co = loc->cPos();
		loc->die(); // Delete the organism used to generate random location

		grid->BugGrid[loc->rPos()][loc->cPos()]=this; // Update the location of the
		// organism on the field
		grid->BugGrid[rPos()][cPos()]=NULL; // Set old position of organism to null

		// Update the object fields
		r = ro;
		c = co;
		eatcnt=0;
		breed();
		prey.clear();
	}
	else{
		// There are no prey in surroundings
		// Find the empty, available spots around doodlebug
		std::vector<int*> OpenSpaces = grid->GetAllEmptyLoc(rPos(),cPos());
		// Check to see if the doodle bug can move at all
		size = OpenSpaces.size();
		if(size!=0){
			// Pick a random location to go
			int* loc = OpenSpaces.at((long)(rand()%size));
			// Update position of the doodlebug in the grid
			grid->BugGrid[loc[0]][loc[1]]=this;
			// Update the old position of the doodle bug
			grid->BugGrid[rPos()][cPos()]=NULL;

			// Update the position of the doodlebug in the grid
			r = loc[0];
			c = loc[1];

			// Check if the doodle bug needs to die because it hasn't eaten
			eatcnt++;
			if(eatcnt >= 3){
				die(); // Doodlebug hasnt eaten recently so it dies
			}
			else
				breed(); // Update breeding of doodlebug

			OpenSpaces.clear();
		}
	}
}

/*****************************************************************************/
/** void breed()
 * Purpose: Breed the doodlebug, spawn another one nearby
 * @return void
 */
void Doodlebug::breed(){
	breedcount++; // Update the count of when to breed
	// Check if the doodle bug needs to breed
	if(breedcount >= 8){
		// Create a vector of all the open spaces around the doodlebug
		std::vector<int*> OpenSpaces = grid->GetAllEmptyLoc(rPos(),cPos());
		// Check if there is an open space around the doodlebug
		int size = OpenSpaces.size();
		if(size!=0){
			// Generate a random location to add the doodle bug to
			int* loc = OpenSpaces.at((long)(rand()%size));
			(new Doodlebug(grid,loc[0], loc[1]))->AddSelfToGrid();
			breedcount = 0; // Reset the breed counter
		}
	}
}

/*****************************************************************************/
/** ~Doodlebug()
 * Purpose: Doodlebug deconstructor
 */
Doodlebug::~Doodlebug() {
}
