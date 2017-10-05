
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
  TellerEvent(EventQueue &evQue, float time, TellerList &Tlist);
  EventQueue *tellerQue;
  ~TellerEvent();
  float idle(float currentTime);
  void InsertTellerToList();
  float GetNextCustomer(float CurrentTime, float averageServiceTime);
  void AddCustToQue(CustEvent *cust);
  void AddCustomerToLine();
  int linelength();
};
#endif
