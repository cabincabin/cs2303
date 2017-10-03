#include "CustEvent.h"
#include "TypesOfActions.h"
#include "Event.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


CustEvent::CustEvent(EventQueue &evQue, float time):
Event(evQue, time)
{
  netTime = time;
  action = CustArrive;
  AddEvent();
}

float CustEvent::CustLeaveBank(){
  action = CustLeave;
  return netTime - initTime;
}

void CustEvent::timeWithTeller(float currentTime, float TellTime){
 netTime = currentTime + TellTime;
 action = CustService;
 AddEvent();
}
