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


int CustEvent::timeAtBank(){
  return netTime - initTime;
}
