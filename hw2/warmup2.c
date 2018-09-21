#include <stdlib.h>
#include <stdio.h>
#include "warmup2.h"

/* print_letter
 * input: uint number - the position in the alphabet of the letter to print
 * output: character that was printed to the screen.
 * summary: Given a number, print the corresponding capital letter 
 * of the alphabet. The number can be anything from 0 to 25. 0 prints 
 * out 'A', 1 prints out 'B', 2 prints out 'C', etc. It also returns 
 * the character.
 */
char print_letter(unsigned int number)
{ 
	if (number > 25)
	{
	 fprintf(stderr, "ERROR: print_letter: Received input %u, between 0 and 25 expected\n", number);
	 return ' ';
	}
	char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 
				'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	char letter = alphabet[number];
	printf("%c\n", letter);
	return letter;
}

/* print_asterisk_letter
 * input: char letter - the letter to print out
 * output: nothing returned, just printed to the screen.
 * Given a character, print the corresponding upper-case letter of the 
 * alphabet using asterisks. 
 */
void print_asterisk_letter(char letter)
{ 
	if ((letter < 'N') || (letter > 'R')){
		fprintf(stderr, "ERROR: print_asterisk_letter: Received input %c, Between N and R expected", letter);
	}
	switch(letter){
		case('N'): printf("*   *\n**  *\n* * *\n*  **\n*   *\n"); break;
		case('O'): printf(" *** \n*   *\n*   *\n*   *\n *** \n"); break;
		case('P'): printf(" *** \n*   *\n**** \n*\n*\n"); break;
		case('R'): printf("**** \n*   *\n**** \n*  *\n*   *\n"); break;
	}
}

/* draw_sideways_wedge_rec, draw_sideways_wedge_iter
 * input: uint width, uint height - starting width of row, height of wedge
 * output: nothing returned, just print to screen
 * Given width and height, prints rows of asterisks that increase one per
 * row until the middle, and then decreases until the starting width
*/
void draw_row(unsigned int width){
	if(width == 0){
		printf("\n");
		return;}
	printf("*");
	draw_row(width-1);
}

void draw_sideways_wedge_rec(unsigned int width, unsigned int height)
{
	if(height == 0){
		return;}
	else if(height == 1){
		draw_row(width);}
	else {
		draw_row(width);
		draw_sideways_wedge_rec(width+1, height-2);
		draw_row(width);}
}

void draw_sideways_wedge_iter(unsigned int width, unsigned int height)
{
	int mid = 0;
	if(height%2 == 0){
		mid = height/2;
		 } 
	else{
		mid = height/2 + 1;
	}
	while(height > mid){
		for(int i = 0; i<width; i++){
			printf("*");}
		printf("\n");
		width++;
		height--;}
	if(height%2 == 0){
		width--;
		for(int i = 0; i<width; i++){
			printf("*");}
		printf("\n");
		width--;}
	else{
		for(int i = 0; i<width; i++){
                        printf("*");}
                printf("\n");
		width--;}	
	while(height >= 1){
		for(int i = 0; i < width; i++){
			printf("*");}
		printf("\n");
		width--;
		height--;}
}


