/*
 * PA3_cjdembsi_fjvanrossum.c
 *
 *  Created on: Sep 17, 2017
 *      Author: student
 */

/*****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "readWords.h"
#include "tree.h"

/*****************************************************************/

//Function Prototypes
void readFile(char * fileName, char * word, struct node * rootNode);

/*****************************************************************/

/*
 * int main(int argc, char ** argv)
 * Purpose: Main loop, start of the program, handles user input from command
 * line and uses it to call functions in tree.h and readWords.h
 * @param int argc Number of arguments entered into the command line
 * @param char ** argv An array of pointers to strings, user input is stored
 * here
 * @return int Represents the status of the program upon exit (0 == success)
 *  ( Not 0 is error)
 */
int main(int argc, char ** argv){
	char word[100]; //setting up an array for the first word
	initFile(argv[1]); //initializing the first file passed in by the user
	getNextWord(word); //Obtaining the first word from the file
	struct node * rootNode = newNode(word); /* creating the root node of
	our binary tree */

	//Purpose: Fill the rest of the binary tree with words from the first file
	//Pre-condition: File is opened correctly, word is not -1
	while (word[0] != -1){
		//Loop-Invariant: word is not -1 in the while loop

		/*Purpose: Fill the word with a so that there is no risk of running
		off the end of the string.
		Pre-condition: word[100] is initialized
		*/
		for(int i = 0; i<100; i++){
			word[i]= 'a';
			//Loop-Invariant: word[i] is now 'a'
		}
		getNextWord(word); //Get the next word from the file
		insertWord(word, rootNode); //Insert the word from the file into tree
		//Loop-Invariant: Word has been inserted into the binary tree
	}
	closeFile(); //close the file that was just read

	//Purpose: Repeat the process above for each text file entered by the user
	//Pre-condition: Command-line arguments are entered, more than 1 argument
	//is entered
	for(int i = 1; i < argc - 1; i++){
		//Loop-invariant: i is less than the number of commands entered by user
		//prints the current file that is entered in the node
		printf("Printing: %s \n", argv[i+1]);
		readFile(argv[i+1], word, rootNode); //user input file is read and
		//entered into binary tree
	}

	printf("\n");
	fflush(stdout);
	printf("         Word:    |    Count: \n");
	listTree(rootNode); /* print out the tree in alphabetical order
	starting at root node */
	derefTree(rootNode); //Deleting the tree and freeing up memory
	printf("\n");
	return 0;
}

/*****************************************************************/

/*
 * void readFile(char * fileName, char * word, struct node * rootNode)
 * Purpose: Read a file as determined by user and store words in tree
 * @param char * fileName A pointer to a string containing name of file
 * @param char * word A pointer to a string which contains the next word that
 * was read from a file
 * @param struct node * rootNode A pointer to a struct node, this is the start
 * node of the binary tree
 * @return void
 */
void readFile(char * fileName, char * word, struct node * rootNode){
	initFile(fileName); //initialize the file to be read
	getNextWord(word); //get the first word from the file

	//Purpose: Iterate through all the words in the file
	//Pre-condition: word[0] should not be -1, and the file is correctly setup
	while (word[0] != -1){
		//printf("%s ", word); //Used for debugging
		//Purpose: Fill word with 'a' to prevent running off the end of string
		for(int i = 0; i<100; i++){
			word[i]= 'a';
		}

		getNextWord(word);
		insertWord(word,rootNode);
		//Loop-invariant: word is inserted into the tree
	}
	closeFile();
}

