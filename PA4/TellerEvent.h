
#ifndef TellerEvent_H_
#define TellerEvent_H_
#include "Event.h"
#include "TellerList.h"
class CustEvent;
class EventQueue;
class TellerList;

class TellerEvent: public Event{
protected:

TellerList &tList;
public:
//cretes a new telerevent with the single EVentqueue, the idle time of the teller
//and the list of all tellers currently active
  TellerEvent(EventQueue &evQue, float time, TellerList &Tlist);
  //create an EventQueue of all custmers currently in the line
  EventQueue *tellerQue;
  ~TellerEvent();
  //have the teller idel, place in the single Eventqueue and return the idle time
  float idle(float currentTime);
  //inserts the teller to the overarching Tellerlist of all active tellers
  void InsertTellerToList();
  //returns the next customer in the telller's tellerQueue
  float GetNextCustomer(float CurrentTime, float averageServiceTime);
  //Add a customer to the tellers tellerqueque
  void AddCustToQue(CustEvent *cust);
  //get the length of the tellers tellerqueue
  int linelength();
};
#endif
