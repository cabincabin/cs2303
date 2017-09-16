README for program life from project PA2_cjdembski

To run this program, first make, then enter:-

./life x y gens input print pause

where  x is the number of columns for the playing board
       y is the number of rows for the playing board
		   gens is the number of generations to play if no end state hit
			 input is the file to place in the center of the playing board
			 print is whether the intermediate generations should be played
											from the first gen to the end condition (y/n)
			 pause is if a key stroke should be pressed to advance gens(y/n)

This plays a Conway's Game of life, which follows these conditions:

The game board is an x by y board filled with x's and o's, where x is life
and o is dead. if x was 3 and y was 3 a valid board could be:

                            xxx
                            xxx
                            xxx

for each generation, a new board is constructed along the following rules:

A neighbor is any of the 8 spaces around a given point p.

                          1 2 3
                          4 p 5
                          6 7 8

if a neighbor is not on the given board it is treaded as a dead cell.
if a live cell has 2 or 3 cells, it remains alive for the next generation.
Otherwise it dies.
if a dead cell has 3 neighbors, it becomes alive for the next generation.

A generation could look like as follows:

                       xxx      xox
                       xxx  ->  ooo
                       xxx      xox

The game ends if it reaches the given number of generations, or
all life has been exterminated, or a pattern created by life repeats
one after another, or after a generation.

To create an input file for the code, open a new txt file and enter
a sequence of lowercase x and y in starting position wanted. This will be
appended to the center of the game board created by x and y. For example:

                                    oooo
                             xx     oxxo
          x=4 y = 4, file =  xx ->  oxxo
                                    oooo



The code flow is as follows:

                          |-------------|--------|--->updateArray
                          |             v        v
             main <- getArrToAppend, getArrCol getArrRow
               |
               v
centerFile, nextgen, printLifeArray
               |
               V
         printLifeArray

/***************************************************************************/

int main(int argc, char *argv[])
    -prints out the game of life for a given file and generation count
    ---int argc the size of the input values, if less than five
    ------an error should be thrown.
    ------if 7, pause and play parameters are allowed
    ---char *argv[5 or 7] is an array holding
    ------x, the number of columns for the playing board
    ------y, the number of rows for the playing board
    ------gens, the number of generations to play if no end state hit
    ------input, the file to place in the center of the playing board
    ------print, whether the intermediate generations should be played
    --------->from the first gen to the end condition (y/n)
    ------pause, if a key stroke should be pressed to advance gens(y/n)
    ---LOOP 1,2,3: allocates a 2d dynamic array of pointers
    ------>precondition: gen is a 2d array allocated to store arrays of pointers
		---------->in each row.
    ------>loopInvariant: gen will be a 2d array of pointers.
    ---LOOP 4:fills arrays 1-3 with 0s
    ------>precondition: all three boards are empty
    ------>loopInvariant: all three boards are filled with 0s
    ---LOOP 5: cycles through the full life array and confirms not dead
    ------>precondition: the gameboard is initialized with the life file
    ------>loopInvariant: any gameboard initialized with proper life
    --------->will not be dead, generations will be allowed.
    ---LOOP 6: runs gens until end condition
    ------>precondition: the gameboard is initialized properly with life
    ------>loop invariant: genA is the current Generation genB will be
    --------->the next Generation, genC is the past generation
    ---LOOP 7,8: scroll through the gameboard
    ------>loopInvariant, precondition: genA is the past generation,
    --------->genB is the current generation genC is the very past generation
    ------>loopInvariant: the death and repetition of the gameboard can be
    --------->checked

/***************************************************************************/

void nextgen(int rSize, int cSize, int ** genA, int ** genB)
    -generates the next generation of life from the given gen
    ---rSize, the row size of the array
    ---cSize, the column size of the array
    ---genA,  the current generation
    ---genB, the array where whe next generation should be produced into
    ---LOOP 1,2: scroll through the gameboard
    ------>Precondition: the index of both generation arrays are at the first
    --------->index
    ------>Precondition: both generation arrays are at the first col index
    ---LOOP 4,5: check each of the 9 neighbors
    ------>precondition: there are no neighbors and the index of the relative
    --------->column is bounded by the gameboard and current pos
    ------>loopInvariant: the number of neigbors for a given point r c
    --------->is found
    ------>loop invariant: the new generation is updated for a given point based
  												//based on its neighbors

/***************************************************************************/

