#ifndef HEAP_H
#define HEAP_H

/*
typedef struct _heapnode heapnode;

struct _heapnode {
  struct encodingTree *tree;
  heapnode *lsub;
  heapnode *rsub;
}; 
*/

typedef struct {
  void **node_array;
  unsigned int cur_num_nodes;
  unsigned int allocated_nodes;
}heap;

/* CREATION FUNCTION */
/* create an empty heap */
heap* create_heap(int size);

/* free the tree and all the **nodes** of the heap but 
 * not the memory each item points to.
 */
void free_heap(heap* tree); 

/* Heap Insert
 * Inserts elements into the binary tree, following heap protocol:
 *   1. Element is added to the bottom of the heap
 *   2. Element is compared with its parent, stopping if they are in the correct order
 *   3. Element and parent are swapped, and go to step 2
 */
void heap_insert(heap *hp, void *item, int (*compare)(void *, void *));

/* Heap Remove
 * Removes root of the binary heap, following heap protocol:
 *	 1. Element at root of the heap is removed and replaced with element from last level
 *	 2. New root is compared with children, stopping if they are in the correct order
 *	 3. Element and one of its children are swapped, and go to step 2
 */
void* heap_remove(heap *hp, int (*compare)(void *, void *));

/* HEAP COMPARE 
 * This compare function explicitly compare the frequency of two wordcount items contained
 * in two encodingTree nodes */
int heap_compare_counts(void *v1, void *v2);

heap* get_heap_counts(char *filename); 

heap* get_heap_words(char *filename); 

#endif
