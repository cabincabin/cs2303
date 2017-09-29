/*
 * tree.c
 *
 *  Created on: Sep 17, 2017
 *      Author:Floris van Rossum & Clayton Dembski
 */

/*****************************************************************/

//Include Statements
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readWords.h"

static int nodeNumber = 0;

/*****************************************************************/

//Definition of a node in the binary tree
struct node {
	char * word; //pointer to the string which contains a word
	int cnt; //An integer value that counts the number of words
	struct node *left; //left node
	struct node *right; //right node
};

/*****************************************************************/

/*
 * struct node * newNode(char * word1)
 * Purpose: Initialize a new node in the program containing word
 * dynamically allocates memory for the struct and the word inside it
 * @param char * word1 Pointer to the string word which is to be entered in
 * the new node
 * @return struct node * Returns the pointer to the node that was just created
 */
struct node * newNode(char * word1){
	//Malloc the space required for a new node
	struct node* node = (struct node*)malloc(sizeof(struct node));

	//Malloc the space for a string of word size and copy the word to it
	node -> word = strncpy(((char *)malloc((strlen(word1)+1)*sizeof(char))),  word1,20);
	node -> cnt = 1; //set count of word1 to 1
	node -> left = NULL;
	node -> right = NULL;
	nodeNumber++;
	return node;
}

/*****************************************************************/

/*
 * void insertWord(char * word1, struct node * node)
 * Purpose: Insert a word into the binary tree, alphabetically
 * @param char * word1 Pointer to the string word which is to be entered in
 * the binary tree
 * @param struct node * node Root node of the binary tree into which the word
 * is to be entered
 * @return void
 */
void insertWord(char* word1, struct node * node){

	/*This if-else statement decides whether the word is alphabetically higher or
	 lower than node->word*/
	if(0 > strcmp(word1,node->word)){
		//Means that node->word is higher in alphabet

		//Checks if the left node is empty
		if(node->left == NULL){
			//Left node is empty so create a new node
			node->left = newNode(word1);
		}
		else{
			//Recursively call function in order to insert word into left node
			insertWord(word1, node->left);
		}
	}
	else if(strcmp(word1,node->word) > 0){
		//Means that word is higher in alphabet, so RIGHT

		//Checks if right node is empty
		if(node->right == NULL){
			//Right node is empty so create a new node in right node
			node->right = newNode(word1);
		} else {
			//Recursively call function in order to insert word into right node
			insertWord(word1, node->right);
		}
	} else if(strcmp(word1,node->word) == 0){
		//Word entered in function is same word as in node
		node->cnt++; //Increment the count of that word
	}
}

/*****************************************************************/

/**listTree(struct node * node)
 * Purpose: prints all nodes to file in alphabetical order
 * @param struct node * node The main node to generate the file off of
 */
void listTree(struct node * node){
	if( node->left != NULL){
		//do something for the left tree
		listTree(node->left);
	}
	else if(node->left == NULL){
		outputFile2(node->word , node->cnt);
		fflush(stdout);
	}
	//do something for the center node
	if(node->right != NULL){
		if( node->left != NULL){
			outputFile2(node->word , node->cnt);
			fflush(stdout);
		}
		//do something for the right node
		listTree(node->right);
	}
	else if(node->right == NULL && node->left != NULL){
		outputFile2(node->word , node->cnt);
		fflush(stdout);
	}
}

/*****************************************************************/

/**derefTree(struct node * node)
 * frees every node in a given tree
 * @param struct node * node the base node for all branches to be deleated
 */
void derefTree(struct node * node){
	if( node->left != NULL){
		//do something for the left tree
		derefTree(node->left);
	}

	//do something for the center node
	if(node->right != NULL){
		//do something for the right node
		derefTree(node->right);
	}

	free(node->word);
	free(node);
}


/*****************************************************************/

/**numUniqueWords()
 * Prints the number of unique words in the tree.
 */
void numUniqueWords(){
	outputFile2("Unique words:", nodeNumber);
}
