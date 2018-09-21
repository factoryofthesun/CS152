#include <stdlib.h>
#include "compress.h"
#include "word.h"
#include "heap.h"
#include "bst.h"
#include <string.h>
// Prototypes of functions used only within this file
// These do not belong in the .h file since they're only used here
// you need to make them into skeleton implementations rather than
// merely prototypes. Then add the encode/decode functions at the end.

/* CREATION FUNCTIONS */
/* create an empty encoding tree */
encodingTree* create_encodingTree()
{
	encodingTree *tree = (encodingTree *) malloc(sizeof(encodingTree)); 
	encodingNode *root = (encodingNode *) malloc(sizeof(encodingNode)); 
	tree->root = root; 
	return tree; 
}

/* free the tree and all the **nodes** of the encoding tree but 
 * not the memory each item points to.
 */
void free_nodes(encodingNode *node)
{
	if(node == NULL)
		return;
	free_nodes(node->lsub); 
	free_nodes(node->rsub); 
	free(node); 
}
void free_encodingTree(encodingTree* tree)
{
	if(tree == NULL)
		return; 
	free_nodes(tree->root); 
}

/* COMBINE */
/* combine two encodingNodes into an encodingTree sub-tree
 * for use within the encoding algorithm*/
encodingNode* combine(encodingNode *node1, encodingNode *node2)
{
	wordcount *word = (wordcount *) malloc(sizeof(wordcount)); 
	strcpy(word->word, ""); 
	word->count = node1->wc->count + node2->wc->count; 
	encodingNode *node = (encodingNode *) malloc(sizeof(encodingNode)); 
	node->wc = word; 
	if(compare_counts(node1->wc, node2->wc) <= 0)
	{
		node->lsub = node1; 
		node->rsub = node2; 
	}
	else
	{
		node->lsub = node2; 
		node->rsub = node1; 
	}
	return node; 
}

//Compares the counts of the wordcount structs within the nodes
/*
int compare_node_counts(void *node1, void *node2)
{
	encodingNode *n1 = (encodingNode *) node1; 
	encodingNode *n2 = (encodingNode *) node2; 
	return compare_counts(n1->wc, n2->wc); 
}
*/

/* CONSTRUCT COMPRESSION NODE HEAP
 * take the elements of the bst sorted by frequency and wrap each wordcount struct
 * inside of an encoding node, and insert each new encodingNode into a min-heap*/
heap* make_compressionnode_heap(bst *tree)
{
	heap *hp = create_heap(200); 
	void *item; 
	for(item = iterate(tree); item!= NULL; item = iterate(NULL))
	{
		encodingNode *node = (encodingNode *) malloc(sizeof(encodingNode)); 
		node->wc = (wordcount *) item; 
		node->lsub = NULL; node->rsub = NULL; 
		heap_insert(hp, node, heap_compare_counts); 
	}
	return hp; 
}

/* BUILD ENCODING TREE */
/* implementation of the encoding algorithm described in homework 7
 * makes use of the combine function defined above
 * creates an encoding/decoding tree from a min heap sorted by frequencies
 * inputs: min-heap pointer 
 * outputs: encodingTree pointer */
encodingTree* build_encoding_tree(heap *hp)
{
	void **array = hp->node_array; 
	encodingNode *n1; encodingNode *n2; encodingNode *new; 
	//Repeat algorithm until heap contains only one node
	while(hp->cur_num_nodes > 1)
	{
		n1 = (encodingNode *) heap_remove(hp, heap_compare_counts); 
		n2 = (encodingNode *) heap_remove(hp, heap_compare_counts); 
		new = combine(n1, n2);
		encodingNode *temp = (encodingNode *) *(hp->node_array);    
		heap_insert(hp, new, heap_compare_counts); 		
	}
	encodingTree *tree = create_encodingTree(); 
	tree->root = *(hp->node_array); 
	return tree; 	
}
void record_node_codes(encodingNode *node, char code[32], int bits)
{
	if((node->lsub == NULL) && (node->rsub==NULL))
	{
		node->wc->bits = bits; 
		code[bits] = '\0';
		strcpy(node->wc->codeword, code);
		printf("%s: %s\n", node->wc->word, code);  
		return;
	}
	else 
	{
	char temp1[32]; char temp2[32];
	strcpy(temp1, code); 
	strcpy(temp2, code);  
	temp1[bits] = '0'; temp2[bits] = '1';  
	record_node_codes(node->lsub, temp1, bits+1); 
	record_node_codes(node->rsub, temp2, bits+1); 
	}
}
/* CODEWORD BST */
/* This function iterates through the encodingTree and
 * extracts the codeword developed from our encoding tree. It then assigns this 
 * codeword to the corresponding wordcount struct 
 * inputs: encodingTree pointer
 * outputs: none - modifies existing wordcount structs*/
