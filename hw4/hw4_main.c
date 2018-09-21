#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw4.h"
#include "hw4_provided.h"

int main(int argc, char *argv[])
{
	//get input variables
	char *filename = argv[1];
	int function_num = atoi(argv[2]);
	float expected = atof(argv[3]);
	float height = atof(argv[4]);
	//Which function to call and checks if expected value aligns with actual 
	climb c = provided_read_climb(filename);
	float rate;
	switch(function_num){
		case(0): rate = rating_hold_distances(c, height);
			if(rate != expected)
			{
				printf("%s, rating_hold_distances - FAILURE\n expected: %f, result: %f\n", filename, expected, rate);
				return 0;	
			}
			else 
				printf("%s, rating_hold_distances - SUCCESS\n", filename); 
				return 1;
			break;
		case(1): rate = rating_hold_shapes(c);
                        if(rate != expected)
                        {
                                printf("%s, rating_hold_shapes - FAILURE\n expected: %f, result: %f\n", filename, expected, rate);
                                return 0;
                        }
                        else
                                printf("%s, rating_hold_shapes - SUCCESS\n", filename);
                                return 1;
                        break;		
		case(2): rate = rating_rock_angle(c);
                        if(rate != expected)
                        {
                                printf("%s, rating_rock_angle - FAILURE\n expected: %f, result: %f\n", filename, expected, rate);
                                return 0;
                        }
                        else
                                printf("%s, rating_rock_angle - SUCCESS\n", filename);
                                return 1;
                        break;
		case(3): rate = overall_rating(c, height);
                        if(rate != expected)
                        {
                                printf("%s, overall_rating - FAILURE\n expected: %f, result: %f\n", filename, expected, rate);
                                return 0;
                        }
                        else
                                printf("%s, overall_rating- SUCCESS\n", filename);
                                return 1;
                        break;
		default: fprintf(stderr, "Not a valid function number!\n"); 
	}
}
