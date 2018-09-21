#ifndef HW6_H
#define HW6_H
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "word.h"

/*get_counts
input: char* filename
output: bst* 
Takes in a filename, reads in file, and splits file into words. 
Words split by whitespace and any punctuation*/
bst* get_counts(char *filename);

bstnode* bstnodeword_insert(bstnode *node, char item[30],
                                int (*compare)(void *, void *));

void bstword_insert(bst *tree, char item[30], int (*compare)(void *, void *));


#endif
