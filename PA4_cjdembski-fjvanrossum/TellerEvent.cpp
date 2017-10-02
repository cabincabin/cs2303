#include "TellerEvent.h"
#include "TypesOfActions.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

TelerEvent::TellerEvent(){
  printf("ERROR: No Event Queue");
  exit(0);
}

TellerEvent::TellerEvent(EventQueue &evQue, float time):
Event(evQue, float time),
initTime(time)
{
  Action = TellIdle;
  netTime = time;
}

void idle(int currentTime){
  Action = TellIdle;
  netTime = currentTime + initTime;
  AddEvent();
}
