#Make file for CS2303: Game of life
#WRITTEN BY: Clayton Dembski 9/15/17
#CS2303 Lab2 makefile used as refrence
#This makefile is used to regenerate files for the life program
#		make readFile.o -- 	Regenerates readFile.o by compiling
#		make life.o 		--	Regenerates life.o by compiling
#		make life				--	Regenerates the executable life file by compiling
#		make						--	same as "make life"


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
