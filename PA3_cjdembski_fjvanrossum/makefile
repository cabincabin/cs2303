
CFLAGS = -g

all: PA3

PA3: PA3_cjdembsi_fjvanrossum.o
	gcc $(CFLAGS) -Wall PA3_cjdembsi_fjvanrossum.o -o PA3

readFile.o: readFile.h readFile.c
	gcc $(CFLAGS) -Wall -c readFile.c

PA3_cjdembsi_fjvanrossum.c.o: PA3_cjdembsi_fjvanrossum.c
	gcc $(CFLAGS) -Wall -c PA3_cjdembsi_fjvanrossum.c

clean:
	 rm -f life.o PA3_cjdembsi_fjvanrossum.c.o PA3
