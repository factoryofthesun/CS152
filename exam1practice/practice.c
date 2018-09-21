#include <stdio.h>
#include <stdlib.h>
#include "practice.h"
#include <string.h>

double min_n(double array[], int length)
{
	if(length == 0)
		return 0;
	double min = array[0]; 
	for(int i = 1; i<length; i++)
	{
		if(min > array[i])
		{ min = array[i];}
	}
	return min;
}
int count_less(double m, double array[], int length)
{
	if(length == 0)
		return 0; 
	int count = 0; 
	for(int i = 0; i < length; i++)
	{
		if(array[i] < m)
			count++; 
	}
	return count; 
}
int index_m_recur(double m, double array[], int length)
{
	if(length == 0)
		return -1;
	int index; 
	index = index_m_recur(m, array, length-1);
	if(index != -1)
		return index;
	else if(array[length-1] == m)
		return length-1; 
	return index; 
}

void swap(char **a, char **b)
{
	char *temp= NULL;
	temp = *b; 
	*b = *a;
	*a = temp;
}
