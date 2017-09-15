CFLAGS = -g

all: life

life: life.o
	gcc life.o -o life
	
life.o: life.c
	gcc -Wall -c life.c
	
clean:
	 rm -f *.o life