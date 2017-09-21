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

int main(){


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

  printf("\n");
  fflush(stdout);
  listTree(rootNode);
  derefTree(rootNode);
  closeFile();
  printf("\n");
  return 0;
}
