#include <stdio.h>
#include <stdlib.h>
#include "hw5.h"
#include <string.h>
#define NUM_EVENTS 4
#define NUM_COUNTRIES 8

char *country_strings[] = { "USA", "Mexico", "Brazil", "Russia", 
	"China", "South Africa", "Chile", "Romania"};

void print_gymnast(gymnast_info *g, FILE *fp)
{
	fprintf(fp,"%s %s ",g->firstname, g->lastname);
	fprintf(fp,"%s:",country_strings[g->country]);
	int i;
	for(i=0;i<NUM_EVENTS;i++)
		fprintf(fp,"%f, ",g->scores[i]);
	fprintf(fp,"\n");
}

void print_list(llist *head, FILE *fp)
{
	llist *tmp;
	for(tmp = head; tmp != NULL; tmp = tmp->next)
		print_gymnast(tmp->g,fp);
}

gymnast_info *create_gymnast(char *first, char *last, enum Country c, 
		float *scores)
{
	gymnast_info *new_gymnast = (gymnast_info *) malloc(sizeof(new_gymnast));
	new_gymnast->firstname = (char *) malloc(sizeof(char *)); 
	new_gymnast->lastname = (char *) malloc(sizeof(char *)); 
	if((first == NULL)||(last == NULL) || (scores == NULL))
	{
		return NULL; 
	}	
	else
	{
		strcpy(new_gymnast->lastname, last); 
		strcpy(new_gymnast->firstname, first); 
		new_gymnast->country = c;
		for(int i = 0; i < NUM_EVENTS; i++)
		{
			new_gymnast->scores[i] = scores[i]; 
		} 
		return new_gymnast; 
	}
}

//Given array of scores, return the sum
float sum_scores(float *scores)
{
	float sum = 0;
	//For loop up til NUM_EVENTS and add up all the scores
	for(int i = 0; i < NUM_EVENTS; i++)
	{
		sum += scores[i]; 
	}
	return sum;				
}

//Given array of scores, return the highest
float max_score(float *scores, int length)
{
	float max = 0; 
	for(int i = 0; i < length; i++)
	{
		if(scores[i] > max)
			max = scores[i];
	}
	return max; 
}

enum Country max_country(llist *list)
{
	llist *temp; 
	float us_score = 0; float me_score = 0; float bra_score = 0; float rus_score = 0; 
	float chi_score = 0; float saf_score = 0; float chil_score = 0; float rom_score = 0;
	//Loop through every gymnast_info, summing up the scores for each country
	for(temp = list; temp != NULL; temp = temp->next)
	{
		switch(temp->g->country){
			case(USA): us_score += sum_scores(temp->g->scores); break;
			case(MEXICO): me_score += sum_scores(temp->g->scores); break;
			case(BRAZIL): bra_score += sum_scores(temp->g->scores); break;
			case(RUSSIA): rus_score += sum_scores(temp->g->scores); break;
			case(CHINA): chi_score += sum_scores(temp->g->scores); break;
			case(SAFRICA): saf_score += sum_scores(temp->g->scores); break;
			case(CHILE): chil_score += sum_scores(temp->g->scores); break;
			case(ROMANIA): rom_score += sum_scores(temp->g->scores); break;
		}
	}
	int max_index; 
	int max = 0;
	float score_list[] = {us_score, me_score, bra_score, rus_score, chi_score, saf_score, chil_score, rom_score}; 
	//Loop through the list of summed scores for each country and get the index of the top scoring country 
	for(int i = 0; i < NUM_COUNTRIES; i++)
	{
		if(score_list[i] > max){
			max = score_list[i];
			max_index = i;}
	}			
	switch(max_index)
	{
		case(0): return USA; break;
		case(1): return MEXICO; break;
		case(2): return BRAZIL; break;
		case(3): return RUSSIA; break;
		case(4): return CHINA; break;
		case(5): return SAFRICA; break;
		case(6): return CHILE; break;
		case(7): return ROMANIA; break;
		default: fprintf(stderr, "error max_country: not a valid max_index"); return 0; 
	}
}

float sum_country(llist *list, enum Country c)
{
	llist *temp; 
	float tot = 0; 
	//Loop through every gymnast, summing up for the specific country 
	for(temp = list; temp != NULL; temp = temp->next)
	{
		if(temp->g->country == c){
			tot+= sum_scores(temp->g->scores);
			 break;}
	}
	return tot; 
	
}

