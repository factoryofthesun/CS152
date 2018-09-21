#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "practice.h"
#include <string.h>

int main()
{
	double arr1[] = {-5.3, 2.1, 4, 12000, 38, 14};
	int length1 = 6;
	double arr2[] = {-1, -1, -1, -1, -1.1};
	int length2 = 5; 
	double m = -1; 

	double min = min_n(arr1, length1);
	printf("min_n: %f\n", min);
	int count = count_less(m, arr2, length2);
	printf("count_less: %d\n", count); 
	int index = index_m_recur(m, arr2, length2); 
	printf("index_m_recur: %d\n", index); 
	
	//pointer shit
	char characters[] = {'a','b','c','d','z'};
	char *arr;
	arr = characters;
	printf("%c\n", *arr); 
	int loc[100]; 
	int *new = (int*) malloc(sizeof(int)*100);
	*new = 1;
	*(++new) = 5; 
	printf("%d\n", *new);
	
	char *fat = "fat";
	char *skinny = "skinnboi";
	swap(&fat, &skinny);
	printf("char fat: %s, char skinny: %s\n", fat, skinny);
	
	char myString[20]; 
	strcpy(myString, "supdood"); 
	printf("%s\n", myString);
	strcpy(myString+7, "more"); 
	printf("%s\n", myString);
	strcat(myString, "evenmore"); 
	printf("%s\n", myString);
}	
