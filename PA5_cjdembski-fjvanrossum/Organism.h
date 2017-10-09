/*
 * Orginism.h
 *
 *  Created on: Oct 8, 2017
 *      Author: student
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_

class Grid;

class Organism {
protected:
bool prey;
public:
	Organism();
	bool isPrey();
	Organism(bool pre);
	virtual ~Organism();

};

#endif /* ORGANISM_H_ */
