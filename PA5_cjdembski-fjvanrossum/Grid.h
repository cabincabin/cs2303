/*
 * Grid.h
 *
 *  Created on: Oct 8, 2017
 *      Author: Clayton Dembski and Floris van Rossum
 *      Purpose:
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
	int totalAnts;
	int totalDoods;
public:
	Organism*** BugGrid;
	Grid(int row, int col);
	bool isValid(int r, int c);
	int getrow();
	int getcol();

	std::vector<Organism*> GetAllPrey();
	std::vector<Organism*> GetAllPred();
	std::vector<Organism*> GetAllPrey(int r, int c);
	std::vector<Organism*> GetAllPred(int r, int c);
	std::vector<int*> GetAllEmptyLoc(int r, int c);
	void updateTotNumAnts();
	void updateTotNumDoods();
	int getTotAnts();
	int getTotDoods();
	virtual ~Grid();
};

#endif /* GRID_H_ */
