#include "TellerEvent.h"
#include "TypesOfActions.h"
#include "Event.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


TellerEvent::TellerEvent(EventQueue &evQue, float time):
Event(evQue, time)
{
  action = TellIdle;
  netTime = time;
  AddEvent();
}

void TellerEvent::idle(int currentTime){
  action = TellIdle;
  netTime = currentTime + initTime;
  AddEvent();
}
