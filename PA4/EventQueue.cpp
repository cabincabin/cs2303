#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "EventQueue.h"
#include "Event.h"
#include "TypesOfActions.h"


Event event = new Event();
Event blankEvent = new Event();

struct node {
	int time;
	Event event; // Stores a generic event object
	struct node *next; // the next node
	struct node *prev; // the previous node
};
node rootNode;

EventQueue::EventQueue(){
	rootNode = initEventQueue();
};

// Insert an event into the event queue
void EventQueue::insertQueue(Event eventIn, node comparedNode){
	if(comparedNode.event.getTime() >= eventIn.getTime()){
		// eventIn needs to be inserted before comparedNode
		// because eventIn has a time that is smaller or equal
		node insertNode = new node; // Create a new node

		insertNode.time = eventIn.getTime(); // Set time of new node

		insertNode.prev = comparedNode.prev; // Set new node previous

		comparedNode.prev -> next = insertNode; // Set old previous node
		// next field to new node

		comparedNode.prev = insertNode; // Set the comparedNode previous to
		// new node
	}
	if(comparedNode.event.getTime() < eventIn.getTime()){
		// comparedNode is earlier in even queue so continue searching
		insertQueue(eventIn,comparedNode.next); // recursively call
	}
}
// Determine if the event queue is empty, returns true if true
bool EventQueue::emptyEventQueue(){
	return true;
}
//Create the event queue with event
node* EventQueue::initEventQueue(){
	node = new node;
	Event blankEvent = new Event(); // UPDATE THIS LATER
	node.event = blankEvent;
	node.next = NULL;
	return node;
}

// gets the rootNode of the event queue
node* EventQueue::getRootNode(){
	return rootNode;
}




