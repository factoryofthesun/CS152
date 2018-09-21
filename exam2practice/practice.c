#include <stdio.h>
#include <stdlib.h>
#include "practice.h"
#include <string.h>

void print_first_value(llist *list){
	int val = *((int *) list->value); 
	printf("%d\n", val); 
}

int compare_ranks(void *r1, void *r2){
	enum Ranks *rank1 = (enum Ranks *) r1; 
	enum Ranks *rank2 = (enum Ranks *) r2; 
	if(rank1 < rank2)
		return -1; 
	else if(rank1 > rank2)
		return 1; 
	else
		return 0; 	
}

bst *create_bst(){
	bst *tree = (bst *) malloc(sizeof(bst)); 
	tree->root = NULL; 
	return tree; 
}

bstnode *bstnode_insert(bstnode *node, void *item, int (*compare)(void *, void *)){
	return NULL; 
}

void print_enum(void *r){
	enum Ranks *rank = (enum Ranks *) r; 
	switch(*rank){
		case bronze: printf("bronze\n"); break;
		case silver: printf("silver\n"); break;
		case gold: printf("gold\n"); break;
		case platinum: printf("plat\n"); break;
		case diamond: printf("diamond\n"); break;
		case challenger: printf("challenger\n"); break;
	}
}

void do_to_all_nodes(bstnode *node, void (*func)(void *)){
	if(node == NULL) 
		return; 
	func(node->item); 
	do_to_all_nodes(node->lsub, func); 
	do_to_all_nodes(node->rsub, func);
}

void do_to_all(bst *tree, void (*func)(void *)){
	if (tree)
		do_to_all_nodes(tree->root, func);
}

void print_list(llist *list, void (*print)(void *))
{
	llist *tmp; 
	for(tmp = list; tmp != NULL; tmp=tmp->next)
	{
		print(tmp->value); 
	}
}

void add_tail(llist *list, void *r){
	llist *tmp;
	for(tmp = list; tmp->next != NULL; tmp = tmp->next)
	{
	}
	llist *new = (llist *) malloc(sizeof(llist));
	new->value = r; 
	new->next = NULL;  
	tmp->next = new; 
	return;
}

int count_less_than(llist *lst, void *r, int (*comp)(void *, void *)){
	return 0; 
}

void *remove_head(llist *lst){
	llist *tmp = lst; 
	llist *new = tmp->next;  
	free(tmp);  
	return new; 
}