llist *add_sorted_name(gymnast_info *ginfo, llist *head)
{
	char *last = ginfo->lastname; 
	char *first = ginfo->firstname;
	llist *temp;
	llist *new = (llist *) malloc(sizeof(llist));
	char *temp_last = NULL;
	char *temp_first = NULL;
	int insert = -1;
	//Loop through list of gymnasts, checking names 
	for(temp = head; temp!=NULL; temp=temp->next)
	{
		temp_last = temp->g->lastname; 
		temp_first = temp->g->firstname; 
		if(strcasecmp(last, temp_last) < 0)
		{
			if(insert == -1)
			{
				new->g = ginfo; 
				new->next = head;
				return new;
			}
			break;
		}
		else if(strcasecmp(last,temp_last) == 0)
		{
			if(strcasecmp(first, temp_first) < 0)
			{
				if(insert == -1)
				{
					new->g = ginfo; 
					new->next = head;
					return new;
				}
				break;
			}
			//if first name is also the same, then insert ginfo after this entry 
			else if(strcasecmp(first, temp_first) == 0)
			{
				new->g = ginfo; 
				new->next = temp->next; 
				temp->next = new; 
				return head;
			}
			
		}
		else{
			insert++;
			}
	}
	//Loop up until insert and add ginfo to the next node
	temp = head;
	for(int i = 0; i < insert; i++)
	{
		temp = temp->next; 
	}
	new->g = ginfo; 
	if(temp->next == NULL)
	{
		temp->next = new; 
	}
	else
	{
		new->next = temp->next;
		temp->next = new; 
	}
	return head;  	
}

llist *add_sorted_country(gymnast_info *ginfo, llist *head)
{
	llist *temp;
	llist *new = (llist *) malloc(sizeof(llist)); 
	enum Country g_country = ginfo->country; 
	int insert = -1;  
	//Loop through head and find the first country that is after the inserted country 
	for(temp = head; temp != NULL; temp = temp->next)
	{
		enum Country tmp_c = temp->g->country;
		if(g_country < tmp_c)
		{
			if(insert ==-1)
			{
				new->g = ginfo; 
				new->next = head;
				return new;
			}
			break;
		}
	}
	temp = head; 
	//Move temp up to insert index then insert the new gymnast
	for(int i = 0; i < insert; i++)
	{
		temp = temp->next;
	}
	new->g = ginfo; 
	new->next = temp->next;
	temp->next = new;
	return head; 	
	
}
llist *add_sorted_total(gymnast_info *ginfo, llist *head)
{
	llist *temp; 
	llist *temp2;
	llist *new = (llist *) malloc(sizeof(llist));
	float tot_add = sum_scores(ginfo->scores);
	int index = -1;
	float tot_tmp;
	
	//Loop through the gymnasts and find the first instance where the score is lower 
	for(temp = head; temp != NULL; temp = temp->next)
	{
		tot_tmp = sum_scores(temp->g->scores);
		if(tot_add > tot_tmp)
		{
			if(index == -1)
			{
				new->g = ginfo; 
				new->next = head; 
				return new;
			}
			break;
		} 
		else if(tot_add == tot_tmp)
		{
			temp2 = temp; 
			//Find the last index of the gymnast with the same score
			while(tot_add == tot_tmp)
			{
				index++; 
				temp2= temp2->next;
				tot_tmp = sum_scores(temp2->g->scores);
			}
			break; 
		}
		else
			index++;
	}
	temp = head;
	//Use index to insert new gymnast 
	for(int i = 0; i < index; i++)
	{
		temp = temp->next;
	}	
	new->g = ginfo; 
	new->next = temp->next;
	temp->next = new;
	return head;
}

gymnast_info *modify_score(char *first, char *last, enum Event e, float score,
		llist *head)
{
	llist *temp;
	gymnast_info *g_return = (gymnast_info *) malloc(sizeof(gymnast_info));  
	//Loop through head and find the gymnast with the same name
	for(temp = head; temp != NULL; temp=temp->next)
	{
		char *templast = temp->g->lastname;
		char *tempfirst = temp->g->firstname;
		if((strcasecmp(templast, last) == 0) && (strcasecmp(tempfirst, first) == 0))
		{
			g_return = temp->g; 
			break;
		}
	}
	if(temp == NULL)
	{
		printf("modify_score: gymnast not found \n");
		return NULL; 
	}
	else
	{	
		(g_return->scores)[e] = score; 
		return g_return;
	}
}

