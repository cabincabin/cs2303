//Header file for the event queue class
class Event;
#ifndef EVENTQUEUE_H_
#define EVENTQUEUE_H_
#include "Event.h"
//Event queue object
class EventQueue{

private:
	struct node{
		Event *event; // Stores a generic event object
		struct node *next; // the next node
		struct node *prev; // the previous node
	};

public:
	EventQueue();

	// Sorted linked list based on time
	// Add something to the linked list
	// remove something from the head
	//Insert a something into the event queue
	void insertQueue(Event &eventIn, node &comparedNode);
	bool emptyEventQueue();
	node* initEventQueue(Event &eventIn); // initialize the eventqueue
	node* getRootNode();
	~EventQueue();

};
#endif
