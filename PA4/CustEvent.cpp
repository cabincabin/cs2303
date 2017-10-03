/*
 *  CustEvent.cpp
 *
 *  Created on: Oct. 1st, 2017
 *  Author: Clayton Dembski & Floris van Rossum
 *  Purpose: Header file of customer event class
 */

/*****************************************************************/
//Include statements
#include "CustEvent.h"
#include "TypesOfActions.h"
#include "Event.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/*****************************************************************/

/*
 * CustEvent(EventQueue &evQue, float time)
 * Purpose: Constructor of the CustEvent class
 * @param EventQueue &evQue A pointer to the main Eventqueue which the cust event
 * is to be stored in upon declaration
 * @param float time The arrival time of the customer event
 */
CustEvent::CustEvent(EventQueue &evQue, float time):
Event(evQue, time)
{
  netTime = time;
  action = CustArrive;
  AddEvent(); // Add customer arrival to event queue
}

/*
 * CustLeaveBank()
 * Purpose: Sets action of event to leave
 */
float CustEvent::CustLeaveBank(){
  action = CustLeave;
  return netTime - initTime;
}

/*
 * timeWithTeller()
 * @param currentTime The current program time
 * @param TellTime The time that the teller took
 * Purpose: Change the event action and calculate net time
 */
void CustEvent::timeWithTeller(float currentTime, float TellTime){
 netTime = currentTime + TellTime;
 action = CustService;
 AddEvent(); // Add customer to teller to event queue
}