llist *modify_sorted_total(gymnast_info *ginfo, llist *head)
{
	llist *new = (llist *) malloc(sizeof(llist));
	//Searches llist for the gymnast with ginfo 
	char *first = ginfo->firstname; 
	char *last = ginfo->lastname;
	llist *tmp; 
	int index = -1; 
	for(tmp = head; tmp != NULL; tmp=tmp->next)
	{
		char *templast = tmp->g->lastname;
                char *tempfirst = tmp->g->firstname;
                if((strcasecmp(templast, last) == 0) && (strcasecmp(tempfirst, first) == 0))
                { 
                        break;
                }
		index++; 
	}
	//If gymnast not found, then just return head
	if(tmp == NULL)
	{
		printf("modify_sorted_total: gymnast not found\n"); 
		return head;  
	}
	else{
	//Remove the node with the changed information
	//Loop to the node before the offending node
	tmp = head;
	for(int i = 0; i < index; i++)
	{
		tmp=tmp->next;
	}
	if(tmp->next->next == NULL)
	{
		tmp->next = NULL; 
	}
	else
		tmp->next = tmp->next->next; 
	//Sort in the new ginfo 
	new = add_sorted_total(ginfo, head);  
	return new;
	}
}

llist *modify_sorted_country(gymnast_info *ginfo, llist *head)
{
	llist *new = (llist *) malloc(sizeof(llist));
        //Searches llist for the gymnast with ginfo and updates
        char *first = ginfo->firstname;
        char *last = ginfo->lastname;
	enum Country c = ginfo->country; 
        llist *tmp;
        int index = -1;
        for(tmp = head; tmp != NULL; tmp=tmp->next)
        {
                char *templast = tmp->g->lastname;
                char *tempfirst = tmp->g->firstname;
		enum Country tempc = tmp->g->country;
                if((strcasecmp(templast, last) == 0) && (strcasecmp(tempfirst, first) == 0) && (tempc == c))
                {
			tmp->g = ginfo; 
                        break;
                }
                index++;
        }
        //If gymnast not found, then just return head
        if(tmp == NULL)
        {
                printf("modify_sorted_total: gymnast not found\n");
                return head;
        }
	//Otherwise, reorder based on new country scores  
	else{
		int index = 0; 
		int i;
		int first; 
		int last; 
		//Get first and last indices of country 
		for(tmp = head; tmp != NULL; tmp=tmp->next)
		{
			if(tmp->g->country == c)
			{	first = index; 
				break;	
			}
			else
				index++; 
		}
		for(tmp = tmp; tmp != NULL; tmp = tmp->next)
		{
			if(tmp->g->country != c)
			{
				last = index-1; 
				break;
			}
			else
				index++; 
		}
		//If country is ordered last
		if(tmp == NULL)
			last = index-1;
		//Get the sum of the altered country score
		float new_score = sum_country(head, c);
		printf("total new score: %f\n", new_score);  
		//Get first index of node with country with score lower than new_score
		int end = 0; 
		float temp_score; 
		for(tmp = head; tmp != NULL; tmp=tmp->next)
		{
			enum Country tempc = tmp->g->country; 
			temp_score = sum_country(head, tempc); 
			if(temp_score <= new_score)
				break;
			else
				end++; 
		}
		printf("first index: %d\n", end); 
		//If new_score is lowest, then throw to the end 
		llist *tmp2 = head;
		if(tmp == NULL)
		{
			tmp = head;
			for(i = 0; i < end-1; i++)
				tmp = tmp->next; 
			for(int j = 0; j < first; j++)
				tmp2 = tmp2->next; 
			llist *beg = head;
			for(i = 0; i < first-1; i++)
				beg = beg->next; 
			llist *end = head; 
			for(i = 0; i < last+1; i++)
				end = end->next;
			beg->next = end;  
			tmp->next = tmp2;
			return head; 
		}
		//Otherwise link the last node of the altered country to the next country
		else
		{
			tmp = head; 
			for(i = 0; i < end; i ++)
				tmp = tmp->next; 
			tmp2 = head; 
			for(int j = 0; j<last; j++)
				tmp2 = tmp2->next; 
			llist *beg = head; 
			for(i = 0; i < end-1; i++)
				beg=beg->next; 
			llist *beg2 = head; 
			for(i = 0; i <first; i++)
				beg2= beg2->next; 
			//Get pointers for the nodes before and after the altered country
			llist *bef = head; 
			llist *aft = head; 
			for(i = 0; i < first-1; i++)
				bef = bef->next; 
			for(i = 0; i < last+1; i++)
				aft = aft->next;
			 //If country is new head, create new llist and return it
                        if(tmp == head)
                        {
                                llist *new = beg2;
				tmp2->next = tmp; 
				bef->next = aft; 
				return new; 
                        }
			//Put it all together
			tmp2->next = tmp;
			beg->next = beg2; 
			bef->next = aft;
 			return head;
		}
		
	}
}
