#include <stdio.h>
#include <stdlib.h>
#include "loops.h"

void print_array(int arr[], int length)
{
	for(int i = 0; i < length; i++)
		printf("%d\n", arr[i]); 
}

void swap(int arr[], int i1, int i2)
{
	int tmp = arr[i1]; 
	arr[i1] = arr[i2]; 
	arr[i2] = tmp; 
}

void bubbleSort(int arr[], int length)
{
	for(int i = 1; i < length; i++)
	{
		for(int j = 0; j < length -i; j++)
		{
			if(arr[j] > arr[j+1])
				swap(arr, j, j+1); 
		}
	}
}

int partition(int arr[], int low, int high);

void quickSort(int arr[], int low, int high);
