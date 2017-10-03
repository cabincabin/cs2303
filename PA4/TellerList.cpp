/*
 * TellerList.cpp
 *
 *  Created on: Oct 2, 2017
 *      Author: Floris van Rossum & Clayton Dembski
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
#include "TellerList.h"
#include "TellerEvent.h"

TellerList::TellerList(EventQueue &eventQue){
	TellerEvent * tellerEventStart = new TellerEvent(eventQue,-10);
	rootNode = new node();
	rootNode -> tellerEvent = tellerEventStart;
	rootNode -> next = NULL;
	rootNode -> prev = NULL;
}

void TellerList::insertQueue(TellerEvent *eventIn, node * comparedNode){
	node * insertNode = initTellerInQueue(eventIn);

	if(comparedNode -> tellerEvent-> getTime() < insertNode -> tellerEvent-> getTime() &&
				(comparedNode -> prev == NULL || comparedNode -> prev -> tellerEvent
				-> getTime() > insertNode -> tellerEvent-> getTime())){
			int a = 1;
			insertNode -> next = comparedNode;
			if(comparedNode -> prev != NULL){
				insertNode -> prev = comparedNode -> prev;
				comparedNode -> prev -> next = insertNode;
			}

			comparedNode -> prev = insertNode;
		}

		else if (comparedNode -> tellerEvent-> getTime() < eventIn -> getTime() &&
				 comparedNode -> prev -> tellerEvent-> getTime() < insertNode -> tellerEvent-> getTime()){
			insertQueue(eventIn, comparedNode -> prev);
		}
}

void TellerList::insertQueue(TellerEvent &eventIn){
	insertQueue(&eventIn , rootNode);
}

bool TellerList::emptyEventQueue(){
	return true;
}

TellerList::node * TellerList::initTellerInQueue(TellerEvent * eventIn){
	node * Node = new node;
	Node -> tellerEvent = eventIn;
	Node -> next = NULL;
	Node -> prev = NULL;
	return Node;
}

TellerList::node * TellerList::getRootNode(){
	return rootNode;
}
