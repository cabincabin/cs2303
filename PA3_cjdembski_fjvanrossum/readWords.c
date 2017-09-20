#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "readWords.h"

static FILE *input;
static char scroll;

///////////////////////////////////////////////////////////////
void initFile(char fileName[]){

  //fName[] = fileName;
  input = fopen(fileName, "r");
  if (!input){
    printf("Unable to open file\n");
    exit(-0);
  }
  printf("opened file\n");
  scroll = fgetc(input);

}

///////////////////////////////////////////////////////////////
char getNextWord(){
  int sizeOfFile = 0;
  int wordGet = 0;
  char prevchar = ' ';
  char word[100];
  if(scroll==EOF){
    closeFile();
    return EOF;
    printf("%d\n", sizeOfFile);
    //exit(-0);
  }
  for(;!(scroll>=(char)48 && scroll <= (char)57)&&!(scroll>=(char)65 && scroll <= (char)90)&&
  !(scroll >= (char)97 && scroll <=(char)122) && scroll!=(char)39; scroll = fgetc(input)){
  //printf("%c",scroll);
  }
  sizeOfFile++;
  printf("%c",178);

  for(;(scroll>=(char)48 && scroll <= (char)57)||(scroll>=(char)65 && scroll <=(char)90)||
  (scroll >= (char)97 && scroll <=(char)122) || scroll==(char)39 || (prevchar == '-'
   && scroll!='-'); scroll = fgetc(input)){
    printf("%c",scroll);
    word[wordGet]=scroll;
    fflush(stdout);
    prevchar = scroll;
    wordGet++;
    //printf("%c",scroll);
  }
  return 'n';
}

///////////////////////////////////////////////////////////////
void closeFile(){
  if (input){
    fclose(input);
  }
}
