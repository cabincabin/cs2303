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

/** EventQueue()
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

/**void insertQueue(Event *eventIn, node * comparedNode)
 * Purpose: Insert an element Event into the event queue based on time, recursive
 * @param Event *eventIn Event to be inserted into the Queue
 * @param node * comparedNode Node which is to be compared to event time
 * @return void
 */
void EventQueue::insertQueue(Event *eventIn, node *comparedNode){
	node *insertNode = initEventInQueue(eventIn);

	if(comparedNode -> event -> getTime() <= insertNode -> event -> getTime() &&
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

	else if(comparedNode -> event -> getTime() <= eventIn -> getTime() &&
			 comparedNode -> prev -> event -> getTime() <= insertNode -> event -> getTime()){
		// comparedNode is earlier in even queue so continue searching
		delete(insertNode);
		insertQueue(eventIn,comparedNode -> prev); // recursively call

	}
}

/*****************************************************************/

/** Overloaded Function:
 * void insertQueue(Event &eventIn)
 * Purpose: public function in order to insert an event into the event queue
 * @param Event &eventIn Pointer to an event which is to be inserted in the queue
 * @return void
 */
void EventQueue::insertQueue(Event &eventIn){
	insertQueue(&eventIn, rootNode); //Call other insertQueue Method
	//convert from refrence to pointer
}

/**bool emptyEventQueue()
 * Purpose: Return a boolean value if the EventQueue is empty
 * @return bool (TRUE == Empty) (FALSE == Event in Queue)
 */

/*****************************************************************/
/**
 * int EventQueueCusts()
 * Purpose: public function to find the number of customers left in an event
 * @return int leng The number of customers in the EventQueue
 */
int EventQueue::EventQueueCusts(){
	int leng = 0;
	node* Node = rootNode;
	//for each node in the queue
	for(int i = 0; i < nodeleng; i++){
		Node = Node -> prev;
		//see if the event is a customer
		if(Node->event->getActionType()>=-3)
				leng++;
	}
	//LOOP INVARIANT: the number of customers in the event queue is returned.

	return leng;

}

/*****************************************************************/

/** node * initEventQueue(Event *eventIn)
 * Purpose:
 * @param Event *eventIn Event to be inserted into the Queue
 * @param node * comparedNode Node which is to be compared to event time
 * @return void
 */
EventQueue::node* EventQueue::initEventInQueue(Event *eventIn){
	//create new node
	node *Node = new node;
	//fill with current event
	Node -> event = eventIn;
	//set both previous nodes to Null
	Node -> next = NULL;
	Node -> prev = NULL;
	return Node;
}

/*****************************************************************/
/** Event *getQueueLen()
* Purpose: give the number of elements in the queue minus the root node
* @return int nodelength the length of the EventQueue at the current time
*/
int EventQueue::getQueueLen(){

	return nodeleng;
}

/*****************************************************************/

/** Event *GetTopEvent()
 * Purpose: Return Pointer to event at the top of the event queue
 * @param void
 * @return Event * Return the pointer to the top event in event queue
 */
Event *EventQueue::GetTopEvent(){
		//get the top event off of the unusable default node
		//rootnode:Ie get the node previous to root node
		Event *eventIn = rootNode -> prev -> event;
		//remove the rootNode with out deleting the event information
		//as the event is used later
		node* prevNode = rootNode -> prev;
		rootNode -> prev = rootNode -> prev -> prev;
		delete(prevNode);
		//update the total size of the class
		nodeleng--;
		return eventIn;

}

/**EventQueue()
 * Purpose: Destructor of the EventQueue class
 */
EventQueue::~EventQueue(){
	int nodel = nodeleng;
	for(int i=nodel; i >0; i--){
		GetTopEvent();
	}
	//delete rootNode;
}

