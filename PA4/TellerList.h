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
	TellerList(EventQueue &eventQue);
	int getQueueLength();
	void insertQueue(TellerEvent &eventIn);
	bool emptyEventQueue();
	int getListLen();
	TellerEvent GetTopEvent(int tellNum);
	~TellerList();
};


#endif /* TELLERLIST_H_ */
