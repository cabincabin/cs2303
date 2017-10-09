/*
 * Orginism.h
 *
 *  Created on: Oct 8, 2017
 *      Author: student
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_

class Grid;

class Organism{
protected:
bool prey;
int breedcount;
Grid* grid;
int x;
int y;
public:
Organism(bool pre, Grid* gri, int xpos, int ypos);
	bool isPrey();
	virtual void move() = 0;
	virtual void breed() = 0;
	virtual void doAction() = 0;
	int xPos();
	int yPos();
	virtual ~Organism();

};

#endif /* ORGANISM_H_ */
