CFLAGS = -g

all: life

life: readFile.o life.o
	gcc $(CFLAGS) -Wall life.o readFile.o -o life

readFile.o: readFile.h readFile.c
	gcc $(CFLAGS) -Wall -c readFile.c

life.o: readFile.h life.c
	gcc $(CFLAGS) -Wall -c life.c

clean:
	 rm -f life.o readFile.o life
