
#ifndef TellerEvent_H_
#define TellerEvent_H_
#include "Event.h"
class CustEvent;
class EventQueue;
class TellerEvent: public Event{
protected:
EventQueue *tellerQue;

public:
  TellerEvent(EventQueue &evQue, float time);

  ~TellerEvent();
  void idle(int currentTime);
  void GetNextCustomer();
  void AddCustToQue(CustEvent *cust);
  void AddCustomerToLine();
  int linelength();
};
#endif
