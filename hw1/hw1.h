#ifndef HW1_H
#define HW1_H

// these should not be strictly necessary, since anyone
// including this file should include these first. But
// just to be safe...
#include <stdio.h>
#include <stdlib.h>

/* surface_area_tetrahedron
 * calculate the surface area of a tetrahedron. 
 * inputs: 
 *   double edge_length - length of one edge of shape
 * output:
 *   double - the total surface area
 */
double surface_area_tetrahedron(double edge_length);

/* sides_to_area
 * calculate the area of a polygon with equal-length sides
 * inputs:
 *   int num_sides - number of sides of the polygon
 *   double side_length - length of each side of the polygon
 * output:
 *   double - the area of a num-side polygon with given side_length
 */
double sides_to_area(int num_sides, double side_length);

/* fall_ground_distance
 * calculate the distance you'll be from the ground if you fall
 * during rock climbing at this point. 
 * inputs:
 *   double current_height (h1) - height that your harness is off the ground
 *   double harness_loop_height (h2) - the distance from your feet to your 
 *      harness loop (which is tied in) at tension
 *   double clip_distance (h3) - distance your harness loop is from the 
 *      rest position of your last quickdraw
 * output:
 *   double - height your feet will be from the ground if you fall
 */
double fall_ground_distance(double current_height, double harness_loop_height, double clip_distance);

/* halving
 * calculate how many times a child needs to go halfway towards
 * you before the remaining distance is less than or equal to an inch, 
 * which we will consider too small to halve.
 * inputs:
 *   float dist - the distance, expressed in inches, that the child starts 
 *      from you
 * output:
 *   unsigned int - the number of iterations, in which each iteration
 *      gets the child closer to you.
 */
unsigned int number_halves(float dist);


/* golden_spiral
 * calculate the length of the square added on the xth application of
 * the spiral formed by starting with an axb rectangle.
 * inputs:
 *   float a - length of first rectangle
 *   float b - width of first rectangle
 *   unsigned int applications - number of added square to calculate
 *      length of
 */
float golden_spiral(float a, float b, int applications);


#endif

