/*
 * qSim.cpp
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

//Header Files for own files
#include "Event.h"
#include "EventQueue.h"
#include "CustEvent.h"
#include "TellerList.h"
#include "TypesOfActions.h"
#include "TellerEvent.h"

/*****************************************************************/

/**int main(int argc, char ** argv)
 * Purpose: Main function of the program
 * @param argc Number of user input arguments
 * @param char ** argv String array of all user input command arguments
 * @return int Error Number, (0 == Success)
 */
int main(int argc, char ** argv){
	// Format of arguments entered in command line:
	// ./qSim #customers #tellers simulationTime averageServiceTime <seed>

	// Checks whether enough commands have been entered
	if(argc < 5){
		// Not enough commands entered: print out error and exit program
		cout << "ERROR: Incorrect Command Line Input \n";
		exit(-1);
	}

	// Print out all user input for verification and troubleshooting
	cout << "The number of customers entered: " << argv[1] << "\n";
	int customers = atoi(argv[1]);
	cout << "The number of tellers entered: " << argv[2] << "\n";
	int tellers = atoi(argv[2]);
	// Checks whether a correct number of customers and tellers has been entered
	if(customers == 0 || tellers == 0){
		// Not enough customers or tellers so print error message and exit
		// program
		cout << "ERROR: Not Enough Customers or Tellers\n";
		exit(-1);
	}
	cout << "The simulation time entered: " << argv[3] << "\n";
	int simulationTime = atoi(argv[3]); // Simulation time in minutes
	cout << "The average service time entered: " << argv[4] << "\n";
	float averageServiceTime = atoi(argv[4]);

	/*****************************************************************/
	//////////////////SIM 1//////////////////////////////

	// Sets random seed if user specifies otherwise use a random seed
	if(argc >= 6 && atoi(argv[5]) != 0){
		// User has specified a random seed so use it
		srand(atoi(argv[5]));
		cout << "The random seed entered entered: " << argv[5] << "\n";
	}

	// Initializing necessary objects
	EventQueue *queue = new EventQueue(); // Event Queue Constructor
	TellerList *Tell = new TellerList(*queue); // TellerList Constructor

	// Create customers number of CustEvents
	// Pre-condition: customers is a non-zero user specified number
	for(int i = 0; i < customers; i++){
		// Generate a random arrival time
		float arrivalTime = simulationTime * (rand() / float(RAND_MAX));
		cout << "The random arrival time of customer:" << i << " is " <<
				arrivalTime << "\n";
		new CustEvent(*queue, arrivalTime); // Initialize a new CustEvent
		// LOOP-INVARIANT: There are now i number of CustEvents in EventQueue
	}

	// Create tellers number of TellerEvent
	// Pre-condition: tellers is a non-zero user specified number
	for(int i = 0; i < tellers; i++){
		// Generate a random idle time for a teller
		float idleTime = 599/60 * (rand()/float(RAND_MAX))+1/60;
		cout << "The random idle time of Teller:" << i << " is " <<
						idleTime << "\n";
		// Create a new teller event with the random idletime and insert in
		// Teller list
		(new TellerEvent(*queue, idleTime, *Tell))->InsertTellerToList();
		// LOOP-INVARIANT: TellerEvent is initialized with a random idle time
		// and inserted in TellerList
	}

	// Initialize boolean flags and variables
	float currentTime = 0;
	bool NoCustAtStartOfDay = false;
	bool firstRun = true;
	float IdleTime = 0;

	// Create Event object nextEv which is the next event
	// from the Event Queue
	Event * nextEv = queue->GetTopEvent();

	// Ensures that the nextEv does not have an arrival time of 0
	if(nextEv->getTime() != 0){
		// nextEv time is not 0, so start idling of tellers
		TellerEvent * teller;
		// Pre-condition: TellerEvent teller has been initialized
		// and all teller objects have been initialized with
		// a random idle time.
		for(int i = 0; i < tellers; i++){
			// Start idling all tellers
			teller = Tell->GetEvent(i+1);
			IdleTime = IdleTime + teller->idle(currentTime);
			// LOOP-INVARIANT: idleTime is equal to the idle time of i Tellers
			// together
		}
		nextEv->AddEvent(); // return next event to the event queue
		NoCustAtStartOfDay = true; // Set a boolean flag, no customers at
		// beginning of the day
	}

	// Initialize or declare variables
	float custBankTimes[customers];
	int custBankCount = 0;
	float stdDev = 0;
	int action;
	float ServTime = 0;
	float AverageTimeInBank = 0;
	float tempTimeOfAction;
	float MaxTimeInLine = 0;

	// Pre-condition: There are customers in the bank (event queue or tellerlists)
	while(Tell -> GetPeopleInBank()!=0 || queue->EventQueueCusts()!=0){

		// This conditional statement gets the first event from event queue
		// and toggles the boolean flags depending on initial condition
		if(firstRun == false){
			// Currently nextEv is not updated so update it
			nextEv = queue->GetTopEvent();
		}
	    else if (NoCustAtStartOfDay){
	    	// If there are no customers with time 0 do the following
			nextEv = queue->GetTopEvent(); // Get the next event
			NoCustAtStartOfDay =  false;
			firstRun = false;
		}
	    else if(firstRun){
	    	// This is the first run, so reset flag and do not get new event
			firstRun = false;
		}

		action = nextEv->getActionType(); // Get the action of the next event
		currentTime = nextEv->getTime(); /* Set the time of main program to
		the time of the next event */

		// Controls what methods to call based on action of the event
		// from the event queue
		if(action == CustArrive) {
			// Event is a customer arrival, insert customer into a teller queue
			Tell->GetEvent(0)->tellerQue->insertQueue(*nextEv);
		}
		else if(action <= TellIdle) {
			// Event is a Teller Event

			// Get the time of the Teller Event
			tempTimeOfAction = static_cast<TellerEvent*>(nextEv) ->
					GetNextCustomer(currentTime,averageServiceTime);

			// If teller event is Idle Event
			if(nextEv->getActionType()==TellIdle){
				// Next event from event queue is an idling teller
				IdleTime = IdleTime + tempTimeOfAction; /* increment idleTime
				 with next action idle time*/
			}
			else{
				// The Teller event is a customer service event
				ServTime = ServTime + tempTimeOfAction; /* Increment
				service time with the service time of the next event */
			}
		}
		else if(action == CustService){
			// Event is a customer service

			// Set customers time in bank
			float TimeInBank = (static_cast<CustEvent*>(nextEv))->CustLeaveBank();
			// Set customers time in bank
			float TimeInLine = TimeInBank -(static_cast<CustEvent*>(nextEv))
					-> getServTime();

			// This conditional statement controls the maximum time a customer
			// has spent in line
			if(TimeInLine>MaxTimeInLine)
				MaxTimeInLine=TimeInLine; // New max is found so update variable

			// Perform statistics calculations
			AverageTimeInBank = AverageTimeInBank + TimeInBank;
			custBankTimes[custBankCount] = TimeInBank;
			custBankCount++;

			// properly delete nextEv Event object
			delete nextEv;
			// LOOP-INVARIANT: An event from the event queue has been processed and
			// the nextEv object has been deleted
		}
	}

	// Update the idle time of the tellers if end of day is not yet reached
	if(currentTime<simulationTime)
		IdleTime=IdleTime+tellers*(simulationTime-currentTime);

	// Pre-condition: All customers have been handled in the bank
	for(int i = 0; i < customers; i++){
		stdDev = stdDev + (custBankTimes[i]-AverageTimeInBank/customers)*(custBankTimes[i]-AverageTimeInBank/customers);
		// LOOP-INVARIANT: i is less than the number of customers
	}
	stdDev = sqrt(stdDev/customers);

	// Print out the statistics of the first simulation
	cout << "--------Simulation 1--------"<<"\n";
	cout << "Customers Served: "<<customers<<"\n";
	cout << "Time Required to Serve All Customers: "<<currentTime<<" min \n";
	cout << "Tellers: "<<tellers<<"\n";
	cout << "Queuing System: Single Queue"<<"\n";
	cout << "Average Time Spent in Bank: "<<(AverageTimeInBank/customers)<<" min \n";
	cout << "Standard Deviation: "<<stdDev<<" min \n";
	cout << "Max Wait Time: "<<MaxTimeInLine<<" min \n";
	cout << "Teller Service Time: " << ServTime << " min \n";
	cout << "Teller Idle Time: "<<IdleTime<<" min \n";

	// Free the objects used
	delete queue;
	delete Tell;

	/*****************************************************************/
	//////////////////SIM 2//////////////////////////////

	// Controls setting of random seed
	if(argc >= 6 && atoi(argv[5]) != 0){
		// User has specified a random seed
		srand(atoi(argv[5])); // Use user-specified seed
	}

	// Initializing necessary objects
	queue = new EventQueue();
	Tell = new TellerList(*queue);

	// Initializing all customer arrival events
	// Pre-condition: Queue has been initialized and customers is a
	// user specified non-zero number
	for(int i = 0; i < customers; i++){
		float arrivalTime = simulationTime * (rand() / float(RAND_MAX));
		new CustEvent(*queue, arrivalTime);
		// LOOP-INVARIANT: A customer object has been initialized with a random
		// arrival time
	}

	// Initializing all tellers
	// Pre-condition: Queue has been initialized and tellers is a
	// user specified non-zero number
	for(int i = 0; i < tellers; i++){
		float idleTime = ((599/60) * (rand()/float(RAND_MAX))) + 1/60;
		// Prevent 0 idle time
		(new TellerEvent(*queue, idleTime, *Tell))->InsertTellerToList();
		// LOOP-INVARIANT: A teller event has been created with a random idle
		// time
	}

	// Set new values for previously used variables
	// reset flags
	currentTime = 0;
	NoCustAtStartOfDay = false;
	firstRun = true;
	nextEv = queue->GetTopEvent();
	IdleTime = 0;

	// Double-checks if there are customers with an arrival time of 0
	if(nextEv->getTime() != 0){
		// No customer with arrival time 0
		TellerEvent * teller;

		// Set all tellers to idle with idle times
		// Pre-condition: Tellers have been initialized with a random
		// idle time
		for(int i = 0; i < tellers; i++){
			teller = Tell->GetEvent(i+1);
			IdleTime = IdleTime + teller->idle(currentTime);
			// Loop-invariant: IdleTime is now the sum idle time of all
			// previously called tellers' idle time
		}
		nextEv->AddEvent(); // Return the next event to the queue
		NoCustAtStartOfDay = true; // Set boolean flag
	}

	// Reset variables and statistics
	custBankCount = 0;
	stdDev = 0;
	action = -10;
	ServTime = 0;
	AverageTimeInBank = 0;
	tempTimeOfAction=0;
	MaxTimeInLine = 0;

	// This loop sorts through all events in the event queue until all customers
	// have left the bank
	// Pre-condition: There are customers in the bank (event queue or tellerlists)
	while(Tell -> GetPeopleInBank()!=0 || queue->EventQueueCusts()!=0){

		// Controls action on first event in event queue
		if(firstRun == false){
			// If this is not the first run, get the next event
			// from the event queue
			nextEv = queue->GetTopEvent();
		}
	    else if (NoCustAtStartOfDay){
	    	// There is no customer with time of 0
			nextEv = queue->GetTopEvent(); // get the next customer
			// Set boolean flags
			NoCustAtStartOfDay =  false;
			firstRun = false;
		}
	    else if(firstRun){
	    	// This is the first run, so reset flag and do not get new event
			firstRun = false;
		}

		action = nextEv->getActionType(); // Get action type of next event
		currentTime = nextEv->getTime(); // Set the current time

		// Performs action based on action type of event
		if(action == CustArrive){
			int lineS = INT_MAX; // Find the teller queue with least amount of
			// customer events
			int i; // Count variable
			TellerList *TellCust = new TellerList(*queue);

			// This for loop gets smallest teller queue length
			// Pre-condition: All teller queues have been initialized
			for(i = 1; i <= Tell -> getListLen(); i++) {
				// Do not look at teller queue 0
				if( (Tell -> GetEvent(i)) -> linelength() < lineS){
					lineS=(Tell->GetEvent(i))->linelength();
				}
				// LOOP-INVARIANT: The length of the teller queue Tell has
				// been checked
			}

			// Finds all the teller queues which have this size of line
			// as determined in loop above
			// Pre-condition: The variable lineS is a real number and
			// all teller queues have been initialized
			for(i = 1; i <= Tell -> getListLen(); i++){
				if((Tell->GetEvent(i))->linelength() == lineS ){
					TellCust->insertQueue(*(Tell->GetEvent(i)));
				}
				// LOOP-INVARIANT: The teller Tell's queue length has been checked, minimum size
				// has been found
			}

			// This throws everything off, as the randoms do not match up anymore,
			// however it is a requirement via the assignment.

			// Get a random teller queue
			int randNum = rand() % (TellCust->getListLen())+1;
			TellCust->GetEvent(randNum)->tellerQue->insertQueue(*nextEv);

			// Delete the used objects
			delete TellCust;
		}
		else if(action <= TellIdle) {
			// Action is an idling teller
			// Get the time of the next Teller Event action
			tempTimeOfAction = static_cast<TellerEvent*>(nextEv) ->
					GetNextCustomer(currentTime,averageServiceTime);

			// Controls time of action based on action type
			if(nextEv->getActionType()==TellIdle){
				// Action is idling teller
				// Increment idle time by time of action above
				IdleTime = IdleTime + tempTimeOfAction;
			}
			else{
				// Action is a service time
				// Increment the service time by the time of  the action above
				ServTime = ServTime + tempTimeOfAction;
			}
		}
		else if(action == CustService){
			// nextEv is a customer service event

			// Update variables later used to calculate statistics
			float TimeInBank = (static_cast<CustEvent*>(nextEv))->CustLeaveBank();
			float TimeInLine = TimeInBank -(static_cast<CustEvent*>(nextEv)) -> getServTime();
			// Update the maximum time spent in line
			if(TimeInLine>MaxTimeInLine)
				MaxTimeInLine=TimeInLine;
			// Add the time in bank to a total
			AverageTimeInBank = AverageTimeInBank + TimeInBank;
			custBankTimes[custBankCount] = TimeInBank;
			custBankCount++;

			// delete used objects
			delete nextEv;
		}
	}

	// Start idling tellers if end of simulation is not yet reached
	if(currentTime<simulationTime)
		IdleTime=IdleTime+tellers*(simulationTime-currentTime);

	// Calculate the standard deviation
	// Pre-condition: All customers have gone through the bank and been serviced
	for(int i = 0; i < customers; i++){
		stdDev = stdDev + (custBankTimes[i]-AverageTimeInBank/customers)*(custBankTimes[i]-AverageTimeInBank/customers);
		// LOOP-INVARIANT: i is less than the number of customers
	}
	stdDev = sqrt(stdDev/customers);

	// Print out all statistics
	cout << "--------Simulation 2--------"<<"\n";
	cout << "Customers Served: "<<customers<<"\n";
	cout << "Time Required to Serve All Customers: "<<currentTime<<" min \n";
	cout << "Tellers: "<<tellers<<"\n";
	cout << "Queuing System: Multiple Queues"<<"\n";
	cout << "Average Time Spent in Bank: "<<(AverageTimeInBank/customers)<<"min \n";
	cout << "Standard Deviation: "<<stdDev<<"min \n";
	cout << "Max Wait Time: "<<MaxTimeInLine<<"min \n";
	cout << "Teller Service Time: " << ServTime << " min \n";
	cout << "Teller Idle Time: "<<IdleTime<<"min \n";

	// Delete all used objects
	delete queue;
	delete Tell;
}
