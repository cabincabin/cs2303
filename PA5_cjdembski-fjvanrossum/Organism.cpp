/*
 * Orginism.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: Clayton Dembski and Floris van Rossum
 *      Purpose:
 */
/*****************************************************************************/
// Include Statements
#include "Organism.h"
#include "Grid.h"
#include <vector>

/*****************************************************************************/

/** Organism(bool pre, Grid* gri, int rpos, int cpos)
 * Purpose: Constructor of the organism object
 * @param bool pre Boolean value that determines if it a prey
 * @param Grid* gri Pointer to the grid playing field
 * @param int rpos Row position of the object
 * @param int cpos Column position of the object
 */
Organism::Organism(bool pre, Grid* gri, int rpos, int cpos):
		prey(pre),
		breedcount(0),
		grid(gri),
		r(rpos),
		c(cpos){

}

/*****************************************************************************/
/** int rPos()
 * Purpose: Get function that returns the row position
 * @return int Row value of the object
 */
int Organism::rPos(){
	return r;
}

/*****************************************************************************/
/** void die()
 * Purpose: Function that deletes an object and replaces grid location with null
 * @return void
 */
void Organism::die(){
	// Set the grid space of this object to null
	grid->BugGrid[r][c]=NULL;
	delete this;
}

/*****************************************************************************/
/** void AddSelfToGrid()
 * Purpose: Adds an organism to the grid
 * @return void
 */
void Organism::AddSelfToGrid(){
	// Check if the grid space of the organism is within the user defined
	// bounds of the grid
	if(grid->isValid(r,c))
		grid->BugGrid[r][c]=this; // Add the organism to the grid
	// Check if the organism is a prey or ant
	if(isPrey()){
		grid->updateTotNumAnts(); // Update total number of ants
	}
	else
		grid->updateTotNumDoods(); // Update the total number of doodlebugs
}

/*****************************************************************************/
/** int cPos()
 * Purpose: Get function that returns the column position
 * @return int Column value of the organism
 */
int Organism::cPos(){
	return c;
}

/*****************************************************************************/
/** bool isPrey()
 * Purpose: Return the prey variable of the organism
 * @return bool Prey variable (1 == PREY, 0 == PREDATOR)
 */
bool Organism::isPrey(){
	return prey;
}

/*****************************************************************************/
/** ~Organism()
 * Purpose: Deconstructor of the organism object
 */
Organism::~Organism(){
}
