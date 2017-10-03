
#ifndef TellerEvent_H_
#define TellerEvent_H_
#include "Event.h"
class TellerEvent: public Event{

public:
  TellerEvent(EventQueue &evQue, float time);

  ~TellerEvent();
  void idle(int currentTime);
};
#endif
