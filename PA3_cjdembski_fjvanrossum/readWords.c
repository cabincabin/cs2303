#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "readWords.h"

static FILE *input;
static int scroll;

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
void getNextWord(char word[]){
  int sizeOfFile = 0;
  int wordGet = 0;
  char prevchar = ' ';
  /*if(scroll==EOF){
    closeFile();
    return EOF;
    printf("%d\n", sizeOfFile);
    //exit(-0);
  }*/

  if(scroll!=EOF){
    for(;!(scroll>=(char)48 && scroll <= (char)57)&&!(scroll>=(char)65 && scroll <= (char)90)&&
    !(scroll >= (char)97 && scroll <=(char)122) && scroll!=(char)39 && scroll!=EOF; scroll = fgetc(input)){
        //printf("dasdsadasd %d",scroll);
    }
    sizeOfFile++;
    //printf("%c",178);

    for(;(scroll>=(char)48 && scroll <= (char)57)||(scroll>=(char)65 && scroll <=(char)90)||
    (scroll >= (char)97 && scroll <=(char)122) || scroll==(char)39 || scroll=='-' || (prevchar == '-'
     && scroll!='-'); scroll = fgetc(input)){
      //printf("%c",scroll);
      if((scroll>=(char)65 && scroll <=(char)90)){
        word[wordGet]=scroll+32;
      }
      else{
        word[wordGet]=scroll;
      }

      prevchar = scroll;
      wordGet++;
      //printf("hhhhhhhhhhhhh %d",scroll);
    }
  }

  else{
    word[0]=-1;
    wordGet = 1;
  }
  word[wordGet]='\0';
  //printf("%d",scroll);
  fflush(stdout);
}

///////////////////////////////////////////////////////////////
void closeFile(){
  if (input){
    fclose(input);
  }
}
