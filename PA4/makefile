
CFLAGS = -g

all: qSim

qSim: qSim.o Event.o EventQueue.o CustEvent.o TellerEvent.o TellerQueue.o TellerList.o
	g++ $(CFLAGS) -Wall qSim.o Event.o EventQueue.o CustEvent.o TellerEvent.o TellerQueue.o TellerList.o -o qSim

qSim.o: qSim.cpp
	g++ $(CFLAGS) -Wall -c qSim.cpp

Event.o: Event.cpp Event.h EventQueue.h
	g++ $(CFLAGS) -Wall -c Event.cpp

EventQueue.o: EventQueue.cpp EventQueue.h Event.h
	g++ $(CFLAGS) -Wall -c EventQueue.cpp

CustEvent.o: CustEvent.cpp CustEvent.h Event.h
	g++ $(CFLAGS) -Wall -c CustEvent.cpp
	
TellerEvent.o: TellerEvent.cpp TellerEvent.h Event.h
	g++ $(CFLAGS) -Wall -c TellerEvent.cpp	

TellerQueue.o: TellerQueue.h Event.h CustEvent.h TellerQueue.cpp
	g++ $(CFLAGS) -Wall -c TellerQueue.cpp
	
TellerList.o: TellerList.h Event.h EventQueue.h TellerList.cpp TellerEvent.h
	g++ $(CFLAGS) -Wall -c TellerList.cpp
	
clean:
	 rm -f qSim.o Event.o EventQueue.o TellerEvent.o CustEvent.o TellerQueue.o TellerList.o qSim
