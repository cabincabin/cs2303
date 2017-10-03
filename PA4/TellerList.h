/*
 * TellerList.h
 *
 *  Created on: Oct 2, 2017
 *      Author: Floris van Rossum & Clayton Dembski
 */

#ifndef TELLERLIST_H_
#define TELLERLIST_H_
class TellerEvent;
class TellerList{

	struct node{
	TellerEvent *tellerEvent;
	struct node *prev;
	struct node *next;
	};

private:
	node * rootNode;
	void insertQueue(TellerEvent *eventIn, node *comparedNode);
	node * initTellerInQueue(TellerEvent *eventIn);
	node * getRootNode();

public:
	TellerList(EventQueue &eventQue);
	int getQueueLength();
	void insertQueue(TellerEvent &eventIn);
	bool emptyEventQueue();
	~TellerList();
};


#endif /* TELLERLIST_H_ */
