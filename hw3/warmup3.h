#ifndef WARMUP3_H
#define WARMUP3_H

#define ROWS 50
#define COLS 50

/* remove_max
 * inputs: 
 *  int array[] - an array of ints
 *  int length - the number of items in the array
 *  receives an array of the specified length. 
 *  The function is supposed to find the maximum item,
 *  remove it from the array, and return that value.
 */
int remove_max(int array[], unsigned int length);

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
 * outputs:
 *   int - return 0 if failed (width or height out of range), 1 if success
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
	unsigned int height);

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
 * outputs:
 *   int - return 0 if failed (width or height out of range), 1 if success
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
        unsigned int height);

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
                        double *area, double *perimeter);

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
int remove_max_in_out(int *array, unsigned int *length);

#endif
