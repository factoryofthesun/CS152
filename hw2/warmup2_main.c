#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warmup2.h"  // see how we're including the file again?


/* Principle 2: Design a good set of test cases
 * they check the base case (0), right above the base case (1), well
 * above the base case (5, 8), and error conditions (-1, -5).
 * -1, 0, 1 are the boundary test cases - base, base+1, base-1.
 */
unsigned int check_print_letter(unsigned int num,
                                        char expected_result)
{
        char dresult = print_letter(num);
        if (dresult == expected_result)
        {
                return 1;
        }
        else
        {
                printf("Unexpected result. print_letter(%u)\n",
                        num);
                printf("returned %c, expected %c \n",dresult, expected_result);
                return 0;
        }
}

int main()
{
	char cval;
	double dval;
	unsigned int uival;
	char word_ill[] = {'I','L','L'};
	char message[] = {'h','e','l','l','o',',',' ','h','o','w',' ',
		'a','r','e',' ','y','o','u','?'};
	char message2[30];
	
	
	// here is another way you can get a word into a string!
	// we will learn it fully later - it's here to make your life easier
	strcpy(message2,"Howdy there!");

	// I am only putting one line in for each to make sure it compiles
	// you need to write your own test code
	int num_checks = 3;
	int num_correct = 0;
	num_correct += check_print_letter(1, 'B');
	num_correct += check_print_letter(27, ' ');
	num_correct += check_print_letter(25, 'Z'); 
	print_asterisk_letter('N');
	draw_sideways_wedge_rec(3, 10);
	draw_sideways_wedge_iter(3, 10);
	printf("Number of tests: %d \n Number correct: %d \n", num_checks, num_correct);
}

