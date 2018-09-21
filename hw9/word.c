#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "word.h"
#include <limits.h>
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
	int count = wc->count; 
	char *word = wc->word; 
	printf("%s: %d",word, count);
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

int chartonum(char letter){
	switch(letter){
		case('a'): case('A'): return 1; break;
		case('b'): case('B'): return 2; break;
		case('c'): case('C'): return 3; break;
		case('d'): case('D'): return 4; break;
		case('e'): case('E'): return 5; break;
		case('f'): case('F'): return 6; break;
		case('g'): case('G'): return 7; break;
		case('h'): case('H'): return 8; break;
		case('i'): case('I'): return 9; break;
		case('j'): case('J'): return 10; break;
		case('k'): case('K'): return 11; break;
		case('l'): case('L'): return 12; break;
		case('m'): case('M'): return 13; break;
		case('n'): case('N'): return 14; break;
		case('o'): case('O'): return 15; break;
		case('p'): case('P'): return 16; break;
		case('q'): case('Q'): return 17; break;
		case('r'): case('R'): return 18; break;
		case('s'): case('S'): return 19; break;
		case('t'): case('T'): return 20; break;
		case('u'): case('U'): return 21; break;
		case('v'): case('V'): return 22; break;
		case('w'): case('W'): return 23; break;
		case('x'): case('X'): return 24; break;
		case('y'): case('Y'): return 25; break;
		case('z'): case('Z'): return 26; break;
	}
	fprintf(stderr, "error chartonum: character out of range\n");
	return UINT_MAX; 	
}

/* get_key
 * transforms the word into an integer key
 */
unsigned long int get_key(void *v)
{
	wordcount *wc = (wordcount *) v; 
	unsigned long int res = 0; 
	char *tmp; 
	for(tmp = wc->word; *tmp != '\0'; tmp++)
	{
		res = res*27 + chartonum(*tmp); 
	}
	return res; 
}
