#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warmup4.h"
#include "warmup4_provided.h"



int main(int argc, char *argv[] )
{
	if(*argv[1] == '0')
	{
		int expected = 0;
		for (int i = 3; i < argc; i++)
		{	 
			expected+= count_vowels(argv[i]);		
		}
		int check = atoi(argv[2]);
		if(expected == check)
		{
			printf("%s - PASSED\n", argv[2]);
			return 1;
		}
		else
		{
			printf("%s - FAILED\n", argv[2]); 
			return 0;
		} 
	}
	else if(*argv[1] == '1')
	{
		for (int i = 2; i < argc; i++)
                {
			make_lowercase(argv[i]);	
			printf(" ");                         
                }
		printf("\n");
	}
	else if(*argv[1] == '2')
	{
		int height = atoi(argv[2]);
		int width = atoi(argv[3]); 
		pixel color; 
		color.red = atoi(argv[4]);
		color.green = atoi(argv[5]);
		color.blue = atoi(argv[6]); 
		pixel **result = make_and_init_image(height, width, color); 
		char *filename = argv[7];
		return provided_write_png_struct(filename, result, width, height); 
	}
		
}
