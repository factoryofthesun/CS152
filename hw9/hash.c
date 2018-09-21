#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hash.h"
#include "word.h"

#define MAX_BUFFER 150

unsigned int generate_hash(hash_table_t *ht, unsigned long int key) 
{
	unsigned int size = ht->size; 
	unsigned int rem = key%size; 
	return rem; 
}


hash_table_t* create_hash_table(unsigned int size, 
			unsigned long int (*getkey)(void *),
			int (*compare)(void *, void *))
{
	hash_table_t *ht = (hash_table_t *) malloc(sizeof(hash_table_t));
	ht->head = (hash_node_t **) malloc(sizeof(hash_node_t *) * size); 
	ht->size = size; 
	ht->getkey = getkey; 
	ht->compare = compare; 
	return ht; 
}

int insert_linear(hash_table_t *ht, void *value, int *opcount)
{
	unsigned long int key = ht->getkey(value); 
	unsigned int index = generate_hash(ht, key); 
	int ops = 1;
	hash_node_t **tmp = ht->head; 
	//Loop through the list of hash nodes, starting at index
	//Stop when first empty space found or entire list traversed
	while(ops < ht->size)
	{
		//If reached end of list, start from index = 0
		if(index == ht->size)
		{
			index = 0; 
		}
		if(tmp[index] == NULL)
		{
			tmp[index] = (hash_node_t *) malloc(sizeof(hash_node_t)); 
			tmp[index]->key = key;
			tmp[index]->value = value;
			*opcount = ops; 
			return 1; 
		}
		ops++; 
		index++; 
	}
	return 0; 
}

void* search_linear(hash_table_t *ht, void *value, int *opcount)
{
	unsigned long int key = ht->getkey(value);
        unsigned int index = generate_hash(ht, key);
        int i = 1;
        hash_node_t **tmp = ht->head;
        //Loop through the list of hash nodes, starting at index
        //Stop when the value is found or entire list traversed
        while(i <= ht->size)
        {
                //If reached end of list, start from index = 0
                if(index == ht->size)
                {
                        index = 0;
                }
		if(tmp[index] != NULL)
		{
                	if(ht->compare(value, tmp[index]->value) == 0)
                        {
				*opcount = i;
                        	return tmp[index]; 
                	}
		}
                i++;
                index++;
		
        }
        return NULL;	
}



float insert_from_file(hash_table_t *ht, char * filename)
{
    FILE *fp;
    char buf[MAX_BUFFER] = "";
    int count=0, total=0, ops=0;
	
    // attempt to open the file, then check whether that worked.
    if ((fp = fopen(filename, "r")) == NULL)
    {
    fprintf(stderr,"Could not open file %s\n",filename);
    return (1);
    }

    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
	buf[strlen(buf)-1] = '\0';
        wordcount *wc = create_count(buf);
	print_word(wc);
	printf("\n");  
        insert_linear(ht, (void *)wc, &ops);
	total += ops;
        count++;
    }

    fclose(fp);

    return ((float) total)/count;
}

float search_from_file(hash_table_t *ht, char * filename)
{
    FILE *fp;
    char buf[MAX_BUFFER] = "";
    int count=0, total=0, ops=0;

    // attempt to open the file, then check whether that worked.
    if ((fp = fopen(filename, "r")) == NULL)
    {
    fprintf(stderr,"Could not open file %s\n",filename);
    return (1);
    }
    
    wordcount wc, *wc_result;
    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
	buf[strlen(buf)-1] = '\0';
	strcpy(wc.word, buf);
        wc_result = search_linear(ht, (void *)(&wc), &ops);
	total += ops;
        count++;
    }

    fclose(fp);

    return (float) total/count;
}

void print_hash_table_entries(hash_table_t *ht)
{
    int i;
    for(i=0; i< ht->size; i++)
    {
        hash_node_t *ptr = ht->head[i];
	// print the first one
	if (ptr != NULL)
        {
            printf("[%d]= (%lu,", i ,ptr->key);
	    print_word(ptr->value); // yes, breaking abstraction
            printf(") ");
        }
        else
            printf("[%d]= NULL ", i);
    }
	printf("\n"); 
}
