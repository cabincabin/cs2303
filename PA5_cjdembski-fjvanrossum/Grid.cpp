/*
 * Grid.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: student
 */

#include "Grid.h"
#include "Organism.h"

#include <vector>
#include <iostream>

Grid::Grid(int ro, int co): row(ro),
col(co), BugGrid(new Organism**[ro])
{
	for(int i = 0; i<ro; i++){
	BugGrid[i] = new Organism*[co];

	}
}

std::vector<Organism*> Grid::GetAllPrey(int r, int c){
	std::vector<Organism*> AllPrey;
	if(r-1>=0){
		if(BugGrid[r-1][c]!=NULL && BugGrid[r-1][c]->isPrey()){
			AllPrey.push_back(BugGrid[r-1][c]);
		}
	}
	if(r+1<row){
		if(BugGrid[r+1][c]!=NULL && BugGrid[r+1][c]->isPrey()){
			AllPrey.push_back(BugGrid[r+1][c]);
		}
	}
	if(c-1>=0){
		if(BugGrid[r][c-1]!=NULL && BugGrid[r][c-1]->isPrey()){
			AllPrey.push_back(BugGrid[r][c-1]);
		}
	}
	if(c+1<col){
		if(BugGrid[r][c+1]!=NULL && BugGrid[r][c+1]->isPrey()){
			AllPrey.push_back(BugGrid[r][c+1]);
		}
	}
		return AllPrey;
}

std::vector<Organism*> Grid::GetAllEmptyLoc(int r, int c){
	std::vector<Organism*> AllEmpty;
	if(r-1>=0){
		if(BugGrid[r-1][c]==NULL){
			AllEmpty.push_back(BugGrid[r-1][c]);
		}
	}
	if(r+1<row){
		if(BugGrid[r+1][c]==NULL){
			AllEmpty.push_back(BugGrid[r+1][c]);
		}
	}
	if(c-1>=0){
		if(BugGrid[r][c-1]==NULL){
			AllEmpty.push_back(BugGrid[r][c-1]);
		}
	}
	if(c+1<col){
		if(BugGrid[r][c+1]==NULL){
			AllEmpty.push_back(BugGrid[r][c+1]);
		}
	}
		return AllEmpty;
}

int Grid::getrow(){
	return row;
}

int Grid::getcol(){
	return col;
}



Grid::~Grid() {
	// TODO Auto-generated destructor stub
}

