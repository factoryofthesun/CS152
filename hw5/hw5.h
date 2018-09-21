#ifndef HW5_H
#define HW5_H
#include <stdio.h>
#include <stdlib.h>

enum Country { USA=0, MEXICO, BRAZIL, RUSSIA, CHINA, SAFRICA, 
			CHILE, ROMANIA };
#define NUM_COUNTRIES 8

enum Event { UNEVEN=0, VAULT, BEAM, FLOOR };
#define NUM_EVENTS 4

typedef struct {
 char *lastname;
 char *firstname;
 enum Country country;
 float scores[NUM_EVENTS];
} gymnast_info;

// for the linked list, we will use the following struct
typedef struct _llist llist;

struct _llist{
 gymnast_info *g;
 llist *next;
};

// extern defines a global variable that all files can use. It is in 
// the .h file, then it needs to be declared again inside a single .c file
// without the extern keyword preceeding it.
extern char *country_strings[];
void print_gymnast(gymnast_info *g, FILE *fp);
void print_list(llist *head, FILE *fp);

/*gymnast_info *create_gymnast
inputs: char * first, char *last, enum Country c, float *scores
output: gymnast info struct
Allocates memory and fills in fields for gymnast 
*/ 
gymnast_info *create_gymnast(char *first, char *last, enum Country c, 
		float *scores);

/*x_score 
input: float *, int
output: float
either sums the scores up or returns the maximum score in the array
*/

float sum_scores(float *scores);
float max_score(float *scores, int length);

/*max_country
input: llist *
output; enum
Returns the name of the country with the highest score
*/
enum Country max_country(llist *list);

float sum_country(llist *list, enum Country c);
/*add_sorted_x 
inputs: gymnast_info *ginfo, llist *head
output: pointer to linked list 
enters the new gymnast info into llist head in sorted order
*/

llist *add_sorted_name(gymnast_info *ginfo, llist *head);
llist *add_sorted_country(gymnast_info *ginfo, llist *head);
llist *add_sorted_total(gymnast_info *ginfo, llist *head);

/*modify_score
inputs: char* first, char* last, enum Event e, float score, llist head
output: gymnast_info
modifies the score for the given gymnast and event in the llist */
gymnast_info *modify_score(char *first, char *last, enum Event e, float score,
		llist *head);
/*modify_sorted_x 
input: gymnast_info *, llist *
output: llist *
Sorts new gymnast info into llist head
*/
llist *modify_sorted_total(gymnast_info *ginfo, llist *head);
llist *modify_sorted_country(gymnast_info *ginfo, llist *head);

#endif
