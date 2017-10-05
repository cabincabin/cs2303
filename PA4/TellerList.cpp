/*
 * TellerList.cpp
 *
 *  Created on: Oct 2, 2017
 *      Author: Floris van Rossum & Clayton Dembski
 */

/*****************************************************************/
// Include Statements:
// Standard includes
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Our own includes
#include "Event.h"
#include "EventQueue.h"
#include "TypesOfActions.h"
#include "TellerList.h"
#include "TellerEvent.h"

/*****************************************************************/
/*
 * TellerList(EventQueue &evQue)
 * Purpose: Constructor of the teller list class
 * @param EventQueue &evQue A pointer to the main Event Queue
 */
TellerList::TellerList(EventQueue &eventQue){
	// Initialize a root teller event
	TellerEvent * tellerEventStart = new TellerEvent(eventQue,-10, *this);
	// Set rootnode members
	rootNode = new node();
	rootNode -> tellerEvent = tellerEventStart;
	rootNode -> tellerNum = 0;
	rootNode -> prev = NULL;
	nodeleng = 0;
}

/*
 * void insertQueue(TellerEvent *eventIn, node *comparedNode, int tellNum)
 * Purpose: Insert a teller queue into the queue with respect to time
 * @param TellerEvent *eventIn A teller event to be inserted
 * @param node *comparedNode The node which inserted teller event will be
 * compared to
 * @param int tellNum Insert the teller number referring to the teller queue
 * number
 * @return void
 */
void TellerList::insertQueue(TellerEvent *eventIn, node *comparedNode, int tellNum){
	// Create a new node which is to be inserted
	node* insertNode = initTellerInQueue(eventIn);

	// Controls where to insert inserted node
	if(comparedNode-> prev == NULL){
		// There is no Teller Event in this node so insert here
		// Update the members of the node
		insertNode -> tellerNum = tellNum;
		comparedNode -> prev = insertNode;
		nodeleng++;
	}
	else{
		// There is a teller event in the node, so recursively call
		// function and keep looking
		insertQueue(eventIn, comparedNode -> prev, ++tellNum);
		// Free used objects
		free(insertNode);
	}
}

/*
 * void insertQueue(TellerEvent &eventIn)
 * Purpose: overloaded public function of the insertQueue, calls the actual
 * function and uses rootnode
 * @param TellerEvent &eventIn The teller event to be inserted
 * @return void
 */
void TellerList::insertQueue(TellerEvent &eventIn){
	insertQueue(&eventIn, rootNode, 1);
}

/*
 * node * initTellerInQueue(TellerEvent * eventIn)
 * Purpose: Initialize the teller queue
 * @param TellerEvent &eventIn The teller event to be inserted in the teller
 * queue
 * @return node * Return a reference to the node
 */
TellerList::node* TellerList::initTellerInQueue(TellerEvent *eventIn){
	// Create a new blank node and set tellerNum to a noticeable value
	// since this should never be used
	node *Node = new node;
	Node -> tellerEvent = eventIn;
	Node -> prev = NULL;
	Node -> tellerNum = -20;
	return Node;
}

/*
 * int getListLen()
 * Purpose: Get the length of the teller queue
 * @return int Returns the length of the teller queue
 */
int TellerList::getListLen(){
	return nodeleng;
}

/*
 * node * getRootNode()
 * Purpose: Return the root node of the teller queue
 * @return node * The root node of the teller queue
 */
TellerList::node* TellerList::getRootNode(){
	return rootNode;
}

/*
 * int GetPeopleInBank()
 * Purpose: Return all the customers currently inside teller queues
 * @return int Return the number of people in teller queues
 */
int TellerList::GetPeopleInBank(){
	int leng = 0;
	node* tellNode = rootNode;
	leng = leng + tellNode->tellerEvent->tellerQue->getQueueLen();
	// Increment through all teller queues to get the teller queue length
	// return the sum of the teller queue lengths
	for(int i = 0; i < nodeleng; i++){
		tellNode = tellNode -> prev;
		leng = leng + tellNode->tellerEvent->tellerQue->getQueueLen();
	}
	return leng;
}

/*
 * TellerEvent * GetEvent(int tellNum)
 * Purpose: Get the next event from the teller queue
 * @param int tellNum The queue number referring to which teller queue to grab the
 * Teller Event from
 * @return TellerEvent * Return the teller event
 */
TellerEvent *TellerList::GetEvent(int tellNum){
		node* tellNode = rootNode;
		// Increment through the teller queues to get desired teller queue
		for(int i = 0; i < tellNum; i++){
			tellNode = tellNode -> prev;
		}
		// Get the teller queue event
		TellerEvent *Tev = tellNode -> tellerEvent;
		return Tev;
}

/*
 * ~TellerList()
 * Purpose: Destructor of the teller list class
 */
TellerList::~TellerList(){
	node* tellNode;
	// Sort through all the teller queues to delete all the nodes
	for(int i=nodeleng; i >=0; i--){
		tellNode = rootNode;
		for(int j = 0; j < nodeleng; j++){
			tellNode = tellNode -> prev;
		}
		delete tellNode->prev;
	}
}

