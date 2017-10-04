/*
 *  EventQueue.h
 *
 *  Created on: Oct. 1st, 2017
 *  Author: Clayton Dembski & Floris van Rossum
 *  Purpose: Header file of EventQueue Class
 */

#ifndef EVENTQUEUE_H_
#define EVENTQUEUE_H_

//Class declaration
class Event;

/*****************************************************************/
//CLASS EVENT QUEUE

class EventQueue{
	//Event Queue Node
	struct node{
			Event *event; // Stores a generic event object
			struct node *next; // the next node
			struct node *prev; // the previous node
		};

/*****************************************************************/


private:
	node* rootNode; // The rootNode of the EventQueue


	void insertQueue(Event *eventIn, node *comparedNode); //
	node* initEventInQueue(Event *eventIn); // initialize the eventqueue
	node* getRootNode();
	int nodeleng;

/*****************************************************************/

public:
	EventQueue();

	// Sorted linked list based on time
	// Add something to the linked list
	// remove something from the head
	//Insert a something into the event queue
	bool emptyEventQueue();

	void insertQueue(Event &eventIn);
	int getQueueLen();
	Event* GetTopEvent();
	float GetTopEventTime();
	~EventQueue();

};
#endif
