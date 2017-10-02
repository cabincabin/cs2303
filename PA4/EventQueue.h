//Header file for the event queue class

#ifndef EVENTQUEUE_H_
#define EVENTQUEUE_H_
//Event queue object
class Event;
class EventQueue{
	struct node{
			Event *event; // Stores a generic event object
			struct node *next; // the next node
			struct node *prev; // the previous node
		};
private:

	node* rootNode;
	void insertQueue(Event *eventIn, node *comparedNode);
	node* initEventInQueue(Event *eventIn); // initialize the eventqueue
	node* getRootNode();

public:
	EventQueue();

	// Sorted linked list based on time
	// Add something to the linked list
	// remove something from the head
	//Insert a something into the event queue
	bool emptyEventQueue();

	void insertQueue(Event &eventIn);

	~EventQueue();

};
#endif
