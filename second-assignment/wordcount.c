// *************************************************************// 
// wordcount.c                                                  // 
// Reseni DU2-IJC, priklad b                                    // 
// Autor: Lukas Foltyn                                          // 
// Fakulta: VUT - Fakulta informacnich technologii              // 
// Posledni zmena:26.3.2020                                     // 
// Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0         // 
// *************************************************************//

#include "htab.h"
#include "io.h"
int main()
{
    bool first_error=false;
    const short unsigned table_size = 2000;
    htab_iterator_t current_item;
    htab_t *word_count_table = htab_init(table_size); /* 2000 slotu by melo byt dostatek, aby se netvorily prilis dlouhe linked listy 
                                                       a dostupnost prvku byla skoro porad instantni(ale zalezi ovsem jak velky je obsah zadaneho souboru)*/ 
    if(!word_count_table)
        goto ERROR_EXIT;
        
    char current_word[MAX_STR_SIZE]={'\0',};
    int word_lenght;

    while((word_lenght = get_word(current_word, MAX_STR_SIZE, NULL)) != EOF)
    {
        if(word_lenght > MAX_STR_SIZE-1 && !first_error)
        {   
            fprintf(stderr, "error: input contains string of invalid lenght.\n");
            first_error=true;
        }
        if(!htab_iterator_valid(current_item = htab_lookup_add(word_count_table,current_word)))
            goto ERROR_DEALLOC_EXIT;
        htab_iterator_set_value(current_item, htab_iterator_get_value(current_item)+1);
    }
   
    for(current_item=htab_begin(word_count_table);!htab_iterator_equal(current_item,htab_end(word_count_table));current_item=htab_iterator_next(current_item))
        printf("%s\t%d\n", htab_iterator_get_key(current_item), htab_iterator_get_value(current_item));
    
    htab_free(word_count_table);
    if(first_error)
        return 1;//exit, invalid lenght
    return 0; //exit success
    
    ERROR_DEALLOC_EXIT:
        htab_free(word_count_table);
    ERROR_EXIT:
        fprintf(stderr,"error: Hash table initialization failed.\n");
        return 2; //exit error 
}

