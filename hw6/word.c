#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "word.h"

/* create_count
 * creates a wordcount struct, copies the word to its memory,
 * and initializes the count to 0.
 */
wordcount *create_count(char *word)
{
        wordcount *wc = (wordcount *)malloc(sizeof(wordcount));
        strcpy(wc->word,word);
        wc->count = 0;
        return wc;

}

/* This frees all of the dynamically allocated fields (just word) */
void free_count(wordcount *wc)
{
	free(wc);
}

/* increment_count
 * increments the count field of a wordcount struct
 */
void increment_count(wordcount *wc)
{
	wc->count = wc->count+1;
}

/* get_count
 * this function is provided to test your accumulator function
 * for your BST.
 * This returns the count in a particular word.
 */
int get_count(void *v)
{
	wordcount *wc = (wordcount*)v;
	return wc->count;
}

/* print_word
 * print function that prints the contents of a single countword struct
 */
void print_word(void* v)
{
	wordcount *wc = (wordcount*)v;
	printf("%s: %d\n",wc->word, wc->count);
}

/* compare_words
 * This function compares two wordcount structs. It compares by comparing
 * the words being stored. The order is the same order as in strcmp.
 * It returns -1 if v1 < v2, 0 if v1 == v2, and 1 if v1 > v2 as defined
 * by alphabetical order.
 */
int compare_words(void *v1, void *v2)
{
        wordcount *w1 = (wordcount *) v1;
        wordcount *w2 = (wordcount *) v2;
        if(strcasecmp(w1->word, w2->word)<0)
                return -1;
        else if(strcasecmp(w1->word,w2->word) == 0)
                return 0;
        else
                return 1;
}


/* compare_counts
 * This function compares two wordcount structs. It compares by comparing
 * the counts being stored. 
 * It returns -1 if v1 < v2, 0 if v1 == v2, and 1 if v1 > v2 as defined
 * by the value of the count fields.
 */
int compare_counts(void *v1, void *v2)
{
        wordcount *w1 = (wordcount *) v1;
        wordcount *w2 = (wordcount *) v2;
        if(w1->count < w2->count)
                return -1;
        else if(w1->count == w2->count)
                return 0;
        else
                return 1;

}

