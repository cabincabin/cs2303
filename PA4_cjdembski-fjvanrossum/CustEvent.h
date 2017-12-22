#include "Event.h"
#ifndef CustEvent_H_
#define CustEvent_H_

class CustEvent: public Event {

public:
  CustEvent();
  CustEvent(EventQueue &evQue, float time);

  int timeAtBank();

 ~CustEvent();

};

#endif
