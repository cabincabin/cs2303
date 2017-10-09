/*
 * Orginism.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: student
 */

#include "Organism.h"
#include "Grid.h"
#include <vector>

Organism::Organism(bool pre, Grid* gri, int rpos, int cpos):
		prey(pre),
		breedcount(0),
		grid(gri),
		r(rpos),
		c(cpos){

}
int Organism::rPos(){
	return r;
}

void Organism::die(){
	grid->BugGrid[r][c]=NULL;
	delete this;
}
void Organism::AddSelfToGrid(){
	if(grid->isValid(r,c))
	grid->BugGrid[r][c]=this;
}
int Organism::cPos(){
	return c;
}
bool Organism::isPrey(){
	return prey;
}
Organism::~Organism(){

}
