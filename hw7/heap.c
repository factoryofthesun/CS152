#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include <string.h>
#include "word.h"
#include "compress.h"
/*
typedef struct _heapnode heapnode;

struct _heapnode {
  struct encodingTree *tree;
  heapnode *lsub;
  heapnode *rsub;
};
*/
/* CREATION FUNCTION */
/* create an empty heap */
heap* create_heap(int size){
	heap *hp = (heap *) malloc(sizeof(heap)); 
	void **array = (void **) malloc(sizeof(void *)*size); 
	hp->node_array = array; 
	hp->cur_num_nodes = 0; 
	hp->allocated_nodes = size; 
	return hp; 
}
/*
void free_hpnode(heapnode* node)
{
	if(node == NULL)
		return;
	free_hpnode(node->lsub); 
	free_hpnode(node->rsub); 
	free(node); 
}
*/
/* free the tree and all the **nodes** of the heap but
 * not the memory each item points to.
 */
void free_heap(heap* tree){
	if(tree == NULL)
		return;
	free(tree->node_array); 
	free(tree);  
}

/* Heap Insert
 * Inserts elements into the binary tree, following heap protocol:
 *   1. Element is added to the bottom of the heap
 *   2. Element is compared with its parent, stopping if they are in the correct order
 *   3. Element and parent are swapped, and go to step 2
 */
void heap_insert(heap *hp, void *item, int (*compare)(void *, void *)){
	if(hp == NULL) 
	{
		return;
	}
	void **tmp_array = hp->node_array;
	//cur_num_nodes gives the index of the bottom of the heap
	int num_nodes = hp->cur_num_nodes; 
	*(tmp_array+num_nodes) = item; 
	int i = num_nodes; 
	hp->cur_num_nodes++; 
	//arr[i/2] gives the parent node 
	if(compare(item, tmp_array[i/2]) == -1)
	{
		//Swap parent and child, then loop until the order is correct 
		tmp_array[num_nodes] = tmp_array[i/2]; 
		tmp_array[i/2] = item; 
		i = i/2; 
		while(compare(item, tmp_array[i/2]) == -1)
		{
			tmp_array[i] = tmp_array[i/2]; 
			tmp_array[i/2] = item; 
			i = i/2;
		}
	}	
	
}

/* Heap Remove
 * Removes root of the binary heap, following heap protocol:
 *       1. Element at root of the heap is removed and replaced with element from last level
 *       2. New root is compared with children, stopping if they are in the correct order
 *       3. Element and one of its children are swapped, and go to step 2
 */
void* heap_remove(heap *hp, int (*compare)(void *, void *))
{
	if(hp == NULL) 
	{
		return NULL; 
	}
	//Remove root and replace with last level element
	void **tmp_array = hp->node_array; 	
	void *head = *tmp_array; 
	int alloc_nodes = hp->cur_num_nodes-1;
	void *new = tmp_array[alloc_nodes]; 
	*tmp_array = new; 
	int i = 0; 
	hp->cur_num_nodes--; 
	//Check if root item is greater than any child node, loop through children until order is correct 
	//Make sure that indices are not out of bounds 
	while(((2*i+1 < hp->cur_num_nodes)&& (compare(new, tmp_array[2*i + 1]) == 1)) || ((2*i+2 < hp->cur_num_nodes)&&(compare(new, tmp_array[2*i + 2]) == 1)))
	{
		if(2*i + 1 > hp->cur_num_nodes)
		{}
		else if(2*i +2 > hp->cur_num_nodes) 
		{		
			tmp_array[i] = tmp_array[2*i +1]; 
			tmp_array[2*i+1] = new; 
			i = 2*i + 1; 
		}
		else
		{	
			switch(compare(tmp_array[2*i+1], tmp_array[2*i+2])){
				case(-1):
				case(0): tmp_array[i] = tmp_array[2*i+1]; tmp_array[2*i+1] = new; i = 2*i +1; break; 
				case(1): tmp_array[i] = tmp_array[2*i+2]; tmp_array[2*i+2] = new; i = 2*i +2; break;	
			}
		}
	}
	return head; 

}

/* HEAP COMPARE
 * This compare function explicitly compare the frequency of two wordcount items contained
 * in two encodingTree nodes */
int heap_compare_counts(void *v1, void *v2)
{
        encodingNode *n1 = (encodingNode *) v1;
        encodingNode *n2 = (encodingNode *) v2;
        return compare_counts(n1->wc, n2->wc);
}

heap* get_heap_words(char *filename)
{
	char buffer[500];
	FILE *fp; 
	int lineno = 0; 
	heap *hp = create_heap(200); 
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
				wordcount *wc = create_count(temp);
				wc->count = 1;  
				heap_insert(hp, wc, compare_words); 				
				tokenPtr = strtok(NULL, " ,.'?!()\n");
			}
		
		}
	}
	return hp; 	
}

heap* get_heap_counts(char *filename)
{
        char buffer[500];
        FILE *fp;
        int lineno = 0;
        heap *hp = create_heap(200);
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
				wordcount *wc = create_count(temp); 
				wc->count = 1; 
                                heap_insert(hp, temp, compare_counts);
                                tokenPtr = strtok(NULL, " ,.'?!()\n");
                        }

                }
        }
        return hp;
}
