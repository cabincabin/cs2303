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
void Doodlebug::move(){// if need to dynamically allocate, free openSpace here
	std::vector<Organism*> prey = grid->GetAllPrey(rPos(),cPos());
	int size = prey.size();
	if(size!=0){
		Organism* loc = prey.at((long)(rand()%size));
		int ro = loc->rPos();
		int co = loc->cPos();
		loc->die();
		grid->BugGrid[loc->rPos()][loc->cPos()]=this;
		grid->BugGrid[rPos()][cPos()]=NULL;
		r = ro;
		c = co;
		eatcnt=0;
		breed();
		prey.clear();
	}
	else{
		std::vector<int*> OpenSpaces = grid->GetAllEmptyLoc(rPos(),cPos());
		size = OpenSpaces.size();
		if(size!=0){
			int* loc = OpenSpaces.at((long)(rand()%size));
			grid->BugGrid[loc[0]][loc[1]]=this;
			grid->BugGrid[rPos()][cPos()]=NULL;
			r = loc[0];
			c = loc[1];
			eatcnt++;
			if(eatcnt >= 3){
				die();
			}
			else
				breed();
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
	breedcount++;
	if(breedcount >= 8){
		std::vector<int*> OpenSpaces = grid->GetAllEmptyLoc(rPos(),cPos());//will always be at least 1 location when invoked by self
		int size = OpenSpaces.size();
		if(size!=0){//for saftey
			int* loc = OpenSpaces.at((long)(rand()%size));
			(new Doodlebug(grid,loc[0], loc[1]))->AddSelfToGrid();
			breedcount = 0;
		}
	}
}

/*****************************************************************************/
/** ~Doodlebug()
 * Purpose: Doodlebug deconstructor
 */
Doodlebug::~Doodlebug() {
	// TODO Auto-generated destructor stub
}
