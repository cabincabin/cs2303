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
  CustEvent(EventQueue &evQue, float time);

  float CustLeaveBank();
  float getServTime();
 ~CustEvent();

 void timeWithTeller(float currentTime, float TellTime);
};

#endif
