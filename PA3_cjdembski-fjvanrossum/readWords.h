/*
 * ReadWords.c
 *
 *  Created on: Sep 17, 2017
 *      Author:Floris van Rossum & Clayton Dembski
 *  this file allows for a txt file to be read and the words in the file to be extracted.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#ifndef READWORDS_H_
#define READWORDS_H_

void initFile(char fileName[]);

void initOutput(char fileName[]);

void getNextWord(char word[]);

void totalWords(int files);

void outputFile(char outputchar[]);
void outputFile2(char usedword[], int numcalls);

void closeFile();
#endif
