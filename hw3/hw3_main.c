#include <stdio.h>
#include <stdlib.h>
#include "hw3_provided.h"
#include "hw3.h"

int main()
{
	//declare variables
	unsigned int ref_r[ROWS][COLS]; 
	unsigned int ref_g[ROWS][COLS]; 
	unsigned int ref_b[ROWS][COLS]; 
	unsigned int hid_r[ROWS][COLS]; 
	unsigned int hid_g[ROWS][COLS]; 
	unsigned int hid_b[ROWS][COLS]; 
	unsigned int res_r[ROWS][COLS]; 
	unsigned int res_g[ROWS][COLS]; 
	unsigned int res_b[ROWS][COLS];
	unsigned int height;
	unsigned int width;
	char ref_filename[] = "slaves.png"; 
	char hid_filename[] = "shrek.png";
	char enc_filename[] = "secret.png";
	char hid2_filename[] = "newshrek.png"; 
	//call functions
	hide_image(ref_r, ref_g, ref_b, hid_r, hid_g, hid_b, res_r, res_g, res_b, height, width); 
	extract_image(res_r, res_g, res_b, hid_r, hid_g, hid_b, height, width); 
	encode(ref_filename, hid_filename, enc_filename); 
	decode(enc_filename, hid2_filename); 
}
