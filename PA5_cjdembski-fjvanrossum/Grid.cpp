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
	for(int i = 0; i < ro; i++){
		BugGrid[i] = new Organism*[co];
	}
}

std::vector<Organism*> Grid::GetAllPred(){
	std::vector<Organism*> AllPred;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if(BugGrid[i][j] != NULL){
				if(!(BugGrid[i][j] -> isPrey())){
					AllPred.push_back(BugGrid[i][j]);
				}
			}
		}
	}
	return AllPred;
}

std::vector<Organism*> Grid::GetAllPred(int r, int c){
	std::vector<Organism*> AllPred;
	if(r-1>=0){
		if(BugGrid[r-1][c]!=NULL && !BugGrid[r-1][c]->isPrey()){
			AllPred.push_back(BugGrid[r-1][c]);
		}
	}
	if(r+1<row){
		if(BugGrid[r+1][c]!=NULL && !BugGrid[r+1][c]->isPrey()){
			AllPred.push_back(BugGrid[r+1][c]);
		}
	}
	if(c-1>=0){
		if(BugGrid[r][c-1]!=NULL && !BugGrid[r][c-1]->isPrey()){
			AllPred.push_back(BugGrid[r][c-1]);
		}
	}
	if(c+1<col){
		if(BugGrid[r][c+1]!=NULL && !BugGrid[r][c+1]->isPrey()){
			AllPred.push_back(BugGrid[r][c+1]);
		}
	}
		return AllPred;
}

std::vector<Organism*> Grid::GetAllPrey(){
	std::vector<Organism*> AllPrey;
	for(int i = 0; i<row; i++){
		for(int j = 0; j<col; j++){
			if(BugGrid[i][j] != NULL){
				if((BugGrid[i][j] -> isPrey())){
					AllPrey.push_back(BugGrid[i][j]);
				}
			}
		}
	}
	return AllPrey;
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

std::vector<int*> Grid::GetAllEmptyLoc(int r, int c){//THIS MAY HAVE SCOPE PROBLEMS IF SO CHANGE EACH LOC TO A NEW INT(2)
	std::vector<int*> AllEmpty;
	if(r-1>=0){
		if(BugGrid[r-1][c]==NULL){
			int loc[2]={r-1,c};
			AllEmpty.push_back(loc);
		}
	}
	if(r+1<row){
		if(BugGrid[r+1][c]==NULL){
			int loc[2]={r+1,c};
			AllEmpty.push_back(loc);
		}
	}
	if(c-1>=0){
		if(BugGrid[r][c-1]==NULL){
			int loc[2]={r,c-1};
			AllEmpty.push_back(loc);
		}
	}
	if(c+1<col){
		if(BugGrid[r][c+1]==NULL){
			int loc[2]={r,c+1};
			AllEmpty.push_back(loc);
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

bool Grid::isValid(int r, int c){
	if(r>=0&&r<row&&c>=0&&c<col)
		return true;
	return false;
}
Grid::~Grid() {
	// TODO Auto-generated destructor stub
}

