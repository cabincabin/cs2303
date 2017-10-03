
#ifndef CustEvent_H_
#define CustEvent_H_
#include "Event.h"
class CustEvent: public Event{

public:
  CustEvent(EventQueue &evQue, float time);

  int timeAtBank();

 ~CustEvent();

};

#endif
