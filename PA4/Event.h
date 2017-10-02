
#ifndef EVENT_H_
#define EVENT_H_
#include "EventQueue.h"
class Event {

public:

  Event();
  Event(EventQueue &evQue);


  int getTime();
  int getActionType();
  void AddEvent();
 ~Event();

protected:
  int action;
  const int initTime;
  int netTime;
  EventQueue eventQue;
};

#endif
