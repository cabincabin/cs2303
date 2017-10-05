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
	TellerEvent * tellerEventStart = new TellerEvent(eventQue,-10, *this);
	rootNode = new node();
	rootNode -> tellerEvent = tellerEventStart;
	rootNode -> tellerNum = 0;
	rootNode -> prev = NULL;
	nodeleng = 0;
}

void TellerList::insertQueue(TellerEvent *eventIn, node *comparedNode, int tellNum){
	node* insertNode = initTellerInQueue(eventIn);

	if(comparedNode-> prev == NULL){
			insertNode -> tellerNum = tellNum;

			comparedNode -> prev = insertNode;
			nodeleng++;
		}

		else{
			insertQueue(eventIn, comparedNode -> prev, ++tellNum);
			free(insertNode);
		}
}

void TellerList::insertQueue(TellerEvent &eventIn){
	insertQueue(&eventIn, rootNode, 1);
}

TellerList::node* TellerList::initTellerInQueue(TellerEvent *eventIn){
	node *Node = new node;
	Node -> tellerEvent = eventIn;
	Node -> prev = NULL;
	Node -> tellerNum = -20;
	return Node;
}

int TellerList::getListLen(){
	return nodeleng;
}

TellerList::node* TellerList::getRootNode(){
	return rootNode;
}

int TellerList::GetPeopleInBank(){
	int leng = 0;
	node* tellNode = rootNode;
	leng = leng + tellNode->tellerEvent->tellerQue->getQueueLen();
	for(int i = 0; i < nodeleng; i++){
		tellNode = tellNode -> prev;
		leng = leng + tellNode->tellerEvent->tellerQue->getQueueLen();
	}

	return leng;
}

TellerEvent *TellerList::GetEvent(int tellNum){ //grab this as refrence

		node* tellNode = rootNode;
		for(int i = 0; i < tellNum; i++){
			tellNode = tellNode -> prev;
		}
		TellerEvent *Tev = tellNode -> tellerEvent;
		return Tev;


}

