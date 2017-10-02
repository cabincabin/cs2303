#include "Event.h"
#include "EventQueue.h"
#include "TypesOfActions.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


Event::Event(){
}

Event::Event(EventQueue &evQue){
  eventQue = evQue;
}

void Event::AddEvent(){
  eventQue.InsertQueue(*this);
}

int Event::getTime(){
  return netTime;
}

Event Event::getActionType(){
  return action;
}
