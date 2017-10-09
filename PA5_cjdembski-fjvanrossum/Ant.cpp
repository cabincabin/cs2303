/*
 * Ant.cpp
 *
 *  Created on: Oct 9, 2017
 *      Author: student
 */

#include "Ant.h"
#include "Grid.h"
#include "Organism.h"

#include <vector>
#include <iostream>
#include <cstdlib>

Ant::Ant(Grid* gri, int rpos, int cpos):
Organism(true,gri,rpos,cpos){
}

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
}
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

Ant::~Ant() {
	// TODO Auto-generated destructor stub
}

