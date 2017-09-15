#ifndef READFILE_H_
#define READFILE_H


int getArrRow(char fileName[]);
int getArrCol(char fileName[]);

int** getArrToAppend(char *fileName);
void updateArray(char fileName[], int ** genAppend);

#endif
