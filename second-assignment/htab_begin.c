// *************************************************************// 
// htab_begin.c                                                 // 
// Reseni DU2-IJC, priklad b                                    // 
// Autor: Lukas Foltyn                                          // 
// Fakulta: VUT - Fakulta informacnich technologii              // 
// Posledni zmena:26.3.2020                                     // 
// Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0         // 
// *************************************************************//
#include "lib_htab.h"

htab_iterator_t htab_begin(const htab_t * t)
{
    if(!t->size)
    {
        return htab_end(t);
    }
    htab_iterator_t item;
    for(unsigned i=0; i< t->arr_size; i++)
    {
        if(t->ptr[i] != NULL)
        {
            item.t = t;
            item.idx = i;
            item.ptr = t->ptr[i];
            return item;
        }
    }
}


