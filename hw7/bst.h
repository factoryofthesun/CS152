#ifndef BST_H
#define BST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct _bstnode bstnode;

struct _bstnode {
  void* item;
  bstnode *lsub;
  bstnode *rsub;
}; 

typedef struct {
 bstnode *root;
} bst;

/* CREATION FUNCTIONS */
/* create an empty bst */
bst* create_bst(); // warmup


/* free the tree and all the **nodes** of the bst but 
 * not the memory each item points to.
 */
void free_bst(bst* tree); // hw

/* INFORMATIONAL FUNCTIONS */
/* provide some generic funcions that will apply the same
 * function to all nodes in a bst. Use an inorder traversal.
 */
int accum_all(bst *tree, int (*func)(void*));  // warmup
void do_to_all(bst *tree, void (*func)(void*)); // hw
void* find(bst *tree, void* item, int (*compare)(void*, void*)); // warmup
void print_bst(bst *tree, void (*print_item)(void*)); // hw

/* MODIFICATION FUNCTIONS */
/* insertion in sorted order */
void bst_insert(bst *tree, void *item, int (*compare)(void *, void *));


/* ITERATOR */
/* iterate
 * create an iterator that navigates the tree with an inorder
 * traversal. If a non-NULL tree is passed in, then the
 * iterator resets to the first node. It returns the item in the
 * first node (as defined by inorder traversal).  If a NULL tree
 * is passed in, then return the item in the next node.
 *
 * Hint: The entire navigation occurs when the non-NULL tree is
 * passed in. The results are stored in a data structure, which is
 * accessed each time to provide the next one. You may make a
 * helper function for this.
 */
void* iterate(bst* tree);

#endif