void record_codes(encodingTree* tree)
{
	char word[32]; int bits = 0; 
	record_node_codes(tree->root, word, bits); 
}

//Takes encoded tree with the assigned keywords and creates an alphabetically ordered tree 
void encode_to_bst(bst *btree, encodingNode *root)
{
	if(root == NULL)
		return;
	if((root->lsub == NULL) && (root->rsub == NULL))
	{
		bst_insert(btree, root->wc, compare_words); 
		return;
	}
	encode_to_bst(btree, root->lsub); 
	encode_to_bst(btree, root->rsub); 
}

//Finds the codeword for a given wordcount 
char *find_code(char *word, bstnode *root)
{
	if(root == NULL)
	{
		printf("find_code: word not found!\n"); 
		return NULL;
	}
	wordcount *wc = (wordcount *) root->item; 
	if(strcasecmp(word, wc->word) == 0)
		return wc->codeword; 
	else if(strcasecmp(word, wc->word) < 0)
		return find_code(word, root->lsub); 
	else
		return find_code(word, root->rsub); 
}

void print_enc_nodes(encodingNode *node)
{
	if(node == NULL)
		return;
	else if((node->lsub == NULL) && (node->rsub == NULL))
	{	
		print_word(node->wc); 
		return; 
	}
	else 
	{
		print_enc_nodes(node->lsub); 
		print_enc_nodes(node->rsub); 		
	}
}

void print_enc_tree(encodingTree *tree)
{
	if(tree == NULL)
		return; 
	else
		print_enc_nodes(tree->root); 	
}
// put your encode and decode functions here
encodingTree* encode(char *originalfile, char *encodedfile)
{
	//Read in the file into a bst, then create another bst orderd by counts 
	bst *tree = get_counts(originalfile);
	bst *freq_tree = create_bst(); 
	bst *dict_tree = create_bst(); 
	char code[32]; 
	void *item; 
	//Loop through first tree and reorder into freq_tree
	for(item = iterate(tree); item!= NULL; item = iterate(NULL))
		bst_insert(freq_tree, item, compare_counts);
	heap *hp = make_compressionnode_heap(freq_tree); 
	encodingTree *realtree = build_encoding_tree(hp); 
	record_codes(realtree); 
	//Sets dict_tree to the alphabetically ordered tree with wordcounts 
	encode_to_bst(dict_tree, realtree->root); 
	print_bst(dict_tree, print_word); 
	//Read in the file, then write in the code to a new file 
	FILE *newfile; 
	newfile = fopen(encodedfile, "w"); 
	char buffer[500];
        FILE *fp;
        int lineno = 0;
        if((fp = fopen(originalfile, "r")) == NULL)
        {
                printf("Could not open %s\n", originalfile);
                exit(1);
        }
        char temp[30];
        while(!feof(fp))
        {
                // read in the line and make sure it was successful
                if (fgets(buffer,500,fp) != NULL)
                {
                        char *string = buffer;
                        char *tokenPtr = strtok(string, " ,.'?!)(\n");
                        while(tokenPtr != NULL)
                        {
                                strcpy(temp, tokenPtr);
				strcpy(code, find_code(temp, dict_tree->root));
				fprintf(newfile, "%s", code);  
                                tokenPtr = strtok(NULL, " ,.'?!()\n");
                        }

                }
        }
	fclose(newfile); 
	return realtree; 
}

void decode(encodingTree *tree, char *encodedfile, char *decodedfile)
{
	encodingNode *root = tree->root; 
	encodingNode *temp_root = root; 
	FILE *newfile;
        newfile = fopen(decodedfile, "w");
        char buffer[500];
        FILE *fp;
        int lineno = 0;
        if((fp = fopen(encodedfile, "r")) == NULL)
        {
                printf("Could not open %s\n", encodedfile);
                exit(1);
        }
	char temp[30]; 
        while(!feof(fp))
        {
                // read in the line and make sure it was successful
                if (fgets(buffer,500,fp) != NULL)
                {
                        char *string = buffer;
                        char *tokenPtr = strtok(string, " ,.'?!)(\n"); 
			char first; 
                        while((*tokenPtr == '1') || (*tokenPtr == '0'))
                        {
				//Keep iterating through tree until hit a leaf
				while((temp_root->lsub != NULL) && (temp_root->rsub != NULL))
				{
					first = *tokenPtr; 
					if(first == '0')
					{
						temp_root = temp_root->lsub; 
						tokenPtr++; 
					}
					else
					{
						temp_root = temp_root->rsub; 
						tokenPtr++; 
					}
						
				}
                                strcpy(temp, temp_root->wc->word);
                                printf("decoded word: %s\n", temp); 
				//Write word to file and reset root pointer
                                fprintf(newfile, "%s ", temp);
                                temp_root = root; 
                        }

                }
        }
        fclose(newfile);
}
