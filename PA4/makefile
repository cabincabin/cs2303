
CFLAGS = -g

all: qSim

qSim: qSim.o Event.o EventQueue.o
	g++ $(CFLAGS) -Wall qSim.o Event.o EventQueue.o -o qSim

qSim.o: qSim.cpp
	g++ $(CFLAGS) -Wall -c qSim.cpp

Event.o: Event.cpp EventQueue.h
	g++ $(CFLAGS) -Wall -c Event.cpp

EventQueue.o: EventQueue.cpp Event.h
	g++ $(CFLAGS) -Wall -c EventQueue.cpp

clean:
	 rm -f qSim.o qSim