void centerFile(int **genA, int rSize, int cSize, int **genAppend,
	int rFileSize, int cFileSize)
    -places a life set onto the approxamate center of a play board,
    ------if the life array does not go into the board evenly, it is placced at
    ------the left apprxamation
    ---genA the empty playboard, must be larger than the life array
    ---rSize, the row size of the playerboard
    ---cSize, the column size of the playerboard
    ---genAppend the life array to be cented on the board.
    ---rFileSize, the row size of the playerboard
    ---cFileSize, the column size of the playerboard
    ---LOOP 1,2: scrolls through each element of the life array
    ------>Precondition: the index of the life array is zero
    ------>loop Invariant: will go through every item in the life array
    ------>loop Invaraint: ends at last index of life array
    ------>Precondition: the column of the life matrix is 0, to be projected
    --------->onto the board
    ------>loop Invariant: the array will be appended to the center, alligned
    --------->aligned left of the game board
    ------>loop invariant: starts at the upper left hand corner of the array
    --------->withoffset for centering
    ------->loop invariant: starts at the lower right hand corner of the array

/***************************************************************************/

void printLifeArray(int rSize, int cSize,int **gen)
    -prints out the life array as given, translating 0s to os and 1s to xs
    ---rSize, the row size of the array passed
    ---cSize, the column size of the array passed
    ---gen, the generation array to be printed on the screen
    ---LOOP 1,2: Scrolls through and prints the array
    ------>Precondition: the index of the gen array is zero
    ------>Precondition: the column of the gen matrix is 0,
    ------>loop invariant: the board will be printed, in xs and os to the screen

/***************************************************************************/

int getArrCol(char fileName[])
    -extracts the maximum column size of a given file in xo life format
    ---fileName[] The name of the file to extract the row size from
    ---returns the max column length of the given file.
    ---Loop1: gets the max size of column for a file
    ------>precondition: the given file has been opened and is at the
    --------->first index.
    ------>loop invariant: the max column size has been found,
    --------->scroll is at the end of the file


/***************************************************************************/

int getArrRow(char fileName[])
    -extracts the maximum row size of a given file in xo life format
    ---fileName[] The name of the file to extract the row size from
    ---returns the max column length of the given file.
    ---Loop1: gets the max size of rowfor a file
    ------>precondition: the given file has been opened and is at the
    --------->first index.
    ------>loop invariant: the max row size has been found,
    --------->scroll is at the end of the file

/***************************************************************************/

int** getArrToAppend(char fileName[])
    -this creates a 2 dimentional array of the data stored,
    ---assuming the file is in the proper xo life format.
    ---fileName[] The name of the file to extract the array from
    ---returns a 2 dimentional array of the given file
    ---LOOP 1: allocates a 2d dynamic array of pointers
    ------>precondition: gen is a 2d array allocated to store arrays of pointers
		---------->in each row.
    ------>loopInvariant: gen will be a 2d array of pointers.
    ---LOOP 2:fills array with 0s
    ------>precondition: the board is empty
    ------>loop invariant: all three boards are filled with 0s

/***************************************************************************/

void updateArray(char fileName[], int ** genAppend)
    -with a filename and a blank array of bounds generated by the max extents
    ------of the file, (row and column) fill in any spaces that contain x's in the array
    ------this is to account for arrays that are uneven in size, line by line.
    ---fileName[] The name of the file to extract the coordinates of life from
    ---genAppend The empty matrix to append "live" cells to.
    ---LOOP 1: scrolls through a given file and adds all life to the 0 double array
    ------>precondition: the given file has been opened and is at the
    --------->first index.
    ------>loopInvariant: the life array has been filled with life from
    ---------->the given file

/***************************************************************************/
/**@source Assignment2--GemaOfLife.docx
*@source  https://stackoverflow.com/questions/7109964/creating-your-own-header-file-in-c
*@source  https://stackoverflow.com/questions/3463426/in-c-how-should-i-read-a-text-file-and-print-all-strings
*@source  https://www.tutorialspoint.com/c_standard_library/c_function_fgetc.htm
*@source 	https://commandline.codeplex.com/
*@source	https://stackoverflow.com/questions/8004237/how-do-i-properly-compare-strings
*@source	https://stackoverflow.com/questions/18801483/press-any-key-to-continue-function-in-c
*@source http://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
*@source http://publications.gbdirect.co.uk/c_book/chapter5/sizeof_and_malloc.html
*/
