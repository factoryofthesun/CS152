#include <stdio.h>
#include <stdlib.h>
#include "warmup3.h"
#include "hw3_provided.h"
#include "hw1.h"
/* remove_max
 * inputs: 
 *  int array[] - an array of ints
 *  int length - the number of items in the array
 *  receives an array of the specified length. 
 *  The function is supposed to find the maximum item,
 *  remove it from the array, and return that value.
 */
int remove_max(int array[], unsigned int length)
{
	return remove_max_in_out(array, &length);
}

/* make_horizontal_stripes
 * inputs: 
 *   unsigned int red[ROWS][COLS],  - red component of resulting image pixels
 *   unsigned int green[ROWS][COLS], - green component of resulting image pixels
 *   unsigned int blue[ROWS][COLS],  - blue component of resulting image pixels
 *   unsigned int stripe_height,  - height of a single stripe
 *   unsigned int stripe_red,  - red component of stripe pixel
 *   unsigned int stripe_green,  - green component of stripe pixel
 *   unsigned int stripe_blue,  - blue component of stripe pixel
 *   unsigned int width,  - width of resulting image
 *   unsigned int height); - height of resulting image
 * 
 *   This produces an image stored in the red, green, and blue 2-d arrays.
 *   The image contains black and colored stripes. All stripes are 
 *   stripe_height. The stripe colors are indicated by stripe_color.
 *   The top stripe is colored. The image is heightxwidth.
 */
int make_horizontal_stripes( 
	unsigned int red[ROWS][COLS], 
	unsigned int green[ROWS][COLS], 
	unsigned int blue[ROWS][COLS], 
	unsigned int stripe_height, 
	unsigned int stripe_red, 
	unsigned int stripe_green, 
	unsigned int stripe_blue, 
	unsigned int width, 
	unsigned int height)
{
	if((width>COLS) || (height>ROWS))
	{
		fprintf(stderr, "error make_horizontal_stripes: image size too large\n"); 
		return 0;
	}
	if((stripe_red > 255)||(stripe_blue > 255)|| (stripe_green > 255))
	{
		fprintf(stderr, "error make_horizontal_stripes: invalid rgb values\n"); 
		return 0; 
	} 
	if (stripe_height == 0)
	{
		//use nested for loops to loop through every column then every row to fill out with zeroes
		for(int i = 0; i < height; i++)
		{
			for(int j = 0; j < width; j++)
			{	
				red[i][j] = 0; 
				green[i][j] = 0;
				blue[i][j] = 0;
			}
		}
		return 1; 
	}
	//otherwise, use integer division and mod2 to alternate loops between colored and black stripes
	for(int k = 0; k < height; k++)
	{	
		int stripe_num = k/stripe_height;
		//colored stripe
		if(stripe_num%2==0)
		{
			//loop through every column in the row k
			for(int c1 = 0; c1 < width; c1++)
			{	
				red[k][c1] = stripe_red; 
				green[k][c1] = stripe_green;
				blue[k][c1] = stripe_blue;
			}
		}
		//black stripe
		else
		{
			//loop through every column in row k
			for(int c2 = 0; c2 < width; c2++)
			{
				red[k][c2] = 0; 
				green[k][c2] = 0; 
				blue[k][c2] = 0;
			}
		}
	}
	
	provided_print_image_to_html("stripes.html", red, green, blue, width, height); 	
	return 1; 
}

/* make_checker_board
 * inputs: 
 *   unsigned int red[ROWS][COLS],  - red component of resulting image pixels
 *   unsigned int green[ROWS][COLS], - green component of resulting image pixels
 *   unsigned int blue[ROWS][COLS],  - blue component of resulting image pixels
 *   unsigned int square_height,  - height of a single square
 *   unsigned int square_red,  - red component of square pixel
 *   unsigned int square_green,  - green component of square pixel
 *   unsigned int square_blue,  - blue component of square pixel
 *   unsigned int width,  - width of resulting image
 *   unsigned int height); - height of resulting image
 * 
 *   This produces an image stored in the red, green, and blue 2-d arrays.
 *   The image contains white and colored squares. All squares are 
 *   square_width x square_width. The square colors are indicated by 
 *   square_color. The image is heightxwidth. The top-left square is colored.
 */
