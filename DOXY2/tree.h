/*
 * tree.h
 *
 *  Created on: Sep 20, 2017
 *      Author: student
 */

#ifndef TREE_H_
#define TREE_H_

struct node * newNode(char * word);
void insertWord(char * word, struct node * node);
void listTree(struct node * node);
void derefTree(struct node * node);
void numUniqueWords();

#endif /* TREE_H_ */
