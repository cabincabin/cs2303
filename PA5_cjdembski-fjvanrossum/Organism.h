/*
 * Orginism.h
 *
 *  Created on: Oct 8, 2017
 *      Author: Clayton Dembski and Floris van Rossum
 *      Purpose: Header file of the Organism class
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_

class Grid;

class Organism{
// Protected variables
protected:
bool prey;
int breedcount;
Grid* grid;
int r;
int c;

// Public variables, functions & constructors
public:
Organism(bool pre, Grid* gri, int rpos, int cpos);
	bool isPrey();
	virtual void move() = 0; // To be overridden by derived classes
	virtual void breed() = 0; // To be overridden by derived classes
	void die(); // Delete an organism, clear it from the grid
	// Get functions
	int rPos();
	int cPos();
	void AddSelfToGrid(); // Add an organism to the playing grid
	virtual ~Organism();

};

#endif /* ORGANISM_H_ */
