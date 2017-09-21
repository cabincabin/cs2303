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

int main(){
  char word[100];
  int a = 0;
  int i = 0;
  initFile("Kennedy.txt");
//  for(;a<2400;a++){
getNextWord(word);
  while(word[0]!=-1){

    printf("%s",word);

    fflush(stdout);
    for(int i; i<100; i++){
      word[i]='a';
    }
    getNextWord(word);
  }
  closeFile();
  return 0;
}
