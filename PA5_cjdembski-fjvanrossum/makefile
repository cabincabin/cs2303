
CFLAGS = -g

all: PA5

PA5: PA5.o Grid.o Oragnism.o 
	g++ $(CFLAGS) -Wall PA5.o Grid.o Organism.o -o PA5

PA5.o: PA5.cpp
	g++ $(CFLAGS) -Wall -c qSim.cpp

Grid.o: Grid.cpp Grid.h
	g++ $(CFLAGS) -Wall -c Grid.cpp

Grid.o: Grid.cpp Grid.h Organism.h
	g++ $(CFLAGS) -Wall -c Grid.cpp


Organism.o: Organism.cpp Organism.h Grid.h
	g++ $(CFLAGS) -Wall -c Organism.cpp

clean:
	 rm -f PA5.o Grid.o Organism.o PA5