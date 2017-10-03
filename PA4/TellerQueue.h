/*
 * TellerQueue.h
 *
 *  Created on: Oct 2, 2017
 *      Author: Floris van Rossum & Clayton Dembski
 */

#ifndef TELLERQUEUE_H_
#define TELLERQUEUE_H_

class TellerQueue{
	struct node{
		TellerEvent *tellerEvent;
		struct node *prev;
		struct node *next;
	};

private:
	node* rootNode;
	void insertQueue(TellerEvent *eventIn, node *comparedNode);
	node* initTellerInQueue(TellerEvent *eventIn);
	node* getRootNode();
public:
	TellerEventQueue();
	int getQueueLength();
	void insertQueue(TellerEvent &eventIn);

	~EventQueue;
};


#endif /* TELLERQUEUE_H_ */
