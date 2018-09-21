#ifndef HW4_PROVIDED_H
#define HW4_PROVIDED_H

typedef struct {
	unsigned int xcoor;
	unsigned int ycoor;
	unsigned int zcoor;
	unsigned int hold_shape;
} climbing_hold;

typedef struct {
	climbing_hold *right_holds; // array of climbing holds
	unsigned int num_right_holds;
	climbing_hold *left_holds; // array of climbing holds
	unsigned int num_left_holds;
} climb;

climb provided_read_climb(char* filename);
#endif

