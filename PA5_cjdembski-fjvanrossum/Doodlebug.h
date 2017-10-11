/*
 * Doodlebug.h
 *
 *  Created on: Oct 9, 2017
 *      Author: Clayton Dembski & Floris van Rossum
 *      Purpose: Header file of the Doodlebug class
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

#include "Organism.h"

class Grid;

class Doodlebug:public Organism {
	int eatcnt;
public:
	// Constructor of the doodlebug object
	Doodlebug(Grid* gri, int rpos, int cpos);

	// Virtual functions, base class method to be used
	virtual void move();
	virtual void breed();
	virtual ~Doodlebug();

	// Functions implemented in doodlebug
	void Starve();
};

#endif /* DOODLEBUG_H_ */
