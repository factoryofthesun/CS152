#ifndef WARMUP4_H
#define WARMUP4_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warmup4_provided.h"

/* int count_vowels(char *str)
inputs: string/character pointer
output: integer
count the number of vowels in the input string  
*/
int count_vowels(char *str); 

/*void make_lowercase(char *str)
input: string 
output: modified string
change all capital letters to lower case
*/
void make_lowercase(char *str); 

/*typedef struct {
	unsigned int red;
	unsigned int green;
	unsigned int blue;
} pixel;

pixel** make_and_init_image(int height, int width, pixel color)
input: height, width, pixel color
output: 2d array of pixels
creates an array of length height, with each element pointing to an array of pixels 
*/
pixel** make_and_init_image(int height, int width, pixel color);

#endif
