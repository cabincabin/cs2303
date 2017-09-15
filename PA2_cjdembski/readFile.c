#include "readFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int getArrRow(FILE *input){
  int r;
  char scroll=0;
  while(scroll!=EOF){
    if(fgetc(input) = '\n')
      r++;
  }
}

int getArrCol(FILE *input){
  int c;
  int cMax = 0;
  char scroll=0;

  while(scroll!=EOF){
    while(scroll!="\n"||!=EOF){
      fgetc(input);
      c++;
    }
    if(c>cMax)
      cMax = c;
    c=0;
  }
}

int** getArrToAppend(char *fileName){
  FILE *input;
  int r;
  int c;
  input = fopen(fileName, "r");
  if (!input){
    printf("Unable to open file\n");
    fflush(stdout);
    exit(-0);
  }
  int rSize = getArrRow();
  int cSize = getArrCol();
  int** genAppend = (int **)malloc(rSize*sizeof(int *));
	if (genAppend) for (i=0; i<rSize; i++){
		genAppend[i] = (int*)malloc(cSize * sizeof(int));
		if (!genAppend[i]) exit(-1);
  for(r=0;r<rSize;r++){
    for(c=0;c<cSize;c++){
      genAppend[r][c]=0;
    }
  }
  fclose(input);
  return genAppend;
}
