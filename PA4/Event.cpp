#include "Event.h"
#include "EventQueue.h"
#include "TypesOfActions.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>



Event::Event(EventQueue &evQue, float time):
initTime(time),
eventQue(evQue){
	action = 0;
	netTime = time;
}

void Event::AddEvent(){
  eventQue.insertQueue(*this);
}

float Event::getTime(){
  return netTime;
}

int Event::getActionType(){
  return action;
}
