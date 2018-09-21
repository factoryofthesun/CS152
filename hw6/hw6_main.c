#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "bst.c"
#include "word.h"
#include "word.c"
#include "hw6.h"

int main()
{
	//test compare functions 
	char word1[] = "baZinga";
	char word2[] = "aazinga";
	char word3[] = "Bazinga";
	wordcount *w1 = create_count(word1);
	wordcount *w2 = create_count(word2);
	wordcount *w3 = create_count(word3); 
	w1->count = 1; 
	w2->count = 0; 
	w3->count = 1;
	if(compare_words(w1, w2) == 1)
		printf("compare_words test 1 pass\n"); 
	else 
		printf("compare_words test 1 fail\n"); 
	if(compare_words(w1, w3) == 0)
		printf("compare_words test 2 pass\n"); 
	else
		printf("compare_words test 2 fail\n"); 
	if(compare_counts(w2, w1) == -1)
		printf("compare_counts test 1 pass\n"); 
	else 
		printf("compare_counts test 1 fail\n"); 
	if(compare_counts(w3, w1) == 0)
                printf("compare_counts test 2 pass\n");
        else
                printf("compare_counts test 2 fail\n"); 

	//Test get_counts 
	bst *tree = get_counts("test1.txt"); 
	print_bst(tree, print_word); 
	//Test bst functions
	do_to_all(tree, increment_count); 
	print_bst(tree, print_word); 
	int sum = accum_all(tree, get_count); 
	printf("accum_all: %d\n", sum); 
	//Test find
	wordcount *find_me = create_count("told"); 
	find_me->count = 0; 
	wordcount *w4 = (wordcount *) find(tree, find_me, compare_words);
	if(compare_words(w4, find_me) == 0)
		printf("find test 1 success \n"); 
	else
		printf("find test 1 fail\n"); 
	wordcount *w5 = (wordcount *) find(tree, find_me, compare_counts); 
	if(w5 == NULL)
		printf("find test 2 success\n"); 
	else
		printf("find test 2 fail\n"); 
}
