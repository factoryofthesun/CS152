#ifndef PRACTICE_H
#define PRACTICE_H

typedef struct _llist llist; 
struct _llist{
	void *value; 
	llist *next; }; 

typedef struct _bstnode bstnode; 
struct _bstnode{
	void *item;
	bstnode *lsub; 
	bstnode *rsub;
};

typedef struct {
 bstnode *root;
} bst;

enum Ranks {bronze, silver, gold, platinum, diamond, challenger}; 

void print_enum(void *r); 

void print_list(llist *list, void (*print)(void *)); 

void print_first_value(llist *list); 

int compare_ranks(void *r1, void *r2); 

bst *create_bst(); 

bstnode *bstnode_insert(bstnode *node, void *item, int (*compare)(void *, void *)); 

void do_to_all_nodes(bstnode *node, void (*func)(void *)); 

void do_to_all(bst *tree, void (*func)(void *)); 

void add_tail(llist *list, void *r); 

void *remove_head(llist *lst);

int count_less_than(llist *lst, void *r, int (*comp)(void *, void *)); 
#endif
