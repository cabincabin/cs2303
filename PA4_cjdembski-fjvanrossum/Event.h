#include "EventQueue.h"
#ifndef Event_H_
#define Event_H_

class Event {

public:

  Event();
  Event(EventQueue &evQue);


  void getTime();
  void getActionType();

 ~Event();

protected:
  void AddEvent();
  
  int action;
  const initTime;
  int netTime;
  EventQueue eventQue;
};

#endif
