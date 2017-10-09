/*
 * Doodlebug.h
 *
 *  Created on: Oct 9, 2017
 *      Author: student
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_
#include "Organism.h"
class Grid;

class Doodlebug:public Organism {
	int eatcnt;
public:
	Doodlebug(Grid* gri, int rpos, int cpos);
	virtual void move();
	void Starve();
	virtual void breed();
	virtual ~Doodlebug();
};

#endif /* DOODLEBUG_H_ */
