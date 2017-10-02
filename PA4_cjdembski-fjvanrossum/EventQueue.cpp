#include <stdio.h>
#include <conio.h>
#include <iostream>

#include EventQueue.h

struct node {
	int time;
	Event event; // Stores a generic event object
	struct node *next; // the next node
};

// event.getTime()
public:
	// Insert an event into the event queue
	void insertQueue(Event event, Event firstEvent){
		if(firstEvent.getTime)
	}
	// Determine if the event queue is empty, returns true if true
	bool emptyEventQueue(){

	}
	//Create the event queue with event
	void initEventQueue(Event eventIn){
		node = new node;
		node -> event = eventIn;
		node -> next = NULL;
	}

class eventQueue{
	public:
	node rootNode;
	void insertQueue(Event event);
	bool emptyEventQueue();
};

//Can there be multiple events of the same event class in the queue:
// Not of the same object but yes for the same class.
