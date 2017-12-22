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
	int nodeleng;

/*****************************************************************/

public:
	//Constructs new EventQueue with a rootnode of an empty EVENT
	EventQueue();

	//returns the number of customers in the EventQueue
	int EventQueueCusts();

	//Inserts and sorts the envent as a node into the queue
	void insertQueue(Event &eventIn);
	//gets the total length of the queue, ignoring the default node
	int getQueueLen();
	//pops the first event to the user
	Event* GetTopEvent();

	~EventQueue();

};
#endif
