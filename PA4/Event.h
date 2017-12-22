
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
  //creates a new event
  Event(EventQueue &evQue, float time);
  //gets the current time of the event
  float getTime();
  //gets the type f action of the event
  int getActionType();
  //adds self to the single EventQueue
  void AddEvent();

};

#endif
