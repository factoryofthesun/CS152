#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "hw1.h"

/* surface_area_tetrahedron
 * calculate the surface area of a tetrahedron. 
 * inputs: 
 *   double edge_length - length of one edge of shape
 * output:
 *   double - the total surface area
 */
double surface_area_tetrahedron(double edge_length)
{
	if(edge_length <= 0){
		 fprintf(stderr, "error surface_area_tetrahedron: invalid edge length\n");
		return -1.0;}
	double surf_area;
	surf_area = sqrt(3)*pow(edge_length,2);
	fprintf(stdout,"The surface area of a regular tetrahedron with edge length %lf is %lf.\n"
	, edge_length, surf_area);
	return surf_area;
}

/* sides_to_area
 * calculate the area of a polygon with equal-length sides
 * inputs:
 *   int num_sides - number of sides of the polygon
 *   double side_length - length of each side of the polygon
 * output:
 *   double - the area of a num-side polygon with given side_length
 */
double sides_to_area(int num_sides, double side_length)
{//function is 1/2*base*height*num_sides
	if(side_length <= 0){
                 fprintf(stderr, "error sides_to_area: invalid edge length\n");
                return -1.0;}
	if(num_sides < 1){
		fprintf(stderr, "error sides_to_area: invalid side number\n");
		return -1.0;}
	double area;
	double radian = 2*M_PI/(2*num_sides);
	double height = cos(radian)/sin(radian)*side_length/2;
	area = .5*height*side_length*num_sides;
	fprintf(stdout,"A regular %d-gon with side length %lf has area %lf\n", num_sides, side_length, area);
	return area;
}


/* fall_ground_distance
 * calculate the distance you'll be from the ground if you fall
 * during rock climbing at this point
 * inputs:
 *   double current_height (h1) - height that your harness is off the ground
 *   double harness_loop_height (h2) - the distance from your feet to your 
 *      harness loop (which is tied in) at tension
 *   double clip_distance (h3) - distance your harness loop is from the 
 *      rest position of your last quickdraw
 * output:
 *   double - height your feet will be from the ground if you fall
 */
double fall_ground_distance(double current_height, 
		double harness_loop_height, double clip_distance)
{
	if((current_height <0)||(harness_loop_height < 0)||(clip_distance <0)){
		fprintf(stderr, "error fall_ground_distance: negative inputs are not allowed\n");
		return INT_MIN;}
	else if((current_height <clip_distance) || (current_height< harness_loop_height)){
		fprintf(stderr, "error fall_ground_distance: current_height too low\n");
		return INT_MIN;}
	else if(current_height < (2*clip_distance + harness_loop_height)){
		printf("After falling, your feet wil be 0 feet above the ground.\n");
		return 0.0;
		}
	double quickdraw = current_height - clip_distance;
	double fall_height = quickdraw - clip_distance - harness_loop_height;
	fprintf(stdout,"After falling, your feet will be %lf feet above the ground.\n", fall_height);
	return fall_height;
}

/* halving
 * calculate how many times a child needs to go halfway towards
 * you before the remaining distance is less than or equal to an inch, 
 * which we will consider too small to halve.
 * inputs:
 *   float dist - the distance, expressed in inches, that the child starts 
 *   	from you
 * output:
 *   unsigned int - the number of iterations, in which each iteration
 *    	gets the child closer to you.
 */
unsigned int number_halves(float dist)
{
	if(dist <= 1){
		return 0;}
	float half_dist = dist/2;
	unsigned int iters = 1 + number_halves(half_dist);
	return iters;
}

/* golden_spiral
 * calculate the length of the square added on the xth application of
 * the spiral formed by starting with an axb rectangle.
 * inputs:
 *   float a - length of first rectangle
 *   float b - width of first rectangle
 *   unsigned int applications - number of added square to calculate
 *      length of
 */
float golden_spiral(float a, float b, int applications)
{
	if(applications==0){
		return a;}
	else if(applications==1){
		return a+b;}
	float length = golden_spiral(a, b, applications-1) + golden_spiral(a,b,applications-2);
	return length;
}


