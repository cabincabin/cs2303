
#ifndef CustEvent_H_
#define CustEvent_H_
#include "Event.h"
class CustEvent: public Event{

public:
  CustEvent(EventQueue &evQue, float time);

  float CustLeaveBank();

 ~CustEvent();

 void timeWithTeller(float currentTime, float TellTime);
};

#endif
