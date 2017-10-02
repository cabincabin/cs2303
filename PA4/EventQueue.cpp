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
	Event * eventStart = new Event(*this, -10);
	rootNode = new node();
	rootNode -> event = eventStart;
	rootNode -> next = NULL; //Furthest up, smallest time
	rootNode -> prev = NULL;
}


// Insert an event into the event queue
void EventQueue::insertQueue(Event *eventIn, node *comparedNode){
	node *insertNode = initEventInQueue(eventIn);

	if(comparedNode -> event -> getTime() < insertNode -> event -> getTime() &&
			(comparedNode -> prev == NULL ||
			 comparedNode -> prev -> event -> getTime() > insertNode -> event -> getTime()) ){
		// eventIn needs to be inserted after comparedNode
		int a = 1;
		// because eventIn has a time that is larger or equal
		// and less than previous node

		insertNode -> next = comparedNode; // Set new node previous to the old node
		if(comparedNode->prev!=NULL){
			insertNode -> prev = comparedNode->prev;
			comparedNode -> prev -> next = insertNode;
		}

		comparedNode -> prev = insertNode; // Set old previous node
		// next field to new node

	}

	else if(comparedNode -> event -> getTime() < eventIn -> getTime() &&
			 comparedNode -> prev -> event -> getTime() < insertNode -> event -> getTime()){
		// comparedNode is earlier in even queue so continue searching
		insertQueue(eventIn,comparedNode -> prev); // recursively call
	}
}

void EventQueue::insertQueue(Event &eventIn){
	insertQueue(&eventIn, rootNode);

}
// Determine if the event queue is empty, returns true if true
bool EventQueue::emptyEventQueue(){
	return true;
}
//Create the event queue with event
EventQueue::node* EventQueue::initEventInQueue(Event *eventIn){
	node *Node = new node;
	Node -> event = eventIn;
	Node -> next = NULL;
	Node -> prev = NULL;
	return Node;
}

// gets the rootNode of the event queue
EventQueue::node* EventQueue::getRootNode(){
	return rootNode;
}
