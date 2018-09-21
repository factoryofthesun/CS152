#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw5.h"

int gymnast_equal(gymnast_info *g_info1, gymnast_info *g_info2)
{
	//Compare scores elementwise
	for(int i = 0; i < NUM_EVENTS; i++)
	{
		if((g_info1->scores)[i] != (g_info2->scores)[i])
		{
			return 0; 
		}
	}
	//Compare everything else
	if((strcasecmp(g_info1->lastname, g_info2->lastname) != 0) || 
		(strcasecmp(g_info1->firstname, g_info2->firstname) != 0) || ((g_info1->country) != (g_info2->country)))
		return 0; 
	else
		return 1; 
}

int llist_equal(llist *l1, llist *l2)
{
	llist *tmp1 = l1; 
	llist *tmp2 = l2; 
	while((tmp1 != NULL) && (tmp2 != NULL) && (gymnast_equal(tmp1->g, tmp2->g)))
	{
		tmp1 = tmp1->next; 
		tmp2 = tmp2->next; 
	}
	return tmp1 == tmp2; 
}

llist* insert_head(gymnast_info *ginfo, llist *list)
{
	llist *new = (llist *) malloc(sizeof(llist)); 
	new->g = ginfo; 
	new->next = list; 
	return new; 
}

int main()
{
	//get input variables
	void *expected = NULL; 	
	char *first = NULL; 
	char *last = NULL; 
	enum Country c; 
	float score; 
	llist *head = NULL; 
	llist *addlist = NULL; 
	gymnast_info *ginfo = NULL;
	enum Event e; 

	//Run tests 
	//Create_gymnast
	first = "Tom"; last = "AndJerry"; c = MEXICO; float scores1[] = {2, 3, 4, 5}; 
	ginfo = create_gymnast(first, last, c, scores1); 
	print_gymnast(ginfo, stdout); 
	
	ginfo = create_gymnast(first, last, c, NULL);
	if(ginfo != NULL)
		printf("create_gymnast - test 1 fail \n"); 
	else 
		printf("create_gymnast - null test passed\n");
	//max_country
	gymnast_info g1 = {"us", "Man", USA, {1, 1, 1, 1}};
	gymnast_info g2 = {"roma", "person", ROMANIA, {9,9,9,9}};
	gymnast_info g3 = {"bra", "person", BRAZIL, {9,8,9,9}}; 
	gymnast_info g4 = {"mex", "person", MEXICO, {9,9,9,9}};
	head = insert_head(&g1, head); head = insert_head(&g2, head); head = insert_head(&g3, head); 
	c = max_country(head); 
	if(c != ROMANIA)
		printf("max_country - test 1 fail\n"); 
	else
		printf("max_country - test 1 pass\n"); 
	head = insert_head(&g4, head); 
	c = max_country(head); 
	if(c != MEXICO)
		printf("max_country - test 2 fail\n"); 
	else
		printf("max_country-test 2 pass\n"); 

	//insertion sorting 
	printf("testing add_sorted_name\n");
	addlist = insert_head(&g2, addlist); addlist = insert_head(&g4, addlist); addlist = insert_head(&g3, addlist); 
	addlist = add_sorted_name(&g1, addlist); 
	print_list(addlist, stdout); 
	addlist = add_sorted_name(&g3, addlist); 
	print_list(addlist, stdout);
	gymnast_info g5 = {"braa", "person", BRAZIL, {0,1,8,3}}; 
	addlist = add_sorted_name(&g5, addlist); 
	print_list(addlist, stdout);
	
	printf("testing add_sorted_country\n");		
	addlist = NULL; addlist = insert_head(&g2, addlist); 
	addlist = add_sorted_country(&g1, addlist); 
	addlist = add_sorted_country(&g2, addlist); 
	print_list(addlist, stdout); 
	printf("expected order: US, Romania, Romania\n"); 

	printf("testing add_sorted_total\n"); 
	addlist = NULL; addlist = insert_head(&g1, addlist); addlist = insert_head(&g2, addlist); 
	addlist = add_sorted_total(&g3, addlist); 
	addlist = add_sorted_total(&g4, addlist); 
	print_list(addlist, stdout); 
	printf("expected order: Romania, Mexico, Brazil, US\n"); 

	printf("testing modify_score\n");
	addlist = NULL; addlist = insert_head(&g1, addlist); addlist= insert_head(&g3, addlist); 
	ginfo = modify_score("MAN", "us", 2, 1000, addlist); 
	if((ginfo->scores)[2] == 1000)
		printf("modify_score - test 1 success\n"); 
	else
		printf("modify_score - test 1 fail\n"); 
	ginfo = modify_score("asdlkfdk", "hello", 1, 14, addlist); 
	if(ginfo == NULL)
		printf("modify_score - test 2 success\n"); 
	else
		printf("modify_score - test 2 fail\n"); 

	printf("testing modify_sorted_total...\n");
	addlist = NULL; addlist = insert_head(&g1, addlist); addlist = insert_head(&g2, addlist); 
	ginfo = &g1; 
	ginfo->lastname = "us";
	ginfo->firstname = "man"; ginfo->country = MEXICO; ginfo->scores[2] = 1000; 
	addlist = modify_sorted_total(ginfo, addlist); 
	print_list(addlist, stdout); 
	printf("Expected order: us (now mexico), romania\n");  

	addlist = NULL; addlist = insert_head(&g1, addlist); addlist = insert_head(&g2, addlist); gymnast_info g6 = {"dne", "dne", USA, {0,0,0,0}}; 
	addlist = modify_sorted_total(&g6, addlist);
	print_list(addlist, stdout); 
	printf("Expected order: romania, us\n");  

	printf("testing modify_sorted_country...\n"); 
	addlist = NULL; addlist = insert_head(&g4, addlist); addlist = insert_head(&g4, addlist); addlist = insert_head(&g4, addlist); addlist = insert_head(&g2, addlist);
	gymnast_info g7 = {"mex", "person", MEXICO, {1000,1000,0,0}}; 
	addlist = modify_sorted_country(&g7, addlist); 
	print_list(addlist, stdout); 
	printf("Expected order: Mexico, romania\n"); 
	
	addlist = NULL; addlist = insert_head(&g4, addlist); addlist = insert_head(&g4, addlist); addlist = insert_head(&g4, addlist); addlist = insert_head(&g2, addlist);
        addlist = modify_sorted_country(&g6, addlist);
	print_list(addlist, stdout); 
	printf("Expected order: romania, mexico\n");
}
