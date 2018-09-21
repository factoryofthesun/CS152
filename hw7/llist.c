#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

/* create_list
 * purpose: create a linked list structure and initialize to empty list
 * inputs: none
 * outputs: pointer to newly created and initialized linked list
 */
llist *create_llist(){
	llist *list = (llist *) malloc(sizeof(llist)); 
	list->head = NULL; 
	list->tail = NULL; 
	return list; 	
}

void insert_head(llist *list, void *item)
{
	node *new = (node *) malloc(sizeof(node)); 
	new->item = item; 
	if(list == NULL)
	{
		llist *newlist = create_llist(); 
		newlist->head = new; 
		newlist->tail = new; 
		list = newlist; 
	}
	else if(list->head == NULL)
	{
		new->next = NULL; 
		list->head = new; 
		list->tail = new; 
	}
	else{
	new->next = list->head; 
	list->head = new; }
}

void remove_tail(llist *list)
{
	node *tmp; 
	node *prev;  
	//Have to check if list is empty, or has one item
	if(list == NULL)
		return;
	else if(list->head == list->tail)
	{
		node *tmp = list->head; 
		list->head = NULL; 
		list->tail = NULL; 
		free(tmp);  
	}
	else{

	for(tmp = list->head; tmp->next != NULL; tmp= tmp->next)
	{
		prev = tmp; 
	}
	list->tail = prev; 
	free(tmp); 
	}
	
}
/* insert_tail
 * purpose: insert an item to become the last item in a linked list.
 * inputs:
 *   list - pointer to llist struct in which to insert item
 *   item - a pointer to the item to be inserted into the linked list
 * return: nothing
 */

void insert_tail(llist *list, void *item){
	node *new = (node *) malloc(sizeof(node));
        new->item = item;
	new->next = NULL; 
	//Check if list is null
	if(list == NULL)
	{
		llist *newlist = create_llist(); 
		newlist->head = new; 
		newlist->tail = new; 
		*list = *newlist; 		
	}
	//Check if list head is empty
	else if(list->head == NULL)
	{
		list->head = new; 
		list->tail = new; 
	}
	else
	{
		node *tmp; 
		list->tail = new;  
		//Loop until at end of list 
		for(tmp = list->head; tmp->next != NULL; tmp=tmp->next)
		{
		}
		tmp->next = new; 
		}	
}
/* remove_head
 * purpose: remove the item that is at the beginning of a linked list
 * inputs:
 *   list - pointer to llist struct in which to insert item
 * return:
 */

void remove_head(llist *list)
{
	//Make sure list is not null
	if(list != NULL)
	{	
		//Check if list has one item
		if(list->head == list->tail)
		{
			node *temp = list->head; 
			list->head = list->head->next; 
			list->tail = list->tail->next; 
			free(temp);
		}
		else
		{			
			node *temp = list->head;
			list->head = list->head->next; 
			free(temp); 
		}
	}	
}

int list_is_empty(llist *list)
{
	if((list->head == NULL) && (list->tail == NULL))
		return 1; 
	else 
		return 0; 
}
