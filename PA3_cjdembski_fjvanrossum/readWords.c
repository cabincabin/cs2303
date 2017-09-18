#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "readWords.h"

static char fName[];

///////////////////////////////////////////////////////////////
int initFileGetSize(char fileName[]){
  char scroll;
  int sizeOfFile = 0;
  char wordBool = ' ';
  char prevchar = ' ';
  //fName[] = fileName;
  FILE *input;
  input = fopen(fileName, "r");
  if (!input){
    printf("Unable to open file\n");
    exit(-0);
  }
  printf("opened file\n");

    while(scroll!=EOF){
      scroll = fgetc(input);
      printf("%c",scroll);
      if(wordBool == ' '){
          if(scroll!= ' ' && scroll != '\n' && scroll != '\t' && scroll != EOF
           && scroll != '.'&& scroll!='-'&&scroll!='"'){
             printf("%c",178);
            sizeOfFile++;
            wordBool = 'c';
          }
      }

      else if(wordBool == 'c'){
          if(scroll== ' '||scroll=='\n'||scroll=='.'||scroll== '\t'||(prevchar == '-' && scroll=='-')||scroll=='"'){
            wordBool = ' ';
          }
      }
      prevchar = scroll;
    }
    fclose(input);
    return sizeOfFile;
}


///////////////////////////////////////////////////////////////
char getNextWord(){
 return 'a';
}

///////////////////////////////////////////////////////////////
