/*
 * Grid.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: Clayton Dembski and Floris van Rossum
 *      Purpose:
 */
/*****************************************************************************/
// Include statements
#include "Grid.h"
#include "Organism.h"

#include <vector>
#include <iostream>

/*****************************************************************************/

/** Grid()
 * Purpose: Constructor of the Grid Object
 * @param int ro Number of rows of the grid
 * @param int co Number of columns of the grid
 */
Grid::Grid(int ro, int co): row(ro),
col(co),totalAnts(0),totalDoods(0),
BugGrid(new Organism**[ro])
{
	// Fill the array with Organisms
	for(int i = 0; i < ro; i++){
		BugGrid[i] = new Organism*[co];
	}
}

/*****************************************************************************/

/** vector<Organism*> GetAllPred()
 * Purpose: Returns a vector containing all the predator organisms
 * @return vector<Organism*> Vector containing all the predators in the grid
 */
std::vector<Organism*> Grid::GetAllPred(){
	// Return vector
	std::vector<Organism*> AllPred;

	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			// Check if this position in the grid is empty
			if(BugGrid[i][j] != NULL){
				// BugGrid[i][j] is not empty, loop invariant
				// Check if this position in the grid is prey
				if(!(BugGrid[i][j] -> isPrey())){
					// The BugGrid[i][j] is a prey so add this location to the
					// vector
					AllPred.push_back(BugGrid[i][j]);
				}
			}

		}
	}
	return AllPred;
}

/*****************************************************************************/
/** vector<Organism*> GetAllPred(int r, int c)
 * Purpose: Returns a vector of predator around a specific location
 * @param int r Row maximum of the grid
 * @param int c Column maximum of the grid
 * @return vector<Organism*> Vector containing all the predators in a space
 */
std::vector<Organism*> Grid::GetAllPred(int r, int c){
	// Return vector
	std::vector<Organism*> AllPred;
	// This conditional statement checks if there is a predator in the adjecent grid
	// r,c
	// First layer of conditional statement protects agains running off the end
	// of the array
	if(r-1>=0){
		// Check left grid location
		if(BugGrid[r-1][c]!=NULL && !BugGrid[r-1][c]->isPrey()){
			// Left is a predator, add it to vector
			AllPred.push_back(BugGrid[r-1][c]);
		}
	}
	if(r+1<row){
		// Check right grid location
		if(BugGrid[r+1][c]!=NULL && !BugGrid[r+1][c]->isPrey()){
			// Right is a predator, add it to vector
			AllPred.push_back(BugGrid[r+1][c]);
		}
	}
	if(c-1>=0){
		// Check top grid location
		if(BugGrid[r][c-1]!=NULL && !BugGrid[r][c-1]->isPrey()){
			// Top is a predator, add it to vector
			AllPred.push_back(BugGrid[r][c-1]);
		}
	}
	if(c+1<col){
		// Check bottom grid location
		if(BugGrid[r][c+1]!=NULL && !BugGrid[r][c+1]->isPrey()){
			// Bottom is a predator, add it to vector
			AllPred.push_back(BugGrid[r][c+1]);
		}
	}
		return AllPred;
}

/*****************************************************************************/
/** vector<Organism*> GetAllPrey()
 * Purpose: Returns a vector of all prey in the grid
 * @return vector<Organism*> Vector containing all the prey in the grid
 */
std::vector<Organism*> Grid::GetAllPrey(){
	// Return vector
	std::vector<Organism*> AllPrey;

	// Iterate through all the rows and columns
	for(int i = 0; i<row; i++){
		for(int j = 0; j<col; j++){
			// Check if the grid is not zero
			if(BugGrid[i][j] != NULL){
				// Check if the grid is a prey
				if((BugGrid[i][j] -> isPrey())){
					// Grid space is prey, so add it to the vector
					AllPrey.push_back(BugGrid[i][j]);
				}
			}
		}
	}
	return AllPrey;
}

/*****************************************************************************/
/** vector<Organism*> GetAllPrey(int r, int c)
 * Purpose: Returns a vector of all prey around a specific location
 * @param int r Row maximum of the grid
 * @param int c Column maximum of the grid
 * @return vector<Organism*> Vector containing prey around parameter grid space
 */
