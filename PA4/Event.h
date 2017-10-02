
#ifndef EVENT_H_
#define EVENT_H_

class EventQueue;
class Event {

protected:
  int action;
  const int initTime;
  int netTime;
  EventQueue &eventQue;


public:

  Event(EventQueue &evQue, int time);
  int getTime();
  int getActionType();
  void AddEvent();
 ~Event();


};

#endif
