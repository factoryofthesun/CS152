#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "llist.h"

/* here are the functions that are implemented within this file but
 * are not allowed to be called by other files
 * These are helper functions necessary because we now have split
 * the struct of a bsttree from the struct of a bstnode.
 */
void do_to_all_nodes(bstnode *node, void (*func)(void*));
int accum_all_nodes(bstnode *node, int (*func)(void*));
bstnode* bstnode_insert(bstnode *node, void *item, 
				int (*compare)(void *, void *));
void* find_node(bstnode *node, void *item,
				int (*compare)(void*, void*));


/* CREATION FUNCTIONS */
/* create an empty bst */
bst* create_bst()
{
	bst *tree = (bst *) malloc(sizeof(bst));
	tree->root = NULL; 
	return tree; 
}

/* INFORMATIONAL FUNCTIONS */
/* provide some generic funcions that will apply the same
 * function to all nodes in a bst
 */

/* do_to_all_nodes - 
 * apply a function (func) to all nodes in the subtree rooted at (node)
 */
void do_to_all_nodes(bstnode *node, void (*func)(void*))
{
	if(node == NULL) 
		return; 
	func(node->item); 
	do_to_all_nodes(node->lsub, func); 
	do_to_all_nodes(node->rsub, func); 
}

/* do_to_all -
 * apply a function (func) to all nodes in the tree
 */
void do_to_all(bst *tree, void (*func)(void*))
{
	if (tree)
		do_to_all_nodes(tree->root, func);
}

/* accum_all_nodes -
 * apply a function (func) to all nodes in the subtree rooted at (node)
 * and sum up the results.
 */
int accum_all_nodes(bstnode *node, int (*func)(void*))
{
	 if(node == NULL)
                return 0;
        int lsum = accum_all_nodes(node->lsub, func);
        int rsum = accum_all_nodes(node->rsub, func);
        return func(node->item) + lsum + rsum;
}
/* accum_all -
 * apply a function (func) to all nodes in the tree and sum up the results.
 */
int accum_all(bst *tree, int (*func)(void*))
{
	if(tree)
		return accum_all_nodes(tree->root, func); 
}

/* find - 
 * find the item in the subtree rooted at node that is equivalent 
 * (as described by compare) to particular item (item).
 */
void* find_node(bstnode *node, void* item, int (*compare)(void*, void*))
{
	if(node == NULL)
                return NULL;
        else if(compare(node->item, item) == 0)
                return node->item;
        else {
                void *lfind = find_node(node->lsub, item, compare);
                void *rfind = find_node(node->rsub, item, compare);
                if(lfind != NULL)
                        return lfind;
                else if(rfind != NULL)
                        return rfind;
                else
                        return NULL;
                }
}

void* find(bst *tree, void* item, int (*compare)(void*, void*))
{
	if(tree)
		return find_node(tree->root, item, compare); 
	return NULL; 
}


/* print_bst - 
 * print the items in the tree from smallest to largest
 * (as described by the compare function used for insertion)
 */
void print_node(bstnode *node, void (*print_item)(void *))
{
	if(node==NULL)
		return;
	print_item(node->item); 
	print_node(node->lsub, print_item); 
	print_node(node->rsub, print_item); 
}
void print_bst(bst *tree, void (*print_item)(void *))
{
	if(tree)
		print_node(tree->root, print_item); 
}

/* MODIFICATION FUNCTIONS */
/* insertion in sorted order. Return the root of the subtree of the 
 * modified tree at this point.
 */
bstnode* bstnode_insert(bstnode *node, void *item, 
				int (*compare)(void *, void *))
{
	//First check if tree is empty 
	if(node == NULL)
	{
		bstnode *new = (bstnode *) malloc(sizeof(bstnode)); 
		new->item = item; 
		new->lsub = NULL; 
		new->rsub = NULL; 
		node = new;
		return node;  
	}
        //If item is larger than or equal to root, run down rightsubtree
	else if(compare(node->item, item) <= 0)
        {
                //If nothing in rsub, then insert item as the rsub leaf
                if(node->rsub == NULL)
                {
                        bstnode *new = (bstnode *) malloc(sizeof(bstnode));
                        new->item = item;
                        new->lsub = NULL;
                        new->rsub = NULL;
                        node->rsub = new;
			return node; 
                }
                else
		{
                 	bstnode_insert(node->rsub, item, compare);
			return node; 
		}
	}
        //Else, run down left subtree
        else
        {
                if(node->lsub == NULL)
                {
			bstnode *new = (bstnode *) malloc(sizeof(bstnode));
                        new->item = item;
                        new->lsub = NULL;
                        new->rsub = NULL;
                        node->lsub = new;
			return node;
			
                }
                else
		{
                      bstnode_insert(node->lsub, item, compare);
			return node; 
		}
        }
}

void bst_insert(bst *tree, void *item, int (*compare)(void *, void *))
{
	if(tree)
		tree->root = bstnode_insert(tree->root, item, compare); 
}

//Initial input for llist is an empty list 
void node_to_list(bstnode *treenode, llist *list)
{
	if(treenode == NULL)
	{
		return;
	}
	node_to_list(treenode->lsub, list);
	//Insert tail the node
	insert_tail(list, treenode->item); 
	node_to_list(treenode->rsub, list); 
}

//Updates a linked list from a tree ordered by in-order traversal
llist *tree_to_list(bst *tree)
{
	if(tree)
	{
		llist *list = create_llist(); 
		node_to_list(tree->root, list); 
		return list; 
	}
}
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
void* iterate(bst* tree)
{
	static node *tmp = NULL;
	if(tree != NULL)
	{
		llist *list = tree_to_list(tree); 
		tmp = list->head; 
	}
	if(tmp == NULL)
		return NULL; 
	void *retval = 	tmp->item; 
	tmp = tmp->next; 
	return retval; 
}



/* free_bst
 * frees all of the nodes in the bst tree
 */
void free_bst(bst* tree)
{
	do_to_all(tree, &free);  
	free(tree); 	
}
