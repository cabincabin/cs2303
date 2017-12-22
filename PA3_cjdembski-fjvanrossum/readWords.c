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
#include "readWords.h"

static FILE *input;

static int scroll; //stores the current letter
static int sizeOfFiles = 0; //stores how many words have been read
char * fileout;//stores the name of the file to be read out

///////////////////////////////////////////////////////////////

/**void initFile(char fileName[])
 * Purpose: initializes the file to be read
 * and initializes scroll to be the first letter in the file.
 * prints if the file is opened successfully or not
 * @param char fileName[] The name of the file to be opened, as a string literal
 */
void initFile(char fileName[]){

  input = fopen(fileName, "r");
  if (!input){
    printf("Unable to open file\n");
    exit(-0);
  }
  //printf("opened file\n");
  scroll = fgetc(input);

}
///////////////////////////////////////////////////////////////

/**void initFile(char fileName[])
 * Purpose: initializes the file to be written to and clears all data in the file.
 * prints if the file is opened successfully or not
 * @param char fileName[] The name of the file to be opened, as a string literal
 */
void initOutput(char fileoutput[]){
	fileout = fileoutput;
	FILE *output;//the file being written to
	output = fopen(fileout, "w");
	if (!output){
	    printf("Unable to open file\n");
	    exit(-0);
	}
	fputs("",output);
	fclose(output);
}

///////////////////////////////////////////////////////////////
/**void getNextWord(char word[])
 * Purpose: fills a given char array with the next full word in the file
 * a word is defined as a-z A-Z 1-9 , or -
 * @param char word[] the array to be filled with the next word.
 *
 */
void getNextWord(char word[]){

  int wordGet = 0; //the current index of the word
  char prevchar = ' '; //the previous charicter

  if(scroll!=EOF){//if not at the end of the file
	  //Precondition: at the end of the previous word
    for(;!(scroll>=(char)48 && scroll <= (char)57)&&!(scroll>=(char)65 && scroll <= (char)90)&&
    !(scroll >= (char)97 && scroll <=(char)122) && scroll!=(char)39 && scroll!=EOF; scroll = fgetc(input)){
        //printf("dasdsadasd %d",scroll);
    	//loop invariant: char scroll is not a valid letter of a word
    }
	  //precondition: loop invariant: at the begining of the word to fill with the charicter
    sizeOfFiles++;
    //printf("%c",178);

    for(;(scroll>=(char)48 && scroll <= (char)57)||(scroll>=(char)65 && scroll <=(char)90)||
    (scroll >= (char)97 && scroll <=(char)122) || scroll==(char)39 || scroll=='-' || (prevchar == '-'
     && scroll!='-'); scroll = fgetc(input)){
      //printf("%c",scroll);
      if((scroll>=(char)65 && scroll <=(char)90)){
        word[wordGet]=scroll+32;//uppercase changed to lowercase
      }
      else{
        word[wordGet]=scroll;
      }

      prevchar = scroll;
      wordGet++;//loop invariant:the next letter in the word is found and added to the word
    }
  }
//loop invariant the word array is filled with the word.
  else{
    word[0]=-1;
    wordGet = 1;
  }

  word[wordGet]='\0';
  //printf("%d",scroll);
  fflush(stdout);
}

///////////////////////////////////////////////////////////////

/**void closeFile()
 * Purpose: Closes the input file after all data has been read from it
 */
void closeFile(){
  if (input){
    fclose(input);
  }
}

///////////////////////////////////////////////////////////////
/**void totalWords()
 * Purpose: prints the total number of words read in by the program
 * at the time of call
 */
void totalWords(int files){
	FILE *output;//the file being written to
	output = fopen(fileout, "a");
	if (!output){
		    printf("Unable to open file\n");
		    exit(-0);
	}

	fprintf(output, "%25s | %7d\n","Total number of words:", sizeOfFiles-files);

	fclose(output);
}
//////////////////////////////////////////////////////////////
/**outputFile(char outputchar[])
 * prints the given string to the file already given
 * @param char outputchar[] the string to be printed to the user
 */
void outputFile(char outputchar[]){
	FILE *output;//the file being written to
	output = fopen(fileout, "a");
	if (!output){
	    printf("Unable to open file\n");
	    exit(-0);
	}

	fputs(outputchar,output);
	fclose(output);

}

//////////////////////////////////////////////////////////////
/**outputFile2(char usedword[], int numcalls)
 * prints the given string to the file already given and
 * the number of times the string is used
 * @param char usedword[] the string to be printed to the user
 * @param  int numcalls the number of calls of the word, to be printed
 */

void outputFile2(char usedword[], int numcalls){
	FILE *output;//the file being written to
	output = fopen(fileout, "a");
	if (!output){
	    printf("Unable to open file\n");
	    exit(-0);
	}

	fprintf(output, "%25s | %7d\n", usedword, numcalls);
	fclose(output);
}
