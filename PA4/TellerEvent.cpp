/*
 * TellerEvent.cpp
 *
 *  Created on: Oct 2, 2017
 *      Author: Floris van Rossum & Clayton Dembski
 *  Purpose: Source file of the teller event class
 */

/*****************************************************************/
// Include Statements:
// Our own include statements
#include "TellerEvent.h"
#include "CustEvent.h"
#include "TypesOfActions.h"
#include "Event.h"
#include "EventQueue.h"
#include "TellerList.h"

//Standard include files
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/*****************************************************************/

/*
 * TellerEvent(EventQueue &evQue, float time, TellerList &TList)
 * Purpose: Constructor of the TellerEvent class
 * @param EventQueue &evQue A pointer to the main Eventqueue which the cust event
 * is to be stored in upon declaration
 * @param float time The idle time of the teller
 * @param TellerList &Tlist Pointer to the relevant teller queue
 */
TellerEvent::TellerEvent(EventQueue &evQue, float time, TellerList &Tlist):
Event(evQue, time),
tList(Tlist)
{
  action = TellIdle;
  netTime = time;
  tellerQue = new EventQueue();
}

/*****************************************************************/

/*
 * float idle(float currentTime)
 * Purpose: Add event to idle
 * @param float currentTime The current time of the simulation which is used
 * to calculate the time of the event
 * @return float Returns the time of the Idle event
 */
float TellerEvent::idle(float currentTime){//WHEN PULLED OUT CHANGE action TO TELLGETCUST
  action = TellIdle;
  netTime = currentTime + initTime;
  AddEvent();
  return initTime;
}

/*****************************************************************/

/*
 * void InsertTellerToList()
 * Purpose: Add teller event to list of all tellers
 * @param void
 * @return void
 */
void TellerEvent::InsertTellerToList(){
	tList.insertQueue(*this);
}

/*****************************************************************/

/*
 * float GetNextCustomer(float currentTime, float averageServiceTime)
 * Purpose: Get the next customer event from the teller queue with a specific
 * time
 * @param float averageServiceTime The service time of the program
 * @param float CurrentTime The current time of the simulation
 */
float TellerEvent::GetNextCustomer(float CurrentTime, float averageServiceTime){

	action = TellGetCust;
	CustEvent * cust;

	// If the length of the tellerQueue is not 0
	if(linelength()!=0){
		// Get the next event from the teller queue
		cust = static_cast<CustEvent*>(tellerQue->GetTopEvent());
	}
	else{
		// teller queue is 0 so check other teller queues
		int i;

		// Initialize teller queue
		TellerList *TellCust = new TellerList(eventQue);

		// Looks at all tellers with lines greater than 0
		for(i = 0; i <= tList.getListLen(); i++){
			if(( tList.GetEvent(i)) -> linelength() !=0 ){
				// Adds teller to list of tellers with non-zero queues
				TellCust->insertQueue(*tList.GetEvent(i));
			}
		}
		// Checks if the list of tellers is not 0
		if(TellCust -> getListLen() == 0){
			// Teller queue is 0 so return the idle time
			return idle(CurrentTime);//can change action
		}
		else{
			// Get a customer from a random teller queue which is not 0
			int randNum = rand() % (TellCust->getListLen())+1;
			cust = static_cast<CustEvent*>(TellCust->GetEvent(randNum)->
					tellerQue->GetTopEvent());
		}

		// delete used objects
		delete TellCust;
	}

	// If the action is a get customer action
	if(action == TellGetCust){
		// Service the customer and return to event queue
		float serviceTime = 2*averageServiceTime*rand()/float(RAND_MAX);
		cust->timeWithTeller(CurrentTime,serviceTime);
		netTime = CurrentTime + serviceTime;
		AddEvent();
		return serviceTime; // return the time taken to service
	}
	return 0; // Default return
}

/*****************************************************************/

/*
 * void AddCustToQue(CustEvent *cust)
 * Purpose: Add a customer event to the teller queue
 * @param CustEvent *cust The customer event to be added to the queue
 * @return void
 */
void TellerEvent::AddCustToQue(CustEvent *cust){
	// If action type is a customer arrival insert in the queue
	if(cust->getActionType() == CustArrive)
		tellerQue->insertQueue(*cust);
}

/*****************************************************************/

/*
 * int linelength()
 * Purpose: Return the length of the teller queue
 * @return int Return the length of the teller queue
 */
int TellerEvent::linelength(){
	return tellerQue->getQueueLen();
}

/*****************************************************************/

/*
 * ~TellerEvent()
 * Purpose: TellerEvent destructor
 */
TellerEvent::~TellerEvent(){
	free(this);
}
