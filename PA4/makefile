
CFLAGS = -g

all: qSim

qSim: qSim.o Event.o EventQueue.o CustEvent.o TellerEvent.o TellerList.o
	g++ $(CFLAGS) -Wall qSim.o Event.o EventQueue.o CustEvent.o TellerEvent.o TellerList.o -o qSim

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
	
TellerList.o: TellerList.cpp TellerList.h Event.h EventQueue.h  TellerEvent.h
	g++ $(CFLAGS) -Wall -c TellerList.cpp

docs:
	@doxygen
	@open doxygen/html/index.html

clean:
	 rm -f qSim.o Event.o EventQueue.o TellerEvent.o CustEvent.o TellerList.o qSim
