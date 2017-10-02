#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "Event.h"
#include "EventQueue.h"
#include "TypesOfActions.h"


//Event event = new Event();
//Event blankEvent = new Event();
//struct node;

EventQueue::EventQueue(){
}

// Insert an event into the event queue
void EventQueue::insertQueue(Event *eventIn, node *comparedNode){
	if(comparedNode -> event -> getTime() >= eventIn -> getTime()){
		// eventIn needs to be inserted before comparedNode
		// because eventIn has a time that is smaller or equal
		node insertNode; // Create a new node

		insertNode.prev = comparedNode -> prev; // Set new node previous

		*comparedNode -> prev -> next = insertNode; // Set old previous node
		// next field to new node

		*comparedNode -> prev = insertNode; // Set the comparedNode previous to
		// new node
	}
	if(comparedNode -> event -> getTime() < eventIn -> getTime()){
		// comparedNode is earlier in even queue so continue searching
		insertQueue(eventIn,comparedNode -> next); // recursively call
	}
}

void EventQueue::insertQueue(Event &eventIn){
	Event *Ev = &eventIn;

}
// Determine if the event queue is empty, returns true if true
bool EventQueue::emptyEventQueue(){
	return true;
}
//Create the event queue with event
EventQueue::node* EventQueue::initEventQueue(Event *eventIn){
	node *Node = new node;
	Node -> event = eventIn;
	Node -> next = NULL;
	Node -> prev = NULL;
	return Node;
}

// gets the rootNode of the event queue
EventQueue::node* EventQueue::getRootNode(){
	return &rootNode;
}
