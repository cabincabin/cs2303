
#ifndef EVENT_H_
#define EVENT_H_

class EventQueue;
class Event {

protected:
  int action;
  const float initTime;
  float netTime;
  EventQueue &eventQue;



public:
  Event(EventQueue &evQue, float time);
  float getTime();
  int getActionType();
  void AddEvent();

};

#endif
