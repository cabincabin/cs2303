/*
 * Grid.h
 *
 *  Created on: Oct 8, 2017
 *      Author: student
 */

#ifndef GRID_H_
#define GRID_H_
#include <vector>
#include <iostream>
class Organism;


class Grid {
protected:
	int row;
	int col;
public:
	Organism*** BugGrid;
	Grid(int row, int col);
	bool isValid();
	int getrow();
	int getcol();
	std::vector<Organism*> GetAllPrey(int r, int c);
	std::vector<Organism*> GetAllEmptyLoc(int r, int c);
	Organism* getOrginismsAtLoc(int x, int y);
	virtual ~Grid();
};

#endif /* GRID_H_ */
