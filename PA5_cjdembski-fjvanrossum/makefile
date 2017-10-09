
CFLAGS = -g

all: PA5

PA5: PA5.o Grid.o Organism.o Ant.o Doodlebug.o
	g++ $(CFLAGS) -Wall PA5.o Organism.o Grid.o Doodlebug.o Ant.o -o PA5

PA5.o: PA5.cpp
	g++ $(CFLAGS) -Wall -c PA5.cpp

Grid.o: Grid.cpp Grid.h Organism.h
	g++ $(CFLAGS) -Wall -c Grid.cpp

Organism.o: Organism.cpp Organism.h Grid.h
	g++ $(CFLAGS) -Wall -c Organism.cpp
	
Doodlebug.o: Doodlebug.cpp Doodlebug.h Organism.h Grid.h
	g++ $(CFLAGS) -Wall -c Doodlebug.cpp
	
Ant.o: Ant.cpp Ant.h Organism.h Grid.h
	g++ $(CFLAGS) -Wall -c Ant.cpp
	
clean:
	 rm -f PA5.o Grid.o Organism.o Ant.o PA5