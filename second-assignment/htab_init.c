// *************************************************************// 
// htab_init.c                                                  // 
// Reseni DU2-IJC, priklad b                                    // 
// Autor: Lukas Foltyn                                          // 
// Fakulta: VUT - Fakulta informacnich technologii              // 
// Posledni zmena:26.3.2020                                     // 
// Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0         // 
// *************************************************************//

#include "lib_htab.h"

htab_t *htab_init(size_t n)
{
    htab_t *new_table;
    new_table = malloc(2*sizeof(unsigned)+n*sizeof(struct htab_item*));
    if(new_table)
    {
        new_table->size=0;
        new_table->arr_size=n;
        return new_table;
    }
    return NULL;    
}


