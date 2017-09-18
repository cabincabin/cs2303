
CFLAGS = -g

all: PA3

PA3: PA3_cjdembsi_fjvanrossum.o readWords.o
	gcc $(CFLAGS) -Wall PA3_cjdembsi_fjvanrossum.o readWords.o -o PA3

readWords.o: readWords.h readWords.c
	gcc $(CFLAGS) -Wall -c readWords.c

PA3_cjdembsi_fjvanrossum.c.o: PA3_cjdembsi_fjvanrossum.c
	gcc $(CFLAGS) -Wall -c PA3_cjdembsi_fjvanrossum.c

clean:
	 rm -f life.o PA3_cjdembsi_fjvanrossum.c.o PA3
