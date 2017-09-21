/*
 * tree.c
 *
 *  Created on: Sep 17, 2017
 *      Author:Floris van Rossum & Clayton Dembski
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//RIGHT IS HIGHER IN ALPHABET (B IS HIGHER THAN A SO RIGHT)
//LEFT IS LOWER IN ALPHABET (A IS LOWER THAN B SO LEFT)
struct node * getWord(char * word, struct node* node);
//This is a node that contains the string as well as a left and right node
struct node {
	char * word; //pointer to the char string
	int cnt; //An integer value that counts the number of words
	struct node *left; //left node
	struct node *right; //right node
};

//This function creates a new node
struct node * newNode(char * word1){
	struct node* node = (struct node*)malloc(sizeof(struct node)); //malloc the space for a new node
	node -> word = strncpy(((char *)malloc(strlen(word1)*sizeof(char))),  word1,20);
	node -> cnt = 1; //set count to 1
	node -> left = NULL;
	node -> right = NULL;
	return node;
}

//This function takes a word and inserts it into the tree, incrementing count
//or creating a new node

//TO-DO:
//Make this so that we can break up nodes and insert a node in between
void insertWord(char* word1, struct node * node){

	if(0 > strcmp(word1,node->word)){
		//Means that node.word is higher in alphabet

		//check that the left node is not empty
		if(node->left == NULL){
			node->left = newNode(word1);
		}
		else{

			insertWord(word1, node->left); //insert word in the left node
		}
	}

	else if(strcmp(word1,node->word) > 0){
		//Means that word is higher in alphabet, so RIGHT

		//check to see that right node is not empty
		if(node->right == NULL){
			node->right = newNode(word1); //create a new node
		} else {
			insertWord(word1, node->right); //insert word in right node
		}
	} else if(strcmp(word1,node->word) == 0){
		//Same word
		node->cnt++;//increment the count of word
	}
}

//This function allows you to enter a word and returns the number of those words
int getNumber(char* word,struct node* node){
	struct node * noded = getWord(word, node);
	if(noded == NULL){
		return 0;
	}
	return noded->cnt;
}

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

//This function lists the tree below it, don't know what to return yet here
void listTree(struct node * node){
	if( node->left != NULL){
		//do something for the left tree
		listTree(node->left);
	}
	//do something for the center node
	if(node->right != NULL){
		//do something for the right node
		listTree(node->right);
	}

	//return something here that will allow us to print out the whole thing
}
