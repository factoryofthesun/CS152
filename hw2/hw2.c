#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "hw2.h"
#include "warmup2.c"

/* print_pilot_word
 * given a character, print the pilot word for that letter
 * alphabet
 * inputs:
 *   char letter - 'a' to 'z' or 'A' to 'Z' or '0' to '9'
 * output:
 *   prints out, but does not return, the word corresponding
 *   to the letter.
 *   returns the number of letters in the word printed out
 */
int print_pilot_word(char letter){
	switch(letter){
		case('a'): case('A'): printf("Alpha\n"); return 5; break; 
		case('b'): case('B'): printf("Bravo\n"); return 5; break;
		case('c'): case('C'): printf("Charlie\n"); return 6; break;
		case('d'): case('D'): printf("Delta\n"); return 5; break;
		case('e'): case('E'): printf("Echo\n"); return 4; break;
		case('f'): case('F'): printf("Foxtrot\n"); return 7; break;
		case('g'): case('G'): printf("Golf\n"); return 4; break;
		case('h'): case('H'): printf("Hotel\n"); return 5; break;
		case('i'): case('I'): printf("India\n"); return 5; break;
		case('j'): case('J'): printf("Juliet\n"); return 7; break;
		case('k'): case('K'): printf("Kilo\n"); return 4; break;
		case('l'): case('L'): printf("Lima\n"); return 4; break;
		case('m'): case('M'): printf("Mike\n"); return 4; break;
		case('n'): case('N'): printf("November\n"); return 8; break;
		case('o'): case('O'): printf("Oscar\n"); return 5; break;
		case('p'): case('P'): printf("Papa\n"); return 4; break;
		case('q'): case('Q'): printf("Quebec\n"); return 6; break;
		case('r'): case('R'): printf("Romeo\n"); return 5; break;
		case('s'): case('S'): printf("Sierra\n"); return 6; break;
		case('t'): case('T'): printf("Tango\n"); return 5; break;
		case('u'): case('U'): printf("Uniform\n"); return 7; break;
		case('v'): case('V'): printf("Victor\n"); return 6; break;
		case('w'): case('W'): printf("Whiskey\n"); return 7; break;
		case('x'): case('X'): printf("X ray\n"); return 5; break;
		case('z'): case('Z'): printf("Zulu\n"); return 4; break;
		case('0'): printf("zero\n"); return 4; break;
		case('1'): printf("one\n"); return 3; break;
		case('2'): printf("two\n"); return 3; break;
		case('3'): printf("three\n"); return 5; break;
		case('4'): printf("four\n"); return 4; break;
		case('5'): printf("five\n"); return 4; break;
		case('6'): printf("six\n"); return 3; break;
		case('7'): printf("seven\n"); return 5; break;
		case('8'): printf("eight\n"); return 5; break;
		case('9'): printf("nine\n"); return 4; break; }
	fprintf(stderr, "error print_pilot_word: character out of range\n");
	return UINT_MAX; 	
}
/* print_word
 * given a number, print the corresponding upper-case word
 * must be a recursive function
 * inputs:
 *   unsigned int number - encoding of a word, as described in hw1.html
 * output:
 *   prints out, but does not return, the word encoded in the number.
 */
void print_word(unsigned int number){
	//base case: number <= 26
	if(number <= 26){
		print_letter(number-1);
		return;}
	//smaller case: number is divisible by 27
	else if(number%27 == 0){
		print_word(number/27);	
	} 		
	//general case: subtract the encoding of the last letter and print last letter after the rest 
	else{
		int last_enc = number%27;
		print_word(number - last_enc); 
		print_letter(last_enc-1);		
		}
	return; }
/* print_asterisk_word
 * given a letter, print the corresponding upper-case word in sterisks
 * inputs:
 *   char[] - a character array
 *   unsigned int length - the number of letters in the character array
 * output:
 *   prints out, but does not return, the word in the array
 */

//Given a letter and row number, returns the row of asterisks to print
void print_char_row(char letter, unsigned int row){
	if(letter == 'N'){
		switch(row){
			case(0): printf("*   * "); break;
			case(1): printf("**  * "); break;
			case(2): printf("* * * "); break;
			case(3): printf("*  ** "); break;
			case(4): printf("*   * "); break;
		}
		return;}
	else if(letter == 'O'){
		switch(row){
			case(0):
			case(4): printf(" ***  "); break;
			case(1):
			case(2):
                        case(3): printf("*   * "); break;}
		return;}
        else if(letter == 'P'){
		switch(row){
			case(0):
			case(2): printf("****  "); break;
			case(1): printf("*   * "); break;
			case(3):
			case(4): printf("*     "); break;}
		return;}
	else if(letter == 'R'){
		switch(row){
			case(0):
			case(2): printf("****  "); break;
			case(1): printf("*   * "); break;
			case(3): printf("*  *  "); break;
			case(4): printf("*   * "); break;
	} return;}
	else
		fprintf(stderr, "error print_char_row: not a valid character\n");
	return;}
void print_asterisk_word(char word[], unsigned int length){
	//loops through the 5 rows of asterisks to print out for each letter in array
	for(int i = 0; i < 5; i++)
	{
		//loops through each letter in the array and prints out the appropriate row
		for(int j = 0; j < length; j++){
			print_char_row(word[j], i);}
		printf("\n"); 
	}	
	return;}
/* encode_rotate
 * given a message, length, and rotate factor, encrypt the message.
 * Each letter is rotated by a different amount, depending on its
 * position within the message.
 */
void encode_rotate(char msg[], unsigned int length, unsigned int rot_factor, unsigned int scale_factor){
	if(length < 1){ 
		printf("\n "); 
		return;
		}
	char letter = msg[length-1];
	if(((letter >= 'a') && (letter <= 'z'))||((letter >= 'A') && (letter <= 'Z'))){
		char new_letter = letter + rot_factor + scale_factor*(length-1);
		msg[length-1] = new_letter;
		encode_rotate(msg, length-1, rot_factor, scale_factor);
		printf("%c", new_letter);
	}
	else{
		encode_rotate(msg, length-1, rot_factor, scale_factor); 	
		printf("%c", letter);
		}
	}
