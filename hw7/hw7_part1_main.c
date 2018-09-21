#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "word.h"
#include "hw6.h"
#include "heap.h"
#include "llist.h"

int main()
{
	//test linked list functions
	llist *list1 = create_llist();
	char word1[] = "hello"; char word2[] = "hallo";	
	wordcount *w1 = create_count(word1); wordcount *w2 = create_count(word2); 
	insert_head(list1, w1); 
	insert_head(list1, w2); 
	if((compare_words(w2, list1->head->item) == 0) && (compare_words(w1, list1->tail->item) == 0))
		printf("llist test 1 pass\n"); 
	remove_tail(list1);
	remove_tail(list1);
	if(list_is_empty(list1))
		printf("llist test 2 pass\n"); 
	/*
	//Test iterator 
	bst *tree1 = get_counts("test1.txt"); 
	bst *tree2 = create_bst();  
	heap *hp1 = create_heap(200); 
	heap *hp2 = create_heap(200); 
	void *item; 
	printf("tree1 compare word\n"); 
	for(item = iterate(tree1); item!= NULL; item = iterate(NULL))
	{
		print_word(item); 
		bst_insert(tree2, item, compare_counts);
		heap_insert(hp1, item, compare_words); 
	}
	printf("tree2 compare counts\n"); 	
	for(item = iterate(tree2); item!= NULL; item = iterate(NULL))
		print_word(item); 

	//Test heap 
	void **array1 = hp1->node_array; 
	int length = hp1->cur_num_nodes; 
	printf("heap1 compare word\n"); 	
	for(int i = 0; i < length; i++) 
	{
		print_word(array1[i]);
		heap_insert(hp2, array1[i], compare_counts);  
	}
	printf("heap2 compare count\n"); 
	void **array2 = hp2->node_array; 
	for(int i = 0; i < length; i++)
		print_word(array2[i]); 	
	*/
}
