#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#ifndef READWORDS_H_
#define READWORDS_H_

void initFile(char fileName[]);

char getNextWord();

void closeFile();
#endif