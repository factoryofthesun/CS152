#ifndef WARMUP2_H
#define WARMUP2_H

/* print_letter
 * input: uint number - the position in the alphabet of the letter to print
 * output: character that was printed to the screen.
 * summary: Given a number, print the corresponding capital letter 
 * of the alphabet. The number can be anything from 1 to 26. 1 prints 
 * out 'A', 2 prints out 'B', 3 prints out 'C', etc. It also returns 
 * the character.
 */
char print_letter(unsigned int number);

/* print_asterisk_letter
 * input: char letter - the letter to print out
 * output: nothing returned, just printed to the screen.
 * Given a character, print the corresponding upper-case letter of the 
 * alphabet using asterisks. The letter can be 'N', 'O', 'P', 'R'.
 */
void print_asterisk_letter(char letter);

/* draw_row
 * input: unsigned int width - the length of the row 
 * output: nothing
 * Given a width, prints a row of asterisks with that length */
void draw_row(unsigned int width);

/* draw_up, draw_down 
 * input: unsigned int width, unsigned int height
 * output: nothing
 * Given width and height, print increasing/decreasing rows of asterisks*/
void draw_up(unsigned int width, unsigned int height);

void draw_down(unsigned int width, unsigned int height);
/* draw_sideways_wedge_rec, draw_sideways_wedge_iter
 * input: uint width, uint height - starting width of row, height of wedge
 * output: nothing returned, just print to screen 
 * Given width and height, prints rows of asterisks that increase one per 
 * row until the middle, and then decreases until the starting width
*/

void draw_sideways_wedge_rec(unsigned int width, unsigned int height); 

void draw_sideways_wedge_iter(unsigned int width, unsigned int height); 

#endif


