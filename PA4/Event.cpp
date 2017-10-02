#include "Event.h"
#include "EventQueue.h"
#include "TypesOfActions.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>



Event::Event(EventQueue &evQue, int time):
initTime(time),
eventQue(evQue){
	action = 0;
	netTime = 0;
}

void Event::AddEvent(){
  eventQue.insertQueue(*this);
}

int Event::getTime(){
  return netTime;
}

int Event::getActionType(){
  return action;
}
