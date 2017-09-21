#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#ifndef READWORDS_H_
#define READWORDS_H_

void initFile(char fileName[]);

void getNextWord(char word[]);

void totalWords();

void closeFile();
#endif
