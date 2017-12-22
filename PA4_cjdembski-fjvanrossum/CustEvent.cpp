#include "CustEvent.h"
#include "TypesOfActions.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

CustEvent::CustEvent(){
  printf("ERROR: No Event Queue");
  exit(0);
}

CustEvent::CustEvent(EventQueue &evQue, float time):
Event(evQue, float time),
initTime(time)
{
  Action = CustArrive;
  netTime = time;
  AddEvent();
}


int CustEvent::timeAtBank(){
  return netTime - innitTime;
}
