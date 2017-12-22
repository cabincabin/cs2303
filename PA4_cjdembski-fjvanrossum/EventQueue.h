//Header file for the event queue class
#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H

//Event queue object
class EventQueue{

public:
  EventQueue();
  EventQueue();

  // Sorted linked list based on time
  // Add something to the linked list
  // remove something from the head

  //Insert a something into the event queue
  void insertQueue(Event event);

private:
  node * initEventQueue(); // initialize the eventqueue

};

#endif
