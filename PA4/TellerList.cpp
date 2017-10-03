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
	rootNode -> tellerNum = 0;
	rootNode -> prev = NULL;
}

void TellerList::insertQueue(TellerEvent *eventIn, node *comparedNode, int tellNum){
	node* insertNode = initTellerInQueue(eventIn);

	if(comparedNode-> prev == NULL){
			insertNode -> tellerNum = tellNum;

			comparedNode -> prev = insertNode;
		}

		else{
			insertQueue(eventIn, comparedNode -> prev, ++tellNum);
			free(insertNode);
		}
}

void TellerList::insertQueue(TellerEvent &eventIn){
	insertQueue(&eventIn, rootNode, 1);
}

bool TellerList::emptyEventQueue(){
	return true;
}

TellerList::node* TellerList::initTellerInQueue(TellerEvent *eventIn){
	node *Node = new node;
	Node -> tellerEvent = eventIn;
	Node -> prev = NULL;
	Node -> tellerNum = -20;
	return Node;
}



TellerList::node* TellerList::getRootNode(){
	return rootNode;
}
