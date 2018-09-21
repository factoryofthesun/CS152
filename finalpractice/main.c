#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loops.h"

int main()
{
	int test1[] = {2, 4, 1, -5, 29, 18, 3};
/*	print_array(test1, 7); 
	bubbleSort(test1, 7);
	printf("after bubble sort\n");  
	print_array(test1, 7); */
	int num = (5<<4) + (5<<2) + (5<<0); 
	printf("%d\n", num); 
	int x = 3; //11
	int y = 9; //1001
	printf("expected: %d\n", 0b100111); 
	int comb = x; 
	comb = comb | ((y&15)<<2); 
	printf("result: %d\n", comb); 
}
