/*
 * Orginism.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: student
 */

#include "Organism.h"
#include "Grid.h"
#include <vector>

Organism::Organism(bool pre, Grid* gri, int xpos, int ypos):
		prey(pre),
		breedcount(0),
		grid(gri),
		x(xpos),
		y(ypos){

}
int Organism::xPos(){
	return x;
}
int Organism::yPos(){
	return y;
}
bool Organism::isPrey(){
	return prey;
}
Organism::~Organism(){

}
