/*
 * Grid.h
 *
 *  Created on: Oct 8, 2017
 *      Author: student
 */

#ifndef GRID_H_
#define GRID_H_
class Organism;
class Grid {
protected:

public:
	Organism*** grid;
	Grid(int row, int col);
	bool isValid();
	Organism* getOrginismsAtLoc(int x, int y);
	virtual ~Grid();
};

#endif /* GRID_H_ */
