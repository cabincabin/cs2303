/*
 *  CustEvent.h
 *
 *  Created on: Oct. 1st, 2017
 *  Author: Clayton Dembski & Floris van Rossum
 *  Purpose: Header file of Customer Event Class
 */

#ifndef CustEvent_H_
#define CustEvent_H_
#include "Event.h"
class CustEvent: public Event{
float servTime;
public:
	//creates new customer which has the single Event queue and the initial time of arrival
  CustEvent(EventQueue &evQue, float time);
  //returns the total time in the bank
  float CustLeaveBank();
  //returns the service time of the customer
  float getServTime();
 ~CustEvent();
//puts the customer back in the event queue with the advanced time
 void timeWithTeller(float currentTime, float TellTime);
};

#endif
