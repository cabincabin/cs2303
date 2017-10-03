/*
 * TellerQueue.cpp
 *
 *  Created on: Oct 2, 2017
 *      Author: student
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
#include "TellerQueue.h"
#include "CustEvent.h"

TellerQueue::TellerQueue(EventQueue &eventQue){
	CustEvent * custEventStart = new CustEvent(eventQue, -10);
	rootNode = new node();
	rootNode -> customerEvent = custEventStart;
	rootNode -> next = NULL; //Furthest up, smallest time (EARLIEST)
	rootNode -> prev = NULL; //Furthest down, Higher time (LATER)
}

void TellerQueue::insertQueue(CustEvent *eventIn, node *comparedNode){
	node * insertNode = initTellerInQueue(eventIn);

	if(comparedNode -> customerEvent -> getTime() < insertNode -> customerEvent -> getTime() &&
			(comparedNode -> prev == NULL || comparedNode -> prev -> event
			-> getTime() > insertNode -> getTime())){
		int a = 1;
		insertNode -> next = comparedNode;
		if(comparedNode -> prev != NULL){
			insertNode -> prev = comparedNode -> prev;
			comparedNode -> prev -> next = insertNode;
		}

		comparedNode -> prev = insertNode;
	}

	else if (comparedNode -> customerEvent -> getTime() < eventIn -> getTime() &&
			 comparedNode -> prev -> customerEvent -> getTime() < insertNode -> customerEvent -> getTime()){
		insertQueue(eventIn, comparedNode -> prev);
	}
}

void TellerQueue::insertQueue(CustEvent &eventIn){
	insertQueue(&eventIn, rootNode); //Call other insertQueue Method
}

bool TellerQueue::emptyEventQueue(){
	return true;
}

TellerQueue::node * TellerQueue::initTellerInQueue(CustEvent *eventIn){
	node * Node = new node;
	Node -> customerEvent = eventIn;
	Node -> next = NULL;
	Node -> prev = NULL;
	return node;
}

TellerQueue::node * TellerQueue::getRoodNode(){
	return rootNode;
}
