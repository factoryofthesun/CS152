#ifndef COMPRESS_H
#define COMPRESS_H

#include "word.h"
#include "bst.h"
#include "heap.h"
#include "hw6.h"

typedef struct _encodingNode encodingNode;

struct _encodingNode {
  wordcount *wc;
  encodingNode *lsub;
  encodingNode *rsub;
}; 

typedef struct {
 encodingNode *root;
} encodingTree;

encodingTree* create_encodingTree();
void free_encodingTree(encodingTree* tree);
encodingNode* combine(encodingNode *node1, encodingNode *node2);
heap* make_compressionnode_heap(bst *tree);
encodingTree* build_encoding_tree(heap *hp);
void record_codes(encodingTree* tree);


/* ENCODE TEXT FILE */
/* this function will take as input the words in the file, create an encoding tree,
 * and output the corresponding encoding. The function will read the file,
 * split into words, and apply the corresponding codes from the encodingTree 
 * inputs: a text file
 * outputs: a new encoded text file */
encodingTree* encode(char *originalfile, char *encodedfile);

/* DECODE */
/* implementation of decoding algorithm described in homework 7, 
 * takes as a parameter an encoding tree created by the encode function above 
 * inputs: encodingTree pointer created by encoding function, and a compressed file
 * outputs: decoded text file */
void decode(encodingTree *tree, char *encodedfile, char *decodedfile);



#endif
