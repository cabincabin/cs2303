/*
 * qSim.c
 *
 *  Created on: Oct. 1st, 2017
 *  Author: Clayton Dembski & Floris van Rossum
 *  Purpose: Main file of PA4
 *
 */

/*****************************************************************/
//Include Statements:
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

//Used for printing messages
#include <iostream>
using namespace std;

//Random libraries
#include <cstdlib>

#include "Event.h"
#include "EventQueue.h"
#include "CustEvent.h"

/*****************************************************************/

int main(int argc, char ** argv){
	//./qSim #customers #tellers simulationTime averageServiceTime <seed>
	if(argc < 5){
		cout << "ERROR: Incorrect Command Line Input \n";
		exit(-1);
	}
	cout << "The number of customers entered: " << argv[1] << "\n";
	int customers = atoi(argv[1]);
	cout << "The number of tellers entered: " << argv[2] << "\n";
	int tellers = atoi(argv[2]);
	cout << "The simulation time entered: " << argv[3] << "\n";
	int simulationTime = atoi(argv[3]); // Simulation time in minutes
	cout << "The average service time entered: " << argv[4] << "\n";
	float averageServiceTime = atoi(argv[4]);
	cout << "The random seed entered entered: " << argv[5] << "\n";
	float randomSeed = atoi(argv[5]); // Random
	if(randomSeed != NULL && randomSeed != 0)
		srand(randomSeed);

	//Initializing necessary objects
	EventQueue *queue = new EventQueue();
	float arrivalTime;
	for(int i = 0; i < customers; i++){
		arrivalTime = simulationTime * (rand() / float(RAND_MAX));
		cout << "The random arrival time of customer:" << i << " is " <<
				arrivalTime << "\n";
		CustEvent *customer = new CustEvent(*queue, arrivalTime);
	}
	float serviceTime;
	for(int i = 0; i < tellers; i++){
		//Put teller initialization here
		serviceTime = 2 * averageServiceTime * (rand()/float(RAND_MAX));
		//put teller object initialization here later
	}

	Event * c1 = new Event(*queue, 1);
	c1->AddEvent();
	Event * c2 = new Event(*queue, 1.5);
	c2->AddEvent();
	Event * c3 = new Event(*queue, 2);
	c3->AddEvent();
	Event * c4 = new Event(*queue, 5);
	c4->AddEvent();
}
