#ifndef _HASH_H_
#define _HASH_H_

typedef struct _hash_node_t hash_node_t;

struct _hash_node_t {
    unsigned long int key;
    void *value;
};


typedef struct _hash_table_t hash_table_t;
struct _hash_table_t{
    unsigned int size;
    hash_node_t **head;
    // Function pointer to get keys
    unsigned long int (*getkey)(void *);
    // Function pointer to compare items
    int (*compare)(void *, void *);
};


/* generate_hash
 * given a hash table and a key from an item, calculate the index
 * in the table.
 * inputs:
 *    ht - a hash table
 *    key - the key of the item
 * outputs:
 *    an index between 0 (inclusive) and hash table size (exclusive)
 */
unsigned int generate_hash(hash_table_t *ht, unsigned long int key);

/* create_hash_table
 * create the memory for the hash table and initialize all variables.
 * inputs:
 *  size - the initial size of the hash table
 *  getkey - a function that calculates the key of the type of item in the table
 *  compare - a function that compares two items of the type in the table
 */
hash_table_t* create_hash_table(unsigned int size, 
				unsigned long int (*getkey)(void *),
				int (*compare)(void *, void *));

/* insert_linear
 *  insert function that uses linear probing
 * inputs:
 *   ht - hash table
 *   value - item to be placed into the hash table
 * outputs:
 *   opcount - the address of a variable in which the number of operations
 *     will be placed. This is the number of probes required to find an 
 *     open space. With no collisions, this is 1.
 *   return value - 1 if successful, 0 if unsuccessful due to full table.
 */
int insert_linear(hash_table_t *ht, void *value, int *opcount);

/* search_linear
 *  search function that uses linear probing
 * inputs:
 *   ht - hash table
 *   value - item to be found in the hash table
 * outputs:
 *   opcount - the address of a variable in which the number of operations
 *     will be placed. This is the number of probes required to find an 
 *     open space. With no collisions, this is 1.
 *   return value - a pointer to the item in the hash table
 *     that matches the value passed in
 */
void *search_linear(hash_table_t *ht, void *value, int *opcount);

/* print_hash_table_entries
 *   print all of the hash table entries 
 * inputs:
 *   ht - hash table whose contents will be printed out
 */
void print_hash_table_entries(hash_table_t *ht);

/* insert_from_file
 *   read the contents from a file and places those inside the hash table
 * inputs:
 *   ht - hash table in which to add items
 *   filename - file to read out contents. They are words that are placed
 *      in wordcount structs.
 * outputs:
 *   float - the average number of probes per insert operation
 */
float insert_from_file(hash_table_t *ht, char * filename);

/* insert_from_file
 *   read the contents from a file and places those inside the hash table
 * inputs:
 *   ht - hash table in which to add items
 *   filename - file to read out contents. They are words that are placed
 *      in wordcount structs.
 * outputs:
 *   float - the average number of probes per search operation
 */
float search_from_file(hash_table_t *ht, char * filename);

#endif
