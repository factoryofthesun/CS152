#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "hw1.h"  // see how we're including the file again?

// you will need to implement check functions here
unsigned int check_surface_area_tetrahedron(double length,
					double expected_result)
{
	double dresult = surface_area_tetrahedron(length);
	double error_tolerance = 0.01;
	if ((dresult >= expected_result - error_tolerance) && 
		(dresult <= expected_result + error_tolerance))
	{
		return 1;
	}
	else
	{
		printf("Unexpected result. surface_area_tetrahedron(%lf)\n",
			length);
		printf("returned %lf, expected %lf \n",dresult, expected_result);
		return 0;
	}
}

unsigned int check_sides_to_area(int side_num, double length,
                                        double expected_result)
{
        double dresult = sides_to_area(side_num,length);
        double error_tolerance = 0.01;
        if ((dresult >= expected_result - error_tolerance) &&
                (dresult <= expected_result + error_tolerance))
        {
                return 1;
        }
        else
        {
                printf("Unexpected result. sides_to_area(%d, %lf)\n",
                        side_num, length);
                printf("returned %lf, expected %lf \n",dresult, expected_result);
                return 0;
        }
}

unsigned int check_fall_ground_distance(double height, double harness_height,
                                       double clip_distance, double expected_result)
{
        double dresult = fall_ground_distance(height, harness_height, clip_distance);
        double error_tolerance = 0.001;
        if ((dresult >= expected_result - error_tolerance) &&
                (dresult <= expected_result + error_tolerance))
        {
                return 1;
        }
        else
        {
                printf("Unexpected result. fall_ground_distance(%lf, %lf, %lf)\n",
                        height, harness_height, clip_distance);
                printf("returned %lf, expected %lf \n",dresult, expected_result);
                return 0;
        }
}

unsigned int check_number_halves(float distance, unsigned int expected_result)
{
        unsigned int dresult = number_halves(distance);
        double error_tolerance = 0.001;
        if (dresult == expected_result)
        {
                return 1;
        }
        else
        {
                printf("Unexpected result. number_halves(%lf)\n",
                        distance);
                printf("returned %u, expected %u \n",dresult, expected_result);
                return 0;
        }
}

unsigned int check_golden_spiral(float a, float b, int applications, float expected_result)
{
        double dresult = golden_spiral(a,b,applications);
        double error_tolerance = 0.001;
        if ((dresult >= expected_result - error_tolerance) &&
                (dresult <= expected_result + error_tolerance))
        {
                return 1;
        }
        else
        {
                printf("Unexpected result. golden_spiral(%lf, %lf, %d)\n",
                        a, b, applications);
                printf("returned %lf, expected %f \n",dresult, expected_result);
                return 0;
        }
}

int main()
{
	unsigned int num_checks = 16;
	unsigned int num_correct = 0;

	// here is a call to a check function

	// I am only putting one line in for each to test for compiling
	// you need to write your own test code
	num_correct = num_correct + check_surface_area_tetrahedron(5.0, 43.30127);
	num_correct += check_surface_area_tetrahedron(-1.1, -1.0);
	num_correct += check_surface_area_tetrahedron(100.0, 17320.51);

	num_correct += check_sides_to_area(7, 2.0, 14.5356);
        num_correct += check_sides_to_area(0, 52.0, -1.0);
	num_correct += check_sides_to_area(24, -23.4, -1.0);

	num_correct += check_fall_ground_distance(-1.1, 23, 40, INT_MIN);
	num_correct += check_fall_ground_distance(5, 12, 3, INT_MIN);
	num_correct += check_fall_ground_distance(8, 4, 4, 0);
	num_correct += check_fall_ground_distance(10, 2, 3, 2);	
	
	num_correct += check_number_halves(103, 7);
	num_correct += check_number_halves(0, 0);
	num_correct += check_number_halves(8, 3);

	num_correct += check_golden_spiral(1.3, 2.4, 10, 247.7);
	num_correct += check_golden_spiral(5, 3, 1, 8);
	num_correct += check_golden_spiral(5.3, 1.1, 6, 77.7);
	printf("Number of tests run: %d\n Number correct: %d\n", num_checks, num_correct);
	
	double test = 5.3 * 9.6;
	printf("%f\n", test); 
}

