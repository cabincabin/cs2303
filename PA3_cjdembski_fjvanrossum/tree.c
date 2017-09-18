/*
 * tree.c
 *
 *  Created on: Sep 17, 2017
 *      Author:Floris van Rossum & Clayton Dembski
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*Compare)(const char *, const char *);

struct node {
	char *word;
	struct node *left;
	struct node *right;
};

struct node* newNode(char word[]){
	struct node* node = (struct node*)malloc(sizeof(struct node));

	node->word[] = word[];
	node->left = NULL;
	node->right = NULL;
	return node;
}

void insert(char* key, struct node ** leaf, Compare cmp){

}
