#ifndef HW2_H
#define HW2_H

#include <stdio.h>
#include <stdlib.h>

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
int print_pilot_word(char letter);

/* print_word
 * given a number, print the corresponding upper-case word
 * must be a recursive function
 * inputs:
 *   unsigned int number - encoding of a word, as described in hw1.html
 * output:
 *   prints out, but does not return, the word encoded in the number.
 */
void print_word(unsigned int number);

/* print_asterisk_word
 * given a letter, print the corresponding upper-case word in sterisks
 * inputs:
 *   char[] - a character array
 *   unsigned int length - the number of letters in the character array
 * output:
 *   prints out, but does not return, the word in the array
 */
void print_asterisk_word(char word[], unsigned int length);

/* encode_rotate
 * given a message, length, and rotate factor, encrypt the message.
 * Each letter is rotated by a different amount, depending on its
 * position within the message.
 */
void encode_rotate(char msg[], unsigned int length, unsigned int rot_factor, unsigned int scale_factor);

#endif
