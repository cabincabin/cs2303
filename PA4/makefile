
CFLAGS = -g

all: qSim

qSim: qSim.o Event.o EventQueue.o CustEvent.o TellerEvent.o TellerQueue.o
	g++ $(CFLAGS) -Wall qSim.o Event.o EventQueue.o CustEvent.o TellerEvent.o TellerQueue.o -o qSim

qSim.o: qSim.cpp
	g++ $(CFLAGS) -Wall -c qSim.cpp

Event.o: Event.cpp Event.h EventQueue.h
	g++ $(CFLAGS) -Wall -c Event.cpp

EventQueue.o: EventQueue.cpp EventQueue.h Event.h
	g++ $(CFLAGS) -Wall -c EventQueue.cpp

CustEvent.o: CustEvent.cpp CustEvent.h Event.h
	g++ $(CFLAGS) -Wall -c CustEvent.cpp
	
TellerEvent.o:  TellerEvent.h Event.h TellerEvent.cpp
	g++ $(CFLAGS) -Wall -c TellerEvent.cpp	

TellerQueue.o: TellerQueue.h Event.h CustEvent.h TellerQueue.cpp
	g++ $(CFLAGS) -Wall -c TellerQueue.cpp
	
clean:
	 rm -f qSim.o Event.o EventQueue.o TellerEvent.o CustEvent.o TellerQueue.o qSim
