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

/*****************************************************************/

//Function Prototypes
struct node * getWord(char * word, struct node* node);
void derefTree(struct node * node);

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
	node -> word = strncpy(((char *)malloc(strlen(word1)*sizeof(char))),  word1,20);
	node -> cnt = 1; //set count of word1 to 1
	node -> left = NULL;
	node -> right = NULL;
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

/*
 * int getNumber(char * word, struct node* node)
 * Purpose: Get the count of a word located in the tree
 * @param char * word Pointer to the string word whose count is to be obtained
 * @param struct node * node
 * @return struct node * Returns the pointer to the node that was just created
 */
int getNumber(char* word,struct node* node){
	struct node * noded = getWord(word, node);
	if(noded == NULL){
		return 0;
	}
	return noded->cnt;
}

/*****************************************************************/

// Returns the pointer to a node when you enter a word
struct node * getWord(char * word, struct node* node){
	if((0 > strcmp(word, node->word))){
		//Means that node.word is higher in alphabet

		//check if left node is empty
		if(node->left == NULL){
			//if the left node is empty return null
			return NULL;
		} else {
			//else continue searching for the word
			getWord(word,node->left);
		}
	} else if(strcmp(word,node->word) > 0){
		//Means that word is higher in alphabet, so RIGHT
		//check to see that right node is not empty
		if(node->right == NULL){
			//if the right node is empty return 0
			return NULL;
		} else {
			//else continue searching for word
			getWord(word, node->right);
		}
	} else if(strcmp(word, node->word) == 0){
		//Same word so return the current node
		return node;
	}
	return NULL;
}

/*****************************************************************/

//This function lists the tree below it
void listTree(struct node * node){
	if( node->left != NULL){
		//do something for the left tree
		listTree(node->left);
	}
	else if(node->left == NULL){
		printf("%17s | %7d\n", node->word , node->cnt);
		fflush(stdout);
	}
	//do something for the center node
	if(node->right != NULL){
		if( node->left != NULL){
			printf("%17s | %7d\n", node->word , node->cnt);
			fflush(stdout);
		}
		//do something for the right node
		listTree(node->right);
	}
	else if(node->right == NULL && node->left != NULL){
		printf("%17s | %7d\n", node->word , node->cnt);
		fflush(stdout);
	}
}

/*****************************************************************/

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
