#include <stdio.h>
#include <stdlib.h>
#include "hw3.h"
#include "hw3_provided.h"

/*hide_image
 * hides the second in the first image using the resulting image arrays
 * inputs: first image rgb arrays, second image rgb arrays, third image rgb arrays, height, width
 * output: changed res arrays
*/
void hide_image(unsigned int ref_r[ROWS][COLS], unsigned int ref_g[ROWS][COLS],
        unsigned int ref_b[ROWS][COLS],unsigned int hid_r[ROWS][COLS],unsigned int hid_g[ROWS][COLS],
        unsigned int hid_b[ROWS][COLS],unsigned int res_r[ROWS][COLS],unsigned int res_g[ROWS][COLS],
	unsigned int res_b[ROWS][COLS],unsigned int height, unsigned int width)
{
	if((height > ROWS) || (width > COLS))
	{
		fprintf(stderr, "error hide_image: image dimensions out of bounds"); 
		return;
	}
	//loop through every row index 
	for(int r = 0; r< height; r++)
	{
		//loop through every column index; check conditions for each pixel
		for(int c = 0; c < width; c++)
		{
			if(hid_r[r][c]>= 128)
			{
				//value of reference picture must be odd
				if(ref_r[r][c]%2 == 0)
				{
					res_r[r][c] = ref_r[r][c] + 1; 
				}
				else
					res_r[r][c] = ref_r[r][c];
			}
			if(hid_r[r][c] < 128)
			{
				//value of reference picture must be even
				if(ref_r[r][c]%2 == 1)
					res_r[r][c] = ref_r[r][c] -1;
				else
					res_r[r][c] = ref_r[r][c]; 
			}
			if(hid_g[r][c]>= 128)
                        {
                                //value of reference picture must be odd
                                if(ref_g[r][c]%2 == 0)
                                {
                                        res_g[r][c] = ref_g[r][c] + 1;
                                }
                                else
                                        res_g[r][c] = ref_g[r][c];
                        }
                        if(hid_g[r][c] < 128)
                        {
                                //value of reference picture must be even
                                if(ref_g[r][c]%2 == 1)
                                        res_g[r][c] = ref_g[r][c] -1;
                                else
                                        res_g[r][c] = ref_g[r][c];
                        }	
			if(hid_b[r][c]>= 128)
                        {
                                //value of reference picture must be odd
                                if(ref_b[r][c]%2 == 0)
                                {
                                        res_b[r][c] = ref_b[r][c] + 1;
                                }
                                else
                                        res_b[r][c] = ref_b[r][c];
                        }
                        if(hid_b[r][c] < 128)
                        {
                                //value of reference picture must be even
                                if(ref_b[r][c]%2 == 1)
                                        res_b[r][c] = ref_b[r][c] -1;
                                else
                                        res_b[r][c] = ref_b[r][c];
                        }
		}
	}
	return;			
}

/* extract_image
 * extracts the image hidden in the res parameter
 * inputs: res rgb arrays, hid rgb arrays, height, width
 * output: changed hid rgb arrays
*/

void extract_image(unsigned int res_r[ROWS][COLS],unsigned int res_g[ROWS][COLS],
        unsigned int res_b[ROWS][COLS],unsigned int hid_r[ROWS][COLS],
        unsigned int hid_g[ROWS][COLS],unsigned int hid_b[ROWS][COLS],unsigned int height,
	 unsigned int width)
{
	if((height > ROWS) || (width > COLS))
        {
                fprintf(stderr, "error extract_image: image dimensions out of bounds");
                return;
        }
        //loop through every row index
        for(int r = 0; r< height; r++)
        {
		for(int c = 0; c < width; c++)
		{
			//check res array even or odd
			if(res_r[r][c]%2 == 0)
				hid_r[r][c] = 0;
			else 
				hid_r[r][c] = 255; 
			if(res_g[r][c]%2 == 0)
				hid_g[r][c] = 0; 
			else
				hid_g[r][c]= 255; 
			 if(res_b[r][c]%2 == 0)
                                hid_b[r][c] = 0;
                        else
                                hid_b[r][c]= 255;
		}
	}

	return; 
}

/* encode
 * takes the filename of a reference and picture to hide, produces the resulting image
 * inputs: filename of reference, filename of hide image, encoded filename
 * output: written file
*/

void encode(char *ref_filename, char *hid_filename, char *enc_filename)
{
	unsigned int ref_r[ROWS][COLS]; unsigned int ref_g[ROWS][COLS]; unsigned int ref_b[ROWS][COLS]; 
	unsigned int hid_r[ROWS][COLS]; unsigned int hid_g[ROWS][COLS]; unsigned int hid_b[ROWS][COLS];
	unsigned int res_r[ROWS][COLS]; unsigned int res_g[ROWS][COLS]; unsigned int res_b[ROWS][COLS];	
	unsigned int width;
	unsigned int length;	

	provided_read_png(ref_filename, ref_r, ref_g, ref_b, &width, &length); 
	provided_read_png(hid_filename, hid_r, hid_g, hid_b, &width, &length); 
	hide_image(ref_r, ref_g, ref_b, hid_r, hid_g, hid_b, res_r, res_g, res_b, length, width); 
	provided_write_png(enc_filename, res_r, res_g, res_b, width, length); 
	return;
}

/* decode
 * takes encrypted file and extracts hidden file
 * inputs: encoded file, hidden file
 * output: output hid file
*/

void decode(char *enc_filename, char *hid_filename)
{
	unsigned int hid_r[ROWS][COLS]; unsigned int hid_g[ROWS][COLS]; unsigned int hid_b[ROWS][COLS];
        unsigned int res_r[ROWS][COLS]; unsigned int res_g[ROWS][COLS]; unsigned int res_b[ROWS][COLS];
	unsigned int width; unsigned int length; 
	provided_read_png(enc_filename, res_r, res_g, res_b, &width, &length); 
	extract_image(res_r, res_g, res_b, hid_r, hid_g, hid_b, length, width); 
	provided_write_png(hid_filename, hid_r, hid_g, hid_b, width, length); 
	return;
}
