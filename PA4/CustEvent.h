#ifndef CUSTEVENT_H_
#define CUSTEVENT_H_
#include "Event.h"
class CustEvent: public Event{

protected:
	float netTime;
	int action;
	Event event;
	EventQueue &eventQue;

public:
	CustEvent(EventQueue &evQue, float time);
	int timeAtBank();
	~CustEvent();
};

#endif
