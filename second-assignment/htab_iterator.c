// *************************************************************// 
// htab_iterator.c                                              // 
// Reseni DU2-IJC, priklad b                                    // 
// Autor: Lukas Foltyn                                          // 
// Fakulta: VUT - Fakulta informacnich technologii              // 
// Posledni zmena:26.3.2020                                     // 
// Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0         // 
// *************************************************************//

#include "lib_htab.h"

htab_iterator_t htab_iterator_next(htab_iterator_t it)
{   
    if(it.ptr->next == NULL)   
    {         
        while(++it.idx != it.t->arr_size && (it.ptr=it.t->ptr[it.idx]) == NULL);
        if(it.idx == it.t->arr_size)
            return htab_end(it.t); 
    }
    else
        it.ptr = it.ptr->next;
	
    return it;    
}

