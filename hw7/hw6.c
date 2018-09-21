#include <stdio.h>
#include <stdlib.h>
#include "hw6.h"
#include <string.h>
#include "bst.h"
#include "word.h"

bstnode* bstnodeword_insert(bstnode *node, char item[30],
                                int (*compare)(void *, void *))
{
	wordcount *wc = create_count(item); 
	wc->count = 1; 
        //First check if tree is empty
        if(node == NULL)
        {
                bstnode *new = (bstnode *) malloc(sizeof(bstnode));
                new->item = wc;
                new->lsub = NULL;
                new->rsub = NULL;
                node = new;
                return node;
        }
	//If item is equal to root word, then add one to count 
	if(compare(node->item, wc) == 0)
	{
		wordcount *temp = (wordcount *) node->item;
		increment_count(temp); 
		return node; 
	}
        //If item is larger than or equal to root word, run down rightsubtree
        else if(compare(node->item, wc) == -1)
        {
                //If nothing in rsub, then insert item as the rsub leaf
                if(node->rsub == NULL)
                {
			bstnode *new = (bstnode *) malloc(sizeof(bstnode));
                	new->item = wc;
                	new->lsub = NULL;
                	new->rsub = NULL;
                	node->rsub = new;
                        return node;
                }
                else
                {
                        bstnodeword_insert(node->rsub, item, compare);
                        return node;
                }
        }
        //Else, run down left subtree
        else
        {
                if(node->lsub == NULL)
                {
			bstnode *new = (bstnode *) malloc(sizeof(bstnode));
                	new->item = wc;
                	new->lsub = NULL;
               		new->rsub = NULL;
                	node->lsub = new;
                        return node;

                }
                else
                {
                        bstnodeword_insert(node->lsub, item, compare);
                        return node;
                }
        }
}

void bstword_insert(bst *tree, char item[30], int (*compare)(void *, void *))
{
	if(tree)
		tree->root = bstnodeword_insert(tree->root, item, compare); 
}

bst* get_counts(char *filename)
{
	char buffer[500];
	FILE *fp; 
	int lineno = 0; 
	bst *tree = create_bst(); 
	if((fp = fopen(filename, "r")) == NULL)
	{
		printf("Could not open %s\n", filename);
		exit(1);
	}
	char temp[30];
	//int i = 0; 
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
				bstword_insert(tree, temp, compare_words); 				
				tokenPtr = strtok(NULL, " ,.'?!()\n");
			}
		
		}
	}
	return tree; 	
}

bst* get_compare_counts(char *filename)
{
        char buffer[500];
        FILE *fp;
        int lineno = 0;
        bst *tree = create_bst();
        if((fp = fopen(filename, "r")) == NULL)
        {
                printf("Could not open %s\n", filename);
                exit(1);
        }
        char temp[30];
        //int i = 0;
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
                                bstword_insert(tree, temp, compare_counts);
                                tokenPtr = strtok(NULL, " ,.'?!()\n");
                        }

                }
        }
        return tree;
}
