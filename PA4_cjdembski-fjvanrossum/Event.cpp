#include "Event.h"
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
  eventQue.InsertQue(*this);
}

void Event::getTime(){
  return netTime;
}

void Event::getActionType(){
  return action;
}
