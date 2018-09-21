#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/* print_stuff: prints several variables of different types
 * purpose is to illustrate printf and the types C provides 
 * void means it doesn't return a value - it does something instead
 * inputs:
 *    int ival - integer value that will be printed out as an integer
 *    float fval - floating-point value that will be printed out as a float
 *    double dval - more precise fp value that will be printed as a long float
 *    char cval - char value that will be printed out as a character
 */
void print_stuff(int ival, float fval, double dval, char cval)
{
	printf("Integer: %d\n",ival);
	printf("Float: %f\n",fval);
	printf("Double is a more precise float: %lf\n",dval);
	printf("Char is a letter %c\n",cval);
        printf("You can also control how a float is printed out: %3.2f\n",
		62.937491287);
}

/* do_some_math: purpose is to do math and show the outcomes for 
 * various operations that illustrate how C works
 * inputs:
 * 	int ival - integer value for performing random operations
 * 	float fval - float value for performing random operations
 * 	char cval - character showing character arithmetic
 */
void do_some_math(int ival, float fval, char cval)
{
	printf("%d + 5 = %d\n",ival,ival+5);
	printf("%c + 5 = %c\n",cval,cval+5);
	printf("%d %% 5 = %d\n",ival,ival%5);
	printf("%c %% 5 = %c! Not useful!\n",cval,cval%5);
	ival = 3;
	fval = 3.0;
	printf("%d / 5 = %d! Be careful!\n",ival,ival/5);
	printf("%f / 5 = %f. They work differently!\n",fval,fval/5);
	printf("%d / 5.0 = %f! Now it works!\n",ival,ival/5.0);
}

/* return_a_value: purpose is to show how to declare values,
 * calculate a result, and return that result to the caller 
 * inputs:
 * 	int ival - integer value we will multiply by 5
 * outputs:
 *      int result - the original input multiplied by 5
 */
int return_a_value(int ival)
{
	int result = ival*5;
	return result;
}

/* fact : compute factorial of given number 
 * This illustrates how to write recursive code in C 
 * inputs:
 * 	unsigned int - we will calculate n!
 * outputs:
 * 	unsigned long int - n!
 */
unsigned long int fact(unsigned int n)
{
  // base case
  if (n==0) 
  {
    return 1;
  } 
  else 
  {
    // call the recursive case
    int smaller_result = fact(n-1);
    // modify the result from recursive case and return our result
    return n * smaller_result;
  }
}


