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
  int i;
  i = initFileGetSize("Obama.txt");
  printf("%d\n",i);
  return 0;
}
