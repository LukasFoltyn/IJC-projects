// *************************************************************// 
// htab_find.c                                                  //
// Reseni DU2-IJC, priklad b                                    // 
// Autor: Lukas Foltyn                                          // 
// Fakulta: VUT - Fakulta informacnich technologii              // 
// Posledni zmena:26.3.2020                                     // 
// Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0         // 
// *************************************************************//

#include "lib_htab.h"

htab_iterator_t htab_find(htab_t * t, htab_key_t key)
{
    htab_iterator_t item;
    size_t index = htab_hash_fun(key)%t->arr_size;
    struct htab_item *temp = t->ptr[index];
    while(temp != NULL)
    {
        if(!strcmp(temp->key, key))
        {
            item.t = t;
            item.ptr = temp;
            item.idx=index;
            return item;
        }
        temp = temp->next;
    }
    return htab_end(t);
}



