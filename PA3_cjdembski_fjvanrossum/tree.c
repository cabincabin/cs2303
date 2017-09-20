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

//This is a node that contains the string as well as a left and right node
struct node {
	char *word; //pointer to the char string
	int cnt; //An integer value that counts the number of words
	struct node *left; //left node
	struct node *right; //right node
};

//This function creates a new node
struct node * newNode(char * word){
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node -> word = word;
	node -> cnt = 1; //set count to 1
	node -> left = NULL;
	node -> right = NULL;
	return node;
}

//This function takes a word and inserts it into the tree, incrementing count
//or creating a new node
void insertWord(char* word, struct node * node){
	if((0 > strcmp(word,node.word))){
		//Means that node.word is higher in alphabet

		//check that the left node is not empty
		if(node.left == NULL){
			newNode(word);
		} else{
			insertWord(word, node.right); //insert word in the left node
		}
	} else if(strcmp(word,node.word) > 0){
		//Means that word is higher in alphabet, so RIGHT

		//check to see that right node is not empty
		if(node.right == NULL){
			newNode(word); //create a new node
		} else {
			insertWord(word, node.right); //insert word in right node
		}
	} else if(strcmp(word,node.word) == 0){
		//Same word
		node -> cnt++;//increment the count of word
	}
}

//This function allows you to enter a word and returns the number of those words
int getNumber(char* word){
	struct node * node = getWord(word);
	return node->cnt;
}

// Returns the pointer to a node when you enter a word
struct node * getWord(char * word, struct node* node){
	if((0 > strcmp(word,node.word))){
		//Means that node.word is higher in alphabet
		//check that the left node is not empty
		if(node.left == NULL){
			newNode(word);
		} else{
			insertWord(word, node.right); //insert word in the left node
		}
	} else if(strcmp(word,node.word) > 0){
		//Means that word is higher in alphabet, so RIGHT
			//check to see that right node is not empty
		if(node.right == NULL){
			newNode(word); //create a new node
		} else {
			insertWord(word, node.right); //insert word in right node
		}
	} else if(strcmp(word,node.word) == 0){
		//Same word
		node -> cnt++;//increment the count of word
	}

}

