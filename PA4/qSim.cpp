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
#include <math.h>
#include <climits>

//Used for printing messages
#include <iostream>
using namespace std;

//Random libraries
#include <cstdlib>

#include "Event.h"
#include "EventQueue.h"
#include "CustEvent.h"
#include "TellerList.h"
#include "TypesOfActions.h"
#include "TellerEvent.h"

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
	if(customers == 0 || tellers == 0){
		cout << "ERROR: Not Enough Customers or Tellers\n";
				exit(-1);
	}
	cout << "The simulation time entered: " << argv[3] << "\n";
	int simulationTime = atoi(argv[3]); // Simulation time in minutes
	cout << "The average service time entered: " << argv[4] << "\n";
	float averageServiceTime = atoi(argv[4]);


	//////////////////SIM 1//////////////////////////////
	if(argc >= 5 && atoi(argv[5]) != 0){
		srand(atoi(argv[5]));
		cout << "The random seed entered entered: " << argv[5] << "\n";
	}
	else{
		srand(5);
	}
	//Initializing necessary objects
	EventQueue *queue = new EventQueue();
	TellerList *Tell = new TellerList(*queue);

	for(int i = 0; i < customers; i++){
		float arrivalTime = simulationTime * (rand() / float(RAND_MAX));
		cout << "The random arrival time of customer:" << i << " is " <<
				arrivalTime << "\n";
		new CustEvent(*queue, arrivalTime);
	}
	//float serviceTime;
	for(int i = 0; i < tellers; i++){
		//Put teller initialization here
		float idleTime = 599/60 * (rand()/float(RAND_MAX))+1/60;
		cout << "The random idle time of Teller:" << i << " is " <<
						idleTime << "\n";
		(new TellerEvent(*queue, idleTime, *Tell))->InsertTellerToList();
		//put teller object initialization here later
	}


	float currentTime = 0;
	bool NoCustAtStartOfDay = false;
	bool firstRun = true;
	Event * nextEv = queue->GetTopEvent();
	float IdleTime = 0;
	if(nextEv->getTime() != 0){
		TellerEvent * teller;
				for(int i = 0; i < tellers; i++){
						teller = Tell->GetEvent(i+1);
						IdleTime = IdleTime + teller->idle(currentTime);

		}
				nextEv->AddEvent();
				NoCustAtStartOfDay = true;
	}

	float custBankTimes[customers];
	int custBankCount = 0;
	float stdDev = 0;
	int action;
	float ServTime = 0;
	float AverageTimeInBank = 0;
	float tempTimeOfAction;
	float MaxTimeInLine = 0;
	while(Tell -> GetPeopleInBank()!=0 || queue->EventQueueCusts()!=0){
		if(firstRun == false){
			nextEv = queue->GetTopEvent();
		}
	    else if (NoCustAtStartOfDay){
			nextEv = queue->GetTopEvent();
			NoCustAtStartOfDay =  false;
			firstRun = false;
		}
	    else if(firstRun){
			firstRun = false;
		}
		action = nextEv->getActionType();
		currentTime = nextEv->getTime();
		if(action == CustArrive){
			Tell->GetEvent(0)->tellerQue->insertQueue(*nextEv);
		}
		else if(action <= TellIdle){//if teller
			tempTimeOfAction = static_cast<TellerEvent*>(nextEv)->GetNextCustomer(currentTime,averageServiceTime);
			if(nextEv->getActionType()==TellIdle){
				IdleTime = IdleTime + tempTimeOfAction;
			}
			else{
				ServTime = ServTime + tempTimeOfAction;
			}
		}
		else if(action == CustService){
			float TimeInBank = (static_cast<CustEvent*>(nextEv))->CustLeaveBank();
			float TimeInLine = TimeInBank -(static_cast<CustEvent*>(nextEv)) -> getServTime();
			if(TimeInLine>MaxTimeInLine)
				MaxTimeInLine=TimeInLine;
			AverageTimeInBank = AverageTimeInBank + TimeInBank;
			custBankTimes[custBankCount] = TimeInBank;
			custBankCount++;
			delete nextEv;
		}
	}

	if(currentTime<simulationTime)
		IdleTime=IdleTime+tellers*(simulationTime-currentTime);
	for(int i = 0; i < customers; i++){
		stdDev = stdDev + (custBankTimes[i]-AverageTimeInBank/customers)*(custBankTimes[i]-AverageTimeInBank/customers);
	}
	stdDev = sqrt(stdDev/customers);
	cout << "--------Simulation 1--------"<<"\n";
	cout << "Customers Served: "<<customers<<"\n";
	cout << "Customer Service Time: "<<ServTime<<"min \n";
	cout << "Tellers: "<<tellers<<"\n";
	cout << "Queuing System: Single Queue"<<"\n";
	cout << "Average Time Spent in Bank: "<<(AverageTimeInBank/customers)<<"min \n";
	cout << "Standard Deviation: "<<stdDev<<"min \n";
	cout << "Max Wait Time: "<<MaxTimeInLine<<"min \n";
	cout << "Teller Idle Time: "<<IdleTime<<"min \n";
	delete queue;
	delete Tell;

	//////////////////SIM 2//////////////////////////////

	if(argc >= 5 && atoi(argv[5]) != 0){
		srand(atoi(argv[5]));
	}
	else{
		srand(5);
	}
	//Initializing necessary objects
	queue = new EventQueue();
	Tell = new TellerList(*queue);

	for(int i = 0; i < customers; i++){
		float arrivalTime = simulationTime * (rand() / float(RAND_MAX));
		new CustEvent(*queue, arrivalTime);
	}
	//float serviceTime;
	for(int i = 0; i < tellers; i++){
		//Put teller initialization here
		float idleTime = 599/60 * (rand()/float(RAND_MAX))+1/60;
		(new TellerEvent(*queue, idleTime, *Tell))->InsertTellerToList();
		//put teller object initialization here later
	}


	currentTime = 0;
	NoCustAtStartOfDay = false;
	firstRun = true;
	nextEv = queue->GetTopEvent();
	IdleTime = 0;
	if(nextEv->getTime() != 0){
		TellerEvent * teller;
				for(int i = 0; i < tellers; i++){
						teller = Tell->GetEvent(i+1);
						IdleTime = IdleTime + teller->idle(currentTime);

		}
				nextEv->AddEvent();
				NoCustAtStartOfDay = true;
	}
	custBankCount = 0;
	stdDev = 0;
	action = -10;
	ServTime = 0;
	AverageTimeInBank = 0;
	tempTimeOfAction=0;
	MaxTimeInLine = 0;
	while(Tell -> GetPeopleInBank()!=0 || queue->EventQueueCusts()!=0){
		if(firstRun == false){
			nextEv = queue->GetTopEvent();
		}
	    else if (NoCustAtStartOfDay){
			nextEv = queue->GetTopEvent();
			NoCustAtStartOfDay =  false;
			firstRun = false;
		}
	    else if(firstRun){
			firstRun = false;
		}
		action = nextEv->getActionType();
		currentTime = nextEv->getTime();
		if(action == CustArrive){

			int lineS = INT_MAX;//to find the line with the smallest size
			int i;
			TellerList *TellCust = new TellerList(*queue);
			//get smallest size of line
			for(i = 1; i <= Tell->getListLen(); i++){//do not add to ULTIqueue
				if((Tell->GetEvent(i))->linelength() < lineS){
					lineS=(Tell->GetEvent(i))->linelength();
				}
			}
			//get all the tellers which have this size of line
			for(i = 1; i <= Tell->getListLen(); i++){

				if((Tell->GetEvent(i))->linelength() == lineS ){
					TellCust->insertQueue(*(Tell->GetEvent(i)));
				}
			}
			//this throws everything off, as the randoms do not match up anymore,
			//however it is a requirement via the assignment.
			//oh well
			int randNum = rand() % (TellCust->getListLen())+1;
			TellCust->GetEvent(randNum)->tellerQue->insertQueue(*nextEv);
			delete TellCust;

		}


		else if(action <= TellIdle){//if teller
			tempTimeOfAction = static_cast<TellerEvent*>(nextEv)->GetNextCustomer(currentTime,averageServiceTime);
			if(nextEv->getActionType()==TellIdle){
				IdleTime = IdleTime + tempTimeOfAction;
			}
			else{
				ServTime = ServTime + tempTimeOfAction;
			}
		}
		else if(action == CustService){
			float TimeInBank = (static_cast<CustEvent*>(nextEv))->CustLeaveBank();
			float TimeInLine = TimeInBank -(static_cast<CustEvent*>(nextEv)) -> getServTime();
			if(TimeInLine>MaxTimeInLine)
				MaxTimeInLine=TimeInLine;
			AverageTimeInBank = AverageTimeInBank + TimeInBank;
			custBankTimes[custBankCount] = TimeInBank;
			custBankCount++;
			delete nextEv;
		}
	}

	if(currentTime<simulationTime)
		IdleTime=IdleTime+tellers*(simulationTime-currentTime);
	for(int i = 0; i < customers; i++){
		stdDev = stdDev + (custBankTimes[i]-AverageTimeInBank/customers)*(custBankTimes[i]-AverageTimeInBank/customers);
	}
	stdDev = sqrt(stdDev/customers);
	cout << "--------Simulation 2--------"<<"\n";
	cout << "Customers Served: "<<customers<<"\n";
	cout << "Customer Service Time: "<<ServTime<<"min \n";
	cout << "Tellers: "<<tellers<<"\n";
	cout << "Queuing System: Multiple Queues"<<"\n";
	cout << "Average Time Spent in Bank: "<<(AverageTimeInBank/customers)<<"min \n";
	cout << "Standard Deviation: "<<stdDev<<"min \n";
	cout << "Max Wait Time: "<<MaxTimeInLine<<"min \n";
	cout << "Teller Idle Time: "<<IdleTime<<"min \n";
	delete queue;
	delete Tell;
}
