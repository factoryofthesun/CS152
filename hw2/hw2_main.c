#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw2.h"  // see how we're including the file again?

// remember to create a test function for each function you 
// are implementing. This test function will call the function
// and compare the result to the expected result.
unsigned int check_print_pilot_word(char letter,
                                        int expected_result)
{
        int dresult = print_pilot_word(letter);
        if (dresult == expected_result)
        {
                return 1;
        }
        else
        {
                printf("Unexpected result. print_pilot_word(%c)\n",
                        letter);
                printf("returned %d, expected %d \n",dresult, expected_result);
                return 0;
        }
}

int main()
{
	char word_ill[] = {'N','O','R'};
	char word_p[] = {'P'};
	char message[] = {'h','e','l','l','o',',',' ','h','o','w',' ',
		'a','r','e',' ','y','o','u','?'};
	char message2[30];
	char message3[] = {'a', 'b', 'c', 'd'};
	
	int num_tests = 4; 
	// here is another way you can get a word into a string!
	// we will learn it fully later - it's here to make your life easier
	strcpy(message2,"Howdy there!");

	// I am only putting one line in for each to make sure it compiles
	// you need to write your own test code
	int num_correct = check_print_pilot_word('A', 5); 
	num_correct += check_print_pilot_word("10", UINT_MAX);
	num_correct += check_print_pilot_word('.', UINT_MAX); 
	num_correct += check_print_pilot_word('Z', 4); 
	print_word(384);
	print_word(4359030); //should print out 'hello'
	print_word(27); //should print out 'A'
	print_asterisk_word(word_ill, 3);
	print_asterisk_word(word_p, 1); //should print out asterisk P
	print_asterisk_word(word_ill, 2); //should return NO
	encode_rotate(message,19,2,1);
	encode_rotate(message2,12,1,3);
	encode_rotate(message3, 4, 1, 0); //should print out bcde
	printf("Number of tests run: %d\n", num_tests); 
	printf("Number correct: %d\n", num_correct); 
}

