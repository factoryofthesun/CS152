#include <stdio.h>
#include <stdlib.h>
#include "warmup4.h"
#include "warmup4_provided.h"
#include <string.h>
/* int count_vowels(char *str)
inputs: string/character pointer
output: integer
count the number of vowels in the input string
*/
int count_vowels(char *str)
{
	int count = 0;
	//loop through entire string, checking if each char is a vowel
	for (int i =0; i<strlen(str); i++)
	{	
		switch(str[i]){
			case('a'):
			case('A'):
			case('e'): 
			case('E'):
			case('i'):
			case('I'):
			case('o'): 
			case('O'): 
			case('u'):
			case('U'): count++; break;
		}
	}
	return count; 	
}
/*void make_lowercase(char *str)
input: string
output: modified string
change all capital letters to lower case
*/
void make_lowercase(char *str)
{
	int length = strlen(str); 
	//loops through string and converts uppercase to lower
	for (int i = 0; i < length; i++)
	{
		if((str[i] >= 'A') && (str[i] <= 'Z'))
			str[i] = str[i] + 32;
		printf("%c", str[i]); 
	}
	return;	
}
/*pixel** make_and_init_image(int height, int width, pixel color)
input: height, width, pixel color
output: 2d array of pixels
creates an array of length height, with each element pointing to an array of pixels
*/
pixel** make_and_init_image(int height, int width, pixel color)
{	//initialize and allocate memory to 2d pixel array 
	pixel **ptr_main = (pixel **) malloc(sizeof(pixel *)*height); 
	for(int j = 0; j < height; j++)
	{
	 	ptr_main[j] = (pixel *) malloc(sizeof(pixel) * width); 
		for(int i = 0; i < width; i++)
		{
			ptr_main[j][i] = color; 		
		}
	}
	return ptr_main; 
}

