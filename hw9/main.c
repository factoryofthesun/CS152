#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "word.h"
#include "hash.h"

void do_full_test(char *filename, int table_size)
{

        hash_table_t* ht = create_hash_table(table_size, get_key, compare_words);

        printf("=====================================================================\n");
        printf("Test, Filename: %s, Hash Table Size: %d\n",filename, table_size);
        printf("=====================================================================\n");
        float average_insert = insert_from_file(ht, filename);
	print_hash_table_entries(ht); 
        float average_search = search_from_file(ht, filename);
        printf("---------------------------------------------------------------------\n");
        printf("Average Insertion Operations: %f\n", average_insert);
        printf("Average Search Operations: %f\n", average_search);
        printf("---------------------------------------------------------------------\n\n");
}
int main(int argc, char* argv[])
{
    //Uncomment the following to test your code: 

     
    hash_table_t* ht1 = create_hash_table(10, get_key, compare_words);

    printf("Insertion and Search Example\n==================\n");
    wordcount *wc = create_count("uchicago");
    int ops;
    insert_linear(ht1, (void *)wc, &ops);
    printf("insert_linear pass\n"); 
    print_hash_table_entries(ht1);
    search_linear(ht1, (void*)wc, &ops);

    //Uncomment the following line to do full tests, provide filename and hash_table size as arguments:
    do_full_test(argv[1], atoi(argv[2]));
    //Test get_key
	wordcount *w1 = create_count("FORK"); 
	unsigned long int result = get_key(w1); 
	if(result == 129530)
		printf("get_key test pass\n"); 
	else
		printf("get_key test fail - expected: 129530, received: %lu", result);
    return 0;
}




