
#ifndef EVENT_H_
#define EVENT_H_

class EventQueue;
class Event {

public:
  int action;
  const float initTime;
  float netTime;
  EventQueue &eventQue;




  Event(EventQueue &evQue, float time);
  float getTime();
  int getActionType();
  void AddEvent();
 ~Event();


};

#endif
