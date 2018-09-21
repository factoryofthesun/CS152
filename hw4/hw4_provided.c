#include <stdio.h>
#include <stdlib.h>
#include "hw4_provided.h"

void checkError(char newline){
	if(newline != '\n'){
		fprintf(stderr,"error: holds file improperly specified\n");
		exit(1);
	}
}

climb provided_read_climb(char* filename){
	climb holds_data;
	unsigned int number_left_holds, number_right_holds;
	char buffer[1024];
	FILE *fp;
	fp = fopen(filename,"r");
	if(!fp){
		fprintf(stderr,"error: could not open file %s\n",filename);
		exit(1);
	}
	char newline;
	fscanf(fp, "%u%c", &number_left_holds, &newline);
	checkError(newline);
	holds_data.num_left_holds = number_left_holds;
	holds_data.left_holds = (climbing_hold *)malloc(sizeof(climbing_hold)*
					number_left_holds);
	climbing_hold *new_left_holds = holds_data.left_holds;
	for(int i = 0; i < number_left_holds; i++){
		climbing_hold new_hold;
		unsigned int xcoord,ycoord,zcoord,shape;
		fscanf(fp, "%u %u %u %u[^\n]%c", &xcoord,&ycoord,&zcoord,&shape,&newline);
		checkError(newline);
		new_hold.xcoor = xcoord;
		new_hold.ycoor = ycoord;
		new_hold.zcoor = zcoord;
		new_hold.hold_shape = shape;
		new_left_holds[i] = new_hold;
	}
	holds_data.left_holds = new_left_holds;
	fscanf(fp, "%u%c", &number_right_holds,&newline);
	checkError(newline);
	holds_data.num_right_holds = number_right_holds;
	holds_data.right_holds = (climbing_hold *)malloc(sizeof(climbing_hold)*
					number_right_holds);
	climbing_hold *new_right_holds = holds_data.right_holds;
	for(int i = 0; i < number_right_holds; i++){
		climbing_hold new_hold;
		unsigned int xcoord,ycoord,zcoord,shape;
		fscanf(fp, "%u %u %u %u[^\n]%c", &xcoord,&ycoord,&zcoord,&shape,&newline);
		checkError(newline);
		new_hold.xcoor = xcoord;
		new_hold.ycoor = ycoord;
		new_hold.zcoor = zcoord;
		new_hold.hold_shape = shape;
		new_right_holds[i] = new_hold;
	}
	holds_data.right_holds = new_right_holds;
	return holds_data;
}
