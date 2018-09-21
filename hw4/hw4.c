#include <stdio.h>
#include <stdlib.h>
#include "hw4.h"
#include "hw4_provided.h"
#include <math.h>
/* float rating_hold_distance
inputs: climb, climber height
output: rating
Rates a climb based on hold distances adjusting for climber's height
*/
float rating_hold_distances(climb c, float climber_height)
{
	//take the relevant variables
	int num_right = c.num_right_holds;
	int num_left = c.num_left_holds; 
 	climbing_hold *rarr = c.right_holds; 
	climbing_hold *larr = c.left_holds; 
	//Check if null
	if((rarr == NULL) || (larr == NULL))
	{	fprintf(stderr, "error: rating_hold_distances, an input is null");
		return 0;
	}
	//loop through all of the right holds and check distances 
	float max = 0;
	climbing_hold below;
	climbing_hold above;
	for(int i = 0; i < num_right-1; i++)
	{
		below = rarr[i]; 
		above = rarr[i+1]; 
		float distance = sqrt(pow(above.xcoor - below.xcoor,2) + pow(above.ycoor - below.ycoor, 2) + pow(above.zcoor - below.zcoor, 2)); 
		if (distance > max)
		{
			max = distance;
		}  
	}
	//do the same for left holds; compare against max of right holds
        for(int i = 0; i < num_left-1; i++)
        {
                below = larr[i];
                above = larr[i+1];
                float distance = sqrt(pow(above.xcoor - below.xcoor,2) + pow(above.ycoor - below.ycoor, 2) + pow(above.zcoor - below.zcoor, 2));
                if (distance > max)
                {
                        max = distance;
                }
        }
	//calculate ratio and return the ratings
	float ratio = climber_height/max; 
	if(ratio >= 4) 
		return 5.06; 
	else if(ratio >= 3)
		return 5.07;
	else if(ratio >= 2.7)
		return 5.08; 
	else if(ratio >=2.4)
		return 5.09; 
	else if(ratio >= 2)
		return 5.10; 
	else if(ratio >= 1.75)
		return 5.101;
	else if(ratio >= 1.5)
		return 5.102;
	else if(ratio >= 1.25)
		return 5.103;
	else 
		return 5.11; 
	
}

/* float rating_hold_shapes
inputs: climb
output: rating
assigns a rating based on the hold shape
*/
float rating_hold_shapes(climb c)
{
	//take the relevant variables
        int num_right = c.num_right_holds;
        int num_left = c.num_left_holds;
        climbing_hold *rarr = c.right_holds;
        climbing_hold *larr = c.left_holds;
	if((rarr == NULL) || (larr == NULL))
        {       fprintf(stderr, "error: rating_hold_distances, an input is null");
                return 0;
        }
	//loop through both left and right holds and take the min hold shape 
	int min = 20; 
	climbing_hold temp;
	for(int i = 0; i < num_right; i++)
	{
		temp = rarr[i]; 
		if(temp.hold_shape < min)
			min = temp.hold_shape;	 
	}
	for(int j = 0; j < num_left; j++)
	{
		temp = larr[j]; 
		if(temp.hold_shape < min)
			min = temp.hold_shape; 
	}
	
	//convert min hold shape into rating
	switch(min){
		case(20): return 5.06; break;
		case(19): return 5.07; break;
		case(18):
		case(17): return 5.08; break;
		case(16):
		case(15): return 5.09; break;
		case(14):
		case(13): return 5.10; break;
		case(12):
		case(11):
		case(10): return 5.101; break;
		case(9):
		case(8): return 5.102; break;
		case(7):
		case(6):
		case(5): return 5.103; break;
		default: return 5.11; break;	
		}
}

/*float rating_rock_angle
input: climb
output: rating
calculates rating based on rock angle
*/
float rating_rock_angle(climb c)
{
	//take the relevant variables
        int num_right = c.num_right_holds;
        int num_left = c.num_left_holds;
        climbing_hold *rarr = c.right_holds;
        climbing_hold *larr = c.left_holds;

	if((rarr == NULL) || (larr == NULL))
        {       fprintf(stderr, "error: rating_hold_distances, an input is null");
                return 0;
        }
	//loop through the right holds and calculate the max angle
	float max_angle = 0;
	climbing_hold below,above;	
	for(int i = 0; i < num_right-1; i++)
	{
		below = rarr[i];
		above = rarr[i+1];
		int z_diff = abs((int) (above.zcoor - below.zcoor));
		int y_diff = above.ycoor - below.ycoor;
		if(y_diff == 0)
                        max_angle = 100;
                else
		{
                         float ratio = (float)z_diff/y_diff;
                         if(ratio > max_angle)
                                 max_angle = ratio;
		}
	}
	//do the same for the left holds
        for(int i = 0; i < num_left-1; i++)
        {
                below = larr[i];
                above = larr[i+1];
                int z_diff = abs((int) (above.zcoor - below.zcoor));
                int y_diff = above.ycoor - below.ycoor;
		if(y_diff == 0)
			max_angle = 100; 
		else
               	{	 float ratio = (float)z_diff/y_diff;
               		 if(ratio > max_angle)
                       		 max_angle = ratio;
		}
        }
	
	if(max_angle ==0)
		return 5.06;
	else if(max_angle <= .25)
		return 5.08;
	else if(max_angle <= .6)
		return 5.09;
	else if(max_angle <= 1)
		return 5.10;
	else if(max_angle <= 1.5)
		return 5.101;
	else if(max_angle <= 4)
		return 5.102;
	else if(max_angle <= 10)
		return 5.103;
	else
		return 5.11;
}

/*float overall_rating
input: climb, climber height
output: rating
returns the maximum value of the other three functions
*/
float overall_rating(climb c, float climber_height)
{
	float rating_hold = rating_hold_distances(c, climber_height);
	float rating_shapes = rating_hold_shapes(c);
	float rating_rock = rating_rock_angle(c); 
	
	if((rating_hold >= rating_shapes) && (rating_hold >= rating_rock))
		return rating_hold;
	else if((rating_shapes >= rating_hold) && (rating_shapes >= rating_rock))
		return rating_shapes;
	else 
		return rating_rock;
				
}
