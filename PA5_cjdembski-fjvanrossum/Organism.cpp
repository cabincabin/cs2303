/*
 * Orginism.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: student
 */

#include "Organism.h"
#include "Grid.h"

Organism::Organism():prey(false){
}
Organism::Organism(bool pre):prey(pre){
}
bool Organism::isPrey(){
	return prey;
}

Organism::~Organism() {
}