int make_checker_board( 
        unsigned int red[ROWS][COLS],
        unsigned int green[ROWS][COLS],
        unsigned int blue[ROWS][COLS],
        unsigned int square_width,
        unsigned int square_red,
        unsigned int square_green,
        unsigned int square_blue,
        unsigned int width,
        unsigned int height)
{
	if((width > COLS)||(height > ROWS))
	{
		fprintf(stderr, "error make_checker_board: dimensions out of bounds\n");
		return 0;  
	}
	else if((square_red > 255) || (square_green > 255) || (square_blue > 255))
	{
		fprintf(stderr, "error make_checker_board: invalid rgb codes\n");
		return 0; 
	}
	else if(square_width == 0)
	{
		//fill entire picture white 
		int i; int j; 
		for(i = 0; i < width; i++)
		{
			for(j= 0; j < height; j++)
			{
				red[j][i] = 255; 
				green[j][i] = 255; 
				red[j][i] = 255; 
			}
		}
		return 1;
	}
	//alternate colored and white squares\
	//outer loop iterates through rows 
	for(int r = 0; r < height; r++)
	{
		int row_num = r/square_width; //gets the row num starting from 0  
		if(row_num%2 == 0)
		{
			//loop through each column, checking for square width
			for(int c = 0; c < width; c++)
			{
				int col_num = c/square_width; 
				if(col_num%2 == 0)
				{
					red[r][c] = square_red; 
					green[r][c] = square_green;
					blue[r][c] = square_blue; 
				}
				else
				{
					red[r][c] = 255; 
					green[r][c] = 255; 
					blue[r][c] = 255; 
				}
			}
		}
		else
		{
			//loop through each column, checking for square width
                        for(int c = 0; c < width; c++)
                        {
                                int col_num = c/square_width;
                                if(col_num%2 == 1)
                                {
                                        red[r][c] = square_red;
                                        green[r][c] = square_green;
                                        blue[r][c] = square_blue;
                                }
                                else
                                {
                                        red[r][c] = 255;
                                        green[r][c] = 255;
                                        blue[r][c] = 255;
                                }
                        }

		}
	}
	provided_print_image_to_html("checkerboard.html", red, green, blue, width, height);
	return 1;
}

/* int area_and_perimeter
 * input:
 *   unsigned int num_sides - number of sides of polygon
 *   double side_length - length of each side
 * output:
 *   double *area - the area of the polygon
 *   double *perimeter - the length of the perimeter of the polygon
 *   int - return 0 for success, -1 for failure
 */
int area_and_perimeter(unsigned int num_sides, double side_length, 
			double *area, double *perimeter)
{
	if((num_sides < 1) || (side_length <= 0))
	{
		fprintf(stderr, "error area_and_perimeter: invalid side length/number\n");
		return -1; 
	}
	double area_result = sides_to_area(num_sides, side_length); 
	*area = area_result;
	double perim = num_sides * side_length; 
	*perimeter = perim; 
	return 0; 
}

/* int remove_max_in_out
 * input:
 *   int *array, - array  
 *   int *length - length of array
 * output:
 *   int *array, - modified array, now without max value
 *   int *length - length of new array (one less than before)
 *  receives an array of the specified length. 
 *  The function is supposed to find the maximum item,
 *  remove it from the array, decrement length, and return that value.
 */
int remove_max_in_out(int *array, unsigned int *length)
{
	int max = array[0];
	int max_index = 0;
	//loops through whole array to find the max value and index
	for(int i = 0; i < *length; i++)
	{
		if(max < array[i])
		{
			max = array[i];
			max_index = i;
		}
	}
	//loops starting from max_index and replaces the value with the one one index in front
	int dim_length = *length - 1;
	for(int j = max_index; j < dim_length; j++){
		array[j] = array[j+1];
	}
	*length = dim_length;
	return max;
}

