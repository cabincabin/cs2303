/*
 * Ant.h
 *
 *  Created on: Oct 9, 2017
 *      Author: Clayton Dembski & Floris van Rossum
 *      Purpose: Header file of the Ant class
 */

#ifndef ANT_H_
#define ANT_H_
#include "Organism.h"
class Grid;


class Ant: public Organism{
public:
	// Ant Contstructor
	Ant(Grid* gri, int rpos, int cpos);

	virtual void move();
	virtual void breed();
	// Virtual deconstructor
	virtual ~Ant();
};

#endif /* ANT_H_ */
