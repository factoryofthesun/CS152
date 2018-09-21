#ifndef HW3_H
#define HW3_H

#define ROWS 50
#define COLS 50
/*hide_image
 * hides the second in the first image using the resulting image arrays 
 * inputs: first image rgb arrays, second image rgb arrays, third image rgb arrays, height, width
 * output: changed res arrays
*/ 
void hide_image(
	unsigned int ref_r[ROWS][COLS], 
	unsigned int ref_g[ROWS][COLS], 
	unsigned int ref_b[ROWS][COLS], 
	unsigned int hid_r[ROWS][COLS], 
	unsigned int hid_g[ROWS][COLS], 
	unsigned int hid_b[ROWS][COLS], 
	unsigned int res_r[ROWS][COLS], 
	unsigned int res_g[ROWS][COLS], 
	unsigned int res_b[ROWS][COLS], 
	unsigned int height, unsigned int width);

/* extract_image
 * extracts the image hidden in the res parameter
 * inputs: res rgb arrays, hid rgb arrays, height, width
 * output: changed hid rgb arrays 
*/ 

void extract_image(
	unsigned int res_r[ROWS][COLS], 
	unsigned int res_g[ROWS][COLS], 
	unsigned int res_b[ROWS][COLS], 
	unsigned int hid_r[ROWS][COLS], 
	unsigned int hid_g[ROWS][COLS], 
	unsigned int hid_b[ROWS][COLS], 
	unsigned int height, unsigned int width);

/* encode
 * takes the filename of a reference and picture to hide, produces the resulting image
 * inputs: filename of reference, filename of hide image, encoded filename
 * output: written file 
*/ 

void encode(char *ref_filename, char *hid_filename, char *enc_filename);

/* decode
 * takes encrypted file and extracts hidden file 
 * inputs: encoded file, hidden file 
 * output: output hid file 
*/ 

void decode(char *enc_filename, char *hid_filename);

#endif
