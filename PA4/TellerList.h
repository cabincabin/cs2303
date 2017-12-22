/*
 * TellerList.h
 *
 *  Created on: Oct 2, 2017
 *      Author: Floris van Rossum & Clayton Dembski
 */

#ifndef TELLERLIST_H_
#define TELLERLIST_H_
#include "TellerEvent.h"
class TellerEvent;
class TellerList{
	struct node{
	TellerEvent *tellerEvent;
	int tellerNum;
	struct node *prev;
	};
private:
	int nodeleng;
	node* rootNode;
	void insertQueue(TellerEvent *eventIn, node *comparedNode, int tellNum);
	node* initTellerInQueue(TellerEvent *eventIn);
	node* getRootNode();

public:
	//initialize the tellerlist, give an eventqueue for the default rootnode
	//TellerEvent and give an ID of 0
	//This is for th SIngle Queue simulation
	TellerList(EventQueue &eventQue);

	//insert a new active teller into the teller list and assign it the next id
	void insertQueue(TellerEvent &eventIn);
	//get the tota number of active tellers
	int getListLen();
	//get the total number of people currently in the bank via each tellers queue
	int GetPeopleInBank();
	//gets a teller by giving it it's assigned ID
	//0 is the single Queue System
	TellerEvent *GetEvent(int tellNum);
	~TellerList();
};


#endif /* TELLERLIST_H_ */
