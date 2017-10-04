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

void TellerEvent::idle(int currentTime){//WHEN PULLED OUT CHANGE action TO TELLGETCUST
  action = TellIdle;
  netTime = currentTime + initTime;
  AddEvent();
}

void TellerEvent::InsertTellerToList(){
	tList.insertQueue(*this);
}

void TellerEvent::GetNextCustomer(int CurrentTime, float averageServiceTime){
	action = TellGetCust;
	CustEvent * cust;
	if(linelength()!=0){
		 cust = static_cast<CustEvent*>(tellerQue->GetTopEvent());
	}

	else{
		int i;
		TellerList *TellCust = new TellerList(eventQue);
		for(i = 0; i <= tList.getListLen(); i++){

			if((tList.GetEvent(i))->linelength() !=0 ){
				TellCust->insertQueue(*tList.GetEvent(i));
			}
		}
		if(TellCust->getListLen()==0){
				idle(CurrentTime);//can change action
		}
		else{
			cust = static_cast<CustEvent*>(TellCust->GetEvent(
					 rand() % (TellCust->getListLen()+1) )->
					tellerQue->GetTopEvent());
		}

	}
	if(action == TellGetCust){
		float serviceTime = 2*averageServiceTime*rand()/float(RAND_MAX);
		cust->timeWithTeller(CurrentTime,serviceTime);
		netTime = CurrentTime + serviceTime;
		AddEvent();
	}
}

void TellerEvent::AddCustToQue(CustEvent *cust){
	if(cust->getActionType() == CustArrive)
		tellerQue->insertQueue(*cust);
}

int TellerEvent::linelength(){
	return tellerQue->getQueueLen();
}
