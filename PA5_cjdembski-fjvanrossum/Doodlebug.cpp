/*
 * Doodlebug.cpp
 *
 *  Created on: Oct 9, 2017
 *      Author: student
 */

#include "Doodlebug.h"
#include "Grid.h"
#include "Organism.h"

#include <vector>
#include <iostream>

#include <cstdlib>
Doodlebug::Doodlebug(Grid* gri, int rpos, int cpos):
Organism(false,gri,rpos,cpos), eatcnt(0){


}

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


		}
	}
}
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


Doodlebug::~Doodlebug() {
	// TODO Auto-generated destructor stub
}

