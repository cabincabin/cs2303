#include "readFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int getArrRow(char fileName[]){
  FILE *input;
  int r=0;
  char scroll=0;

  input = fopen(fileName, "r");
  if (!input){
    printf("Unable to open file\n");
    fflush(stdout);
    exit(-0);
  }

  while(scroll!=EOF){
    scroll = fgetc(input);
    if(scroll == '\n'){
      r++;
    }
  }
  fclose(input);
  return r;

}

int getArrCol(char fileName[]){
  FILE *input;
  int c=0;
  int cMax = 0;
  char scroll=0;

  input = fopen(fileName, "r");
  if (!input){
    printf("Unable to open file\n");
    fflush(stdout);
    exit(-0);
  }

  while(scroll!=EOF){
    fflush(stdout);
    scroll = fgetc(input);
    c++;
    if(scroll=='\n'){
      if(c>cMax)
        cMax = c;
      c=0;
    }

  }

  fclose(input);
  return cMax;
}

int** getArrToAppend(char fileName[]){
  int i;
  int r;
  int c;

  int rSize = getArrRow(fileName);
  printf("%d",rSize);
  fflush(stdout);
  int cSize = getArrCol(fileName)-1;
  printf("%d",cSize);
  fflush(stdout);
  int** genAppend = (int **)malloc(rSize*sizeof(int *));
	if (genAppend) for (i=0; i<rSize; i++){
		genAppend[i] = (int*)malloc(cSize * sizeof(int));
		if (!genAppend[i]) exit(-1);
  }

  for(r=0;r<rSize;r++){
    for(c=0;c<cSize;c++){
      genAppend[r][c]=0;
    }
  }

  updateArray(fileName, genAppend);

  int j;
  printf("\n");
  for(i = 0; i<rSize; i++){
    printf("\n");
    for(j = 0; j<cSize; j++){
      if(genAppend[i][j] == 1){
        printf("x");
      }
      else{
        printf("o");
      }
    }
  }
  printf("\n");

  return genAppend;
}

void updateArray(char fileName[], int ** genAppend){
  FILE *input;
  int r=0;
  int c=-1;
  char scroll = 0;

  input = fopen(fileName, "r");
  if (!input){
    printf("Unable to open file\n");
    fflush(stdout);
    exit(-0);
  }

  while(scroll!=EOF){
    scroll = fgetc(input);
    if(scroll == '\n'){
        r++;
        c=-1;
    }
    else{
      c++;
    }
    if (scroll == 'x'){
      genAppend[r][c] = 1;
    }
    if (scroll == 'o'){
      genAppend[r][c] = 0;
    }

  }

  fclose(input);
}