std::vector<Organism*> Grid::GetAllPrey(int r, int c){
	// Return variable
	std::vector<Organism*> AllPrey;
	// Protection against running off the end of the grid
	if(r-1>=0){
		// Check the left grid
		if(BugGrid[r-1][c]!=NULL && BugGrid[r-1][c]->isPrey()){
			// Left grid is prey so add it to vector
			AllPrey.push_back(BugGrid[r-1][c]);
		}
	}
	if(r+1<row){
		// Check the right grid space
		if(BugGrid[r+1][c]!=NULL && BugGrid[r+1][c]->isPrey()){
			// Right grid space is prey, so add it to vector
			AllPrey.push_back(BugGrid[r+1][c]);
		}
	}
	if(c-1>=0){
		// Check top grid space
		if(BugGrid[r][c-1]!=NULL && BugGrid[r][c-1]->isPrey()){
			// Top grid space is prey, so add it to vector
			AllPrey.push_back(BugGrid[r][c-1]);
		}
	}
	if(c+1<col){
		// Check bottom grid space
		if(BugGrid[r][c+1]!=NULL && BugGrid[r][c+1]->isPrey()){
			// Bottom grid space is prey, so add it to vector
			AllPrey.push_back(BugGrid[r][c+1]);
		}
	}
		return AllPrey;
}

/*****************************************************************************/
/** vector<int*> GetAllEmptyLoc(int r, int c)
 * Purpose: Returns a vector int of empty locations around a grid space
 * @param int r Row maximum of the grid
 * @param int c Column maximum of the grid
 * @return vector<Organism*> Vector containing all empty spaces
 */
std::vector<int*> Grid::GetAllEmptyLoc(int r, int c){
	/* Used if statements instead of a for loop because there are too little
	 * spaces to make a for loop worth it. There is only left, right, top and
	 * bottom. While it might make the code more concise it would increase the
	 * workload for the program when creating a vector of empty locations.
	 */
	// Return vector
	std::vector<int*> AllEmpty;

	// First conditional statement is to check we are not running off the end
	// of the grid
	if(r-1>=0){
		// Check the left grid space
		if(BugGrid[r-1][c]==NULL){
			// Add the left empty space to the vector
			int* loc1 = new int[2];
			 loc1[0]=r-1;
			 loc1[1]=c;
			AllEmpty.push_back(loc1);
		}
	}
	if(r+1<row){
		// Check the right grid space
		if(BugGrid[r+1][c]==NULL){
			// Add the right empty space to the vector
			int* loc2 = new int[2];
			loc2[0]=r+1;
			loc2[1]=c;
			AllEmpty.push_back(loc2);
		}
	}
	if(c-1>=0){
		// Check the top grid space
		if(BugGrid[r][c-1]==NULL){
			// Add the top grid space to the vector
			int* loc3 = new int[2];
			loc3[0]=r;
			loc3[1]=c-1;
			AllEmpty.push_back(loc3);
		}
	}
	if(c+1<col){
		// Check the bottom grid space
		if(BugGrid[r][c+1]==NULL){
			// Add the bottom grid space to the vector
			int* loc4 = new int[2];
			loc4[0]=r;
			loc4[1]=c+1;
			AllEmpty.push_back(loc4);
		}
	}
		return AllEmpty;
}

/*****************************************************************************/
/** void updateTotNumAnts()
 * Purpose: Update the total count of ants in the game
 * @return void
 */
void Grid::updateTotNumAnts(){
	totalAnts++;
}

/*****************************************************************************/
/** void updateTotNumDoods()
 * Purpose: Update the total count of doodlebugs in the game
 * @return void
 */
void Grid::updateTotNumDoods(){
	totalDoods++;
}

/*****************************************************************************/
/** int getTotAnts()
 * Purpose: Return the total count of ants in the game
 * @return int The number of ants in the game
 */
int Grid::getTotAnts(){
	return totalAnts;
}

/*****************************************************************************/
/** int getTotDoods()
 * Purpose: Return the total count of doodlebugs in the game
 * @return int The total number of doodlebugs in the game
 */
int Grid::getTotDoods(){
	return totalDoods;
}

/*****************************************************************************/
/** int getrow()
 * Purpose: Return the number of rows in the grid
 * @return int The number of rows in the grid
 */
int Grid::getrow(){
	return row;
}

/*****************************************************************************/
/** int getcol()
 * Purpose: Return the number of columns in the grid
 * @return int The number of columns in the grid
 */
int Grid::getcol(){
	return col;
}

/*****************************************************************************/
/** bool isValid(int r, int c)
 * Purpose: Function determines if a certain location is off the end of the grid
 * @return bool Returns a boolean value based on whether (r,c) is off the grid
 * (TRUE == in grid) (FALSE == not in grid)
 */
bool Grid::isValid(int r, int c){
	// This conditional statements checks if the location is off the end of the
	// grid
	if(r>=0&&r<row&&c>=0&&c<col)
		return true;
	return false;
}

/*****************************************************************************/
/** ~Grid()
 * Purpose: Deconstructor of the grid object
 */
Grid::~Grid() {
}
