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
			int* loc1 = new int[2];
			 loc1[0]=r-1;
			 loc1[1]=c;
			AllEmpty.push_back(loc1);
		}
	}
	if(r+1<row){
		if(BugGrid[r+1][c]==NULL){
			int* loc2 = new int[2];
			loc2[0]=r+1;
			loc2[1]=c;
			AllEmpty.push_back(loc2);
		}
	}
	if(c-1>=0){
		if(BugGrid[r][c-1]==NULL){
			int* loc3 = new int[2];
			loc3[0]=r;
			loc3[1]=c-1;
			AllEmpty.push_back(loc3);
		}
	}
	if(c+1<col){
		if(BugGrid[r][c+1]==NULL){
			int* loc4 = new int[2];
			loc4[0]=r;
			loc4[1]=c+1;
			AllEmpty.push_back(loc4);
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

