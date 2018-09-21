#ifndef HW4_H
#define HW4_H
#include <stdio.h>
#include <stdlib.h>
#include "hw4_provided.h"

/* float rating_hold_distance
inputs: climb, climber height
output: rating 
Rates a climb based on hold distances adjusting for climber's height
*/
float rating_hold_distances(climb c, float climber_height);

/* float rating_hold_shapes
inputs: climb
output: rating
assigns a rating based on the hold shape 
*/
float rating_hold_shapes(climb c);

/*float rating_rock_angle
input: climb
output: rating
calculates rating based on rock angle 
*/
float rating_rock_angle(climb c);

/*float overall_rating
input: climb, climber height
output: rating
returns the maximum value of the other three functions
*/
float overall_rating(climb c, float climber_height);


#endif 
