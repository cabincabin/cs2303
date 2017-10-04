/*
 *  EventQueue.cpp
 *
 *  Created on: Oct. 1st, 2017
 *  Author: Clayton Dembski & Floris van Rossum
 *  Purpose: Source file of EventQueue class
 *
 */
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "Event.h"
#include "EventQueue.h"
#include "TypesOfActions.h"

/*****************************************************************/

/*
 * EventQueue()
 * Purpose: Constructor of the EventQueue class
 */
EventQueue::EventQueue(){
	Event * eventStart = new Event(*this, -10);
	rootNode = new node();
	rootNode -> event = eventStart;
	rootNode -> next = NULL; //Furthest up, smallest time (EARLIEST)
	rootNode -> prev = NULL; //Furthest down, Higher time (LATER)
	nodeleng = 0;
}

/*****************************************************************/

/*
 * void insertQueue(Event *eventIn, node * comparedNode)
 * Purpose: Insert an element Event into the event queue based on time, recursive
 * @param Event *eventIn Event to be inserted into the Queue
 * @param node * comparedNode Node which is to be compared to event time
 * @return void
 */
void EventQueue::insertQueue(Event *eventIn, node *comparedNode){
	node *insertNode = initEventInQueue(eventIn);

	if(comparedNode -> event -> getTime() < insertNode -> event -> getTime() &&
			(comparedNode -> prev == NULL ||
			 comparedNode -> prev -> event -> getTime() > insertNode -> event -> getTime()) ){
		// eventIn needs to be inserted after comparedNode
		// because eventIn has a time that is larger or equal
		// and less than previous node
		nodeleng++;
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
		free(insertNode);
		insertQueue(eventIn,comparedNode -> prev); // recursively call

	}
}

/*****************************************************************/

/* Overloaded Function:
 * void insertQueue(Event &eventIn)
 * Purpose: public function in order to insert an event into the event queue
 * @param Event &eventIn Pointer to an event which is to be inserted in the queue
 * @return void
 */
void EventQueue::insertQueue(Event &eventIn){
	insertQueue(&eventIn, rootNode); //Call other insertQueue Method
}

/*
 * bool emptyEventQueue()
 * Purpose: Return a boolean value if the EventQueue is empty
 * @return bool (TRUE == Empty) (FALSE == Event in Queue)
 */

/*****************************************************************/

bool EventQueue::emptyEventQueue(){
	return true;
}

/*****************************************************************/

/*
 * node * initEventQueue(Event *eventIn)
 * Purpose:
 * @param Event *eventIn Event to be inserted into the Queue
 * @param node * comparedNode Node which is to be compared to event time
 * @return void
 */
EventQueue::node* EventQueue::initEventInQueue(Event *eventIn){

	node *Node = new node;
	Node -> event = eventIn;
	Node -> next = NULL;
	Node -> prev = NULL;
	return Node;
}

/*****************************************************************/

// gets the rootNode of the event queue
EventQueue::node* EventQueue::getRootNode(){
	return rootNode;
}

/*****************************************************************/

int EventQueue::getQueueLen(){
	return nodeleng;
}

/*****************************************************************/

/*
 * Event *GetTopEvent()
 * Purpose: Return Pointer to event at the top of the event queue
 * @param void
 * @return Event * Return the pointer to the top event in event queue
 */
//ENSURE THAT IT IS NOT 0
Event *EventQueue::GetTopEvent(){ //grab this as refrence
		Event *eventIn = rootNode -> prev -> event;
		node* prevNode = rootNode -> prev;
		rootNode -> prev = rootNode -> prev -> prev;
		free(prevNode);
		return eventIn;
}

/*****************************************************************/

/*
 * float GetTopEventTime()
 * Purpose: Return time of the top event
 * @param void
 * @return float Return the time of the top event
 */

float EventQueue::GetTopEventTime(){
	return rootNode -> prev ->event -> getTime();
}
