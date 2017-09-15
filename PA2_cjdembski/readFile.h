#ifndef READFILE_H_
#define READFILE_H

int isValidFile();

int getArrRow(FILE *input);
int getArrCol(FILE *input);

int** getArrToAppend(char *fileName);


#endif
