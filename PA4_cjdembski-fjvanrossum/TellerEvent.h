#include "Event.h"
#ifndef TellerEvent_H_
#define TellerEvent_H_

class CustEvent: public Event {

public:

  TellerEvent();
  TellerEvent(EventQueue &evQue, float time);

  void idle(int currentTime);

 ~TellerEvent();
};
#endif
