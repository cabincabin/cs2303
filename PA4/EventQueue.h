//Header file for the event queue class
#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H
#include "Event.h"
//Event queue object
class EventQueue{
	struct node;
	int time;
	Event event;
	struct node *next;
	struct node *prev;
public:
	EventQueue();

	// Sorted linked list based on time
	// Add something to the linked list
	// remove something from the head
	//Insert a something into the event queue
	void insertQueue(Event eventIn, node comparedNode);
	bool emptyEventQueue();
	node* initEventQueue(); // initialize the eventqueue
	node* getRootNode();
	~EventQueue();

protected:

};

#endif
