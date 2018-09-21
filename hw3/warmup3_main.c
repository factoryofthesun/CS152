#include <stdio.h>
#include <stdlib.h>
#include "hw3_provided.h"
#include "warmup3.h"
#include "hw1.h"
unsigned int check_remove_max(int array[], unsigned int length, 
                                        int expected_result)
{
        int dresult = remove_max(array, length);
        if (dresult == expected_result)
        {
                return 1;
        }
        else
        {
                printf("Unexpected result. print_letter(%p, %u)\n",
                        array, length);
                printf("returned %d, expected %d \n",dresult, expected_result);
                return 0;
        }
}

unsigned int check_area_and_perimeter(unsigned int num_sides, double side_length,
                                       double *area, double *perimeter, int expected_result)
{
        int dresult = area_and_perimeter(num_sides, side_length, area, perimeter);
        if (dresult == expected_result)
        {
                return 1;
        }
        else
        {
                printf("Unexpected result. area_and_perimeter(%u, %f, %f, %f)\n",
                        num_sides, side_length, *area, *perimeter);
                printf("returned %d, expected %d \n",dresult, expected_result);
                return 0;
        }
}

unsigned int check_make_horizontal_stripes(unsigned int red[ROWS][COLS], unsigned int green[ROWS][COLS],
					unsigned int blue[ROWS][COLS], unsigned int stripe_height, 
					unsigned int stripe_red, unsigned int stripe_green, 
 					 unsigned int stripe_blue, unsigned int width, unsigned int height,
                                        int expected_result)
{
        int dresult = make_horizontal_stripes(red, green, blue, stripe_height, stripe_red, stripe_green,
						stripe_blue, width, height);
        if (dresult == expected_result)
        {
                return 1;
        }
        else
        {
                printf("Unexpected result. make_horizontal_stripes(%u, %u, %u, %u, %u, %u)\n",
                        stripe_height, stripe_red, stripe_green, stripe_blue,width,height);
                printf("returned %d, expected %d \n",dresult, expected_result);
                return 0;
        }
}

unsigned int check_make_checker_board(unsigned int red[ROWS][COLS], unsigned int green[ROWS][COLS],
                                        unsigned int blue[ROWS][COLS], unsigned int square_width,
                                        unsigned int square_red, unsigned int square_green,
                                         unsigned int square_blue, unsigned int width, unsigned int height,
                                        int expected_result)
{
        int dresult = make_checker_board(red, green, blue, square_width, square_red, square_green,
                                                square_blue, width, height);
        if (dresult == expected_result)
        {
                return 1;
        }
        else
        {
                printf("Unexpected result. make_checker_board(%u, %u, %u, %u, %u, %u)\n",
                        square_width, square_red, square_green, square_blue,width,height);
                printf("returned %d, expected %d \n",dresult, expected_result);
                return 0;
        }
}
int main()
{
	// declare variables
	unsigned int r[ROWS][COLS];
        unsigned int g[ROWS][COLS];
        unsigned int b[ROWS][COLS];
        unsigned int width;
        unsigned int length;
	double area; 
	double perimeter; 
	int arr1[] = {1, 2, 3, 5, 4};
	int arr2[] = {1, 8, 8, 2, 3, 5, 6, 7}; 
	// read in ppm file
	provided_read_png("sample.png",r,g,b,&width,&length);

	// print to html
	provided_print_image_to_html("sample.html",r,g,b,width,length);

	//tests
	int num_tests = 15; 
	int num_correct = 0;
	num_correct += check_make_horizontal_stripes(r, g, b, 1, 30, 144, 255, 12, 12, 1);
	num_correct += check_make_horizontal_stripes(r,g,b,0,30, 144, 255, 12, 12, 1); 
	num_correct += check_make_horizontal_stripes(r,g,b, 3, 30, 144, 255, 12, 12,1); 
	num_correct += check_make_horizontal_stripes(r,g,b, 2, 260, 144, 255, 12, 12, 0); 
	num_correct += check_make_horizontal_stripes(r,g,b, 2, 30, 144, 255, 100, 12, 0);
 
	num_correct += check_make_checker_board(r, g, b,4,30,144,255, 12, 12, 1);
        num_correct += check_make_checker_board(r,g,b,0,30, 144, 255, 12, 12, 1);
        num_correct += check_make_checker_board(r,g,b, 3, 30, 144, 255, 12, 12,1);
        num_correct += check_make_checker_board(r,g,b, 2, 260, 144, 255, 12, 12, 0);
        num_correct += check_make_checker_board(r,g,b, 2, 30, 144, 255, 100, 12, 0);

	num_correct += check_area_and_perimeter(4, 4, &area, &perimeter, 0); 
	num_correct += check_area_and_perimeter(0, 4, &area, &perimeter, -1); 
	num_correct += check_area_and_perimeter(4, -2, &area, &perimeter, -1);
	printf("area: %lf, perimeter: %lf \n", area, perimeter); 

	num_correct += check_remove_max(arr1, 5, 5); 
	num_correct += check_remove_max(arr2, 8, 8); 
	printf("Number of tests: %d \n Number correct: %d\n", num_tests, num_correct); 
}


