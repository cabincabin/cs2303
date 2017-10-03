
#ifndef TellerEvent_H_
#define TellerEvent_H_
#include "Event.h"
#include "TellerList.h"
class CustEvent;
class EventQueue;
class TellerList;

class TellerEvent: public Event{
protected:
EventQueue *tellerQue;
TellerList &tList;
public:
  TellerEvent(EventQueue &evQue, float time, TellerList &Tlist);

  ~TellerEvent();
  void idle(int currentTime);
  void GetNextCustomer();
  void AddCustToQue(CustEvent *cust);
  void AddCustomerToLine();
  int linelength();
};
#endif
