/*
 *  Event.cpp
 *
 *  Created on: Oct. 1st, 2017
 *  Author: Clayton Dembski & Floris van Rossum
 *  Purpose: Source file of Event class
 *
 */

/*****************************************************************/
// Include Statements:
#include "Event.h"
#include "EventQueue.h"
#include "TypesOfActions.h"

// Standard include files
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/*****************************************************************/

/**TellerEvent(EventQueue &evQue, float time)
 * Purpose: Constructor of the Event class
 * @param EventQueue &evQue A pointer to the main Eventqueue
 * @param float time The current time of the event
 */

Event::Event(EventQueue &evQue, float time):
initTime(time),
eventQue(evQue){
	action = 0;
	netTime = time;
}

/*****************************************************************/
/**void AddEvent()
 * Purpose: Add an event to the event queue
 * @return void
 */
void Event::AddEvent(){
  eventQue.insertQueue(*this);
}

/*****************************************************************/

/**float getTime()
 * Purpose: Return the time of the event
 * @return float Returns the time of the event
 */
float Event::getTime(){
  return netTime;
}

/*****************************************************************/

/**int getActionType()
 * Purpose: Get the action type required for the event
 * @return int Returns the number of action, look in TypesOfActions.h for
 * meaning of integers
 */
int Event::getActionType(){
  return action;
}
