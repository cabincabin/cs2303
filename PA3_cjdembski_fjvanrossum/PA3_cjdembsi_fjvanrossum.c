/*
 * PA3_cjdembsi_fjvanrossum.c
 *
 *  Created on: Sep 17, 2017
 *      Author: student
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "readWords.h"
#include "tree.h"

void readFile(char * fileName, char * word, struct node * rootNode);

int main(int argc, char ** argv){
	char word[100];
	struct node * rootNode = newNode(word);
	for(int i = 0; i < argc - 1; i++){
		printf("Printing: %s \n", argv[i+1]);
		readFile(argv[i+1], word, rootNode);
	}
/*
  char word[100];
  int a = 0;
  int i = 0;
  initFile("Obama.txt");
  //causes size to be a+1
  getNextWord(word);
  struct node * rootNode = newNode(word);
  for(;a<5;a++){


  //while(word[0]!=-1){

    printf("%s ",word);

    fflush(stdout);
    for(int i; i<100; i++){
      word[i]='a';
    }
    getNextWord(word);
    insertWord(word,rootNode);
  }

  */
  //readFile("Obama.txt",word,rootNode);
  //readFile("Kennedy.txt", word, rootNode);
  printf("\n");
  fflush(stdout);
  printf("         Word:    |    Count: \n");
  listTree(rootNode);
  derefTree(rootNode);
  closeFile();
  printf("\n");
  return 0;
}

void readFile(char * fileName, char * word, struct node * rootNode){
	//char word[100];
	int a = 0;
	int i = 0;
	initFile(fileName);
	getNextWord(word);

	while (word[0] != -1){
		//printf("%s ", word);
		fflush(stdout);
		for(int i = 0; i<100; i++){
			word[i]= 'a';
		}
		getNextWord(word);
		insertWord(word,rootNode);
	}
}

