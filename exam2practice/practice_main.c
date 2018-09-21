#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "practice.h"
#include <string.h>

int main()
{
	int a = 1; 
	llist *tmp; 
	tmp->value = (void *) &a; 
	tmp->next = NULL; 
	print_first_value(tmp); 
	
	//test basic bst/rank functions
	enum Ranks r1 = silver; 
	enum Ranks r2 = gold; 
	enum Ranks r3 = challenger; 
	printf("%d, %d, %d\n", compare_ranks(&r1, &r1), compare_ranks(&r1, &r2), compare_ranks(&r3, &r2)); 

	bst *bst1 = create_bst(); 
	bstnode *bs2 = (bstnode *) malloc(sizeof(bstnode)); 
	bs2->item = &r1; bs2->lsub = NULL; bs2->rsub = NULL; 
	bstnode *bs3 = (bstnode *) malloc(sizeof(bstnode)); 
	bs3->item = &r3; bs3->lsub = NULL; bs3->rsub = NULL; 
	bstnode *root = (bstnode *) malloc(sizeof(bstnode)); 
	root->item = &r2; root->lsub = bs2; root->rsub = bs3;
	bst1->root = root; 	
	do_to_all(bst1, print_enum);  

	llist *main = (llist *) malloc(sizeof(llist)); 
	main->value = &r1; 
	main->next = NULL; 
	add_tail(main, &r2); 
	add_tail(main, &r1); 
	print_list(main, print_enum); 
	
	llist *new = (llist *) remove_head(main);
	printf("remove_head: ");   
	print_list(new, print_enum); 
}	
