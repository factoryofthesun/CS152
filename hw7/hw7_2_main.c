#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "word.h"
#include "hw6.h"
#include "heap.h"
#include "llist.h"
#include "compress.h"

int main()
{
	//Test creation functions
	encodingTree *tree = create_encodingTree(); 
	free_encodingTree(tree);
	printf("creation passed\n");  
	//Test combine function
	wordcount *w1 = create_count("left"); wordcount *w2 = create_count("right"); 
	w1->count = 2; w2->count = 2; 
	encodingNode *n1 = (encodingNode *) malloc(sizeof(encodingNode)); 
	encodingNode *n2 = (encodingNode *) malloc(sizeof(encodingNode)); 
	n1->wc = w1; n2->wc = w2; 
	encodingNode *combined = combine(n1, n2); 
	printf("combine successful\n"); 
	printf("%s, %s, %s\n", combined->wc->word, combined->lsub->wc->word, combined->rsub->wc->word); 
	//Test encode function
	encodingTree *key = encode("test_encode.txt", "code.txt"); 
	//Test decode function
	decode(key, "code.txt", "decode.txt"); 
}
