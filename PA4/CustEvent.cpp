#include "CustEvent.h"
#include "TypesOfActions.h"
#include "Event.h"
#include "EventQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


CustEvent::CustEvent(EventQueue &evQue, float time):
netTime(time),
eventQue(evQue){
  netTime = time;
  action = CustArrive;
  AddEvent();
}


int CustEvent::timeAtBank(){
  return netTime - initTime;
}
