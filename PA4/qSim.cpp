
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "Event.h"
#include "EventQueue.h"

int main(){
	Event * event = new Event();
	EventQueue * queue = new EventQueue();
	event -> AddEvent();

}
