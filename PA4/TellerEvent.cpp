#include "TellerEvent.h"
#include "CustEvent.h"
#include "TypesOfActions.h"
#include "Event.h"
#include "EventQueue.h"
#include "TellerList.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


TellerEvent::TellerEvent(EventQueue &evQue, float time, TellerList &Tlist):
Event(evQue, time),
tList(Tlist)
{
  action = TellIdle;
  netTime = time;
  AddEvent();
  tellerQue = new EventQueue();
}

void TellerEvent::idle(int currentTime){
  action = TellIdle;
  netTime = currentTime + initTime;
  AddEvent();
}

void TellerEvent::GetNextCustomer(){
	action = TellGetCust;
	if(tellerQue->getQueueLen()!=0){
	}
}

void TellerEvent::AddCustToQue(CustEvent *cust){
	if(cust->getActionType() == CustArrive)
	tellerQue->insertQueue(*cust);
}

int TellerEvent::linelength(){
	return tellerQue->getQueueLen();
}
