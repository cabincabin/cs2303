/*
 * Ant.h
 *
 *  Created on: Oct 9, 2017
 *      Author: student
 */

#ifndef ANT_H_
#define ANT_H_
#include "Organism.h"
class Grid;


class Ant: public Organism{
public:
	Ant(Grid* gri, int rpos, int cpos);
	virtual void move();
	virtual void breed();

	virtual ~Ant();
};

#endif /* ANT_H_ */
