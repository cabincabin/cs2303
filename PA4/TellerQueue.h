/*
 * TellerQueue.h
 *
 *  Created on: Oct 2, 2017
 *      Author: Floris van Rossum & Clayton Dembski
 */

#ifndef TELLERQUEUE_H_
#define TELLERQUEUE_H_
class CustEvent;
class TellerQueue{
	struct node{
		CustEvent *customerEvent;
		struct node *prev;
		struct node *next;
	};

private:
	node* rootNode;
	void insertQueue(CustEvent *eventIn, node *comparedNode);
	node* initTellerInQueue(CustEvent *eventIn);
	node* getRootNode();
public:
	TellerQueue();
	int getQueueLength();
	void insertQueue(CustEvent &eventIn);
	bool emptyEventQueue();
	~TellerQueue();
};


#endif /* TELLERQUEUE_H_ */
