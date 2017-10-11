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
	std::vector<Organism*> AllPred;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if(BugGrid[i][j] != NULL){
				if(!(BugGrid[i][j] -> isPrey())){
					AllPred.push_back(BugGrid[i][j]);
				}
			}
		}
	}
	return AllPred;
}

/*****************************************************************************/
/** vector<Organism*> GetAllPred(int r, int c)
 * Purpose: Returns a vector of all predators in the grid
 * @param int r Row maximum of the grid
 * @param int c Column maximum of the grid
 * @return vector<Organism*> Vector containing all the predators in a space
 */
std::vector<Organism*> Grid::GetAllPred(int r, int c){
	std::vector<Organism*> AllPred;
	if(r-1>=0){
		if(BugGrid[r-1][c]!=NULL && !BugGrid[r-1][c]->isPrey()){
			AllPred.push_back(BugGrid[r-1][c]);
		}
	}
	if(r+1<row){
		if(BugGrid[r+1][c]!=NULL && !BugGrid[r+1][c]->isPrey()){
			AllPred.push_back(BugGrid[r+1][c]);
		}
	}
	if(c-1>=0){
		if(BugGrid[r][c-1]!=NULL && !BugGrid[r][c-1]->isPrey()){
			AllPred.push_back(BugGrid[r][c-1]);
		}
	}
	if(c+1<col){
		if(BugGrid[r][c+1]!=NULL && !BugGrid[r][c+1]->isPrey()){
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
	std::vector<Organism*> AllPrey;
	for(int i = 0; i<row; i++){
		for(int j = 0; j<col; j++){
			if(BugGrid[i][j] != NULL){
				if((BugGrid[i][j] -> isPrey())){
					AllPrey.push_back(BugGrid[i][j]);
				}
			}
		}
	}
	return AllPrey;
}

/*****************************************************************************/
/** vector<Organism*> GetAllPrey(int r, int c)
 * Purpose: Returns a vector of all prey in the grid
 * @param int r Row maximum of the grid
 * @param int c Column maximum of the grid
 * @return vector<Organism*> Vector containing all the prey in the grid
 */
std::vector<Organism*> Grid::GetAllPrey(int r, int c){
	std::vector<Organism*> AllPrey;
	if(r-1>=0){
		if(BugGrid[r-1][c]!=NULL && BugGrid[r-1][c]->isPrey()){
			AllPrey.push_back(BugGrid[r-1][c]);
		}
	}
	if(r+1<row){
		if(BugGrid[r+1][c]!=NULL && BugGrid[r+1][c]->isPrey()){
			AllPrey.push_back(BugGrid[r+1][c]);
		}
	}
	if(c-1>=0){
		if(BugGrid[r][c-1]!=NULL && BugGrid[r][c-1]->isPrey()){
			AllPrey.push_back(BugGrid[r][c-1]);
		}
	}
	if(c+1<col){
		if(BugGrid[r][c+1]!=NULL && BugGrid[r][c+1]->isPrey()){
			AllPrey.push_back(BugGrid[r][c+1]);
		}
	}
		return AllPrey;
}

/*****************************************************************************/
/** vector<int*> GetAllEmptyLoc(int r, int c)
 * Purpose: Returns a vector int of empty locations in the grid
 * @param int r Row maximum of the grid
 * @param int c Column maximum of the grid
 * @return vector<Organism*> Vector containing all empty spaces
 */
std::vector<int*> Grid::GetAllEmptyLoc(int r, int c){//THIS MAY HAVE SCOPE PROBLEMS IF SO CHANGE EACH LOC TO A NEW INT(2)
	std::vector<int*> AllEmpty;
	if(r-1>=0){
		if(BugGrid[r-1][c]==NULL){
			int* loc1 = new int[2];
			 loc1[0]=r-1;
			 loc1[1]=c;
			AllEmpty.push_back(loc1);
		}
	}
	if(r+1<row){
		if(BugGrid[r+1][c]==NULL){
			int* loc2 = new int[2];
			loc2[0]=r+1;
			loc2[1]=c;
			AllEmpty.push_back(loc2);
		}
	}
	if(c-1>=0){
		if(BugGrid[r][c-1]==NULL){
			int* loc3 = new int[2];
			loc3[0]=r;
			loc3[1]=c-1;
			AllEmpty.push_back(loc3);
		}
	}
	if(c+1<col){
		if(BugGrid[r][c+1]==NULL){
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
	if(r>=0&&r<row&&c>=0&&c<col)
		return true;
	return false;
}

/*****************************************************************************/
/** ~Grid()
 * Purpose: Deconstructor of the grid object
 */
Grid::~Grid() {
	// TODO Auto-generated destructor stub
}
