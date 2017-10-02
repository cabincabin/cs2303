#ifndef Event_H_
#define Event_H_

class Event {

public:
  Event();
  Event(EventQueue evQue);

  void AddEvent();
  void getTime();
  void getActionType();

 ~Event();
private:
  const inittime;
  int actionTime;

};

#endif
