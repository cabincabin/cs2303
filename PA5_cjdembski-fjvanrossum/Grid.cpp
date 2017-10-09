/*
 * Grid.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: student
 */

#include "Grid.h"
#include "Organism.h"

Grid::Grid(int row, int col): grid(new Organism**[row]){
	for(int i = 0; i<row; i++){
	grid[i] = new Organism*[col];
	}

	for(int i = 0; i<row; i++){
		for(int j = 0; j<col; j++){
			grid[i][j] = new Organism;
		}
	}
	grid[1][1] = new Organism(true);

}


Grid::~Grid() {
	// TODO Auto-generated destructor stub
}

