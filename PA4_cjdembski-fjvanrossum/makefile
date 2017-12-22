
CFLAGS = -g

all: qSim

qSim: qSim.o readWords.o tree.o
	g++ $(CFLAGS) -Wall qSim.o -o qSim

qSim.o: qSim.cpp
	g++ $(CFLAGS) -Wall -c qSim.cpp

clean:
	 rm -f qSim.o qSim
