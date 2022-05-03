// *************************************************************// 
// htab_lookup_add.c                                            // 
// Reseni DU2-IJC, priklad b                                    // 
// Autor: Lukas Foltyn                                          // 
// Fakulta: VUT - Fakulta informacnich technologii              // 
// Posledni zmena:26.3.2020                                     // 
// Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0         // 
// *************************************************************//

#include "lib_htab.h"

htab_iterator_t htab_lookup_add(htab_t * t, htab_key_t key)
{
    htab_iterator_t item = htab_find(t,key);
    if(item.ptr == NULL)
    {
        size_t index = htab_hash_fun(key)%t->arr_size;
        if(t->ptr[index] == NULL)
        {
            if((t->ptr[index] = create_item(key)) == NULL)
                return htab_end(t);
            item.ptr = t->ptr[index];
        }
        else
        {
            struct htab_item *temp=t->ptr[index];
            while(temp->next != NULL)
                temp = temp->next;
            if((temp->next = create_item(key)) == NULL)
                return htab_end(t);
            item.ptr = temp->next; 
        }
        t->size++;       
        item.idx = index;
        return item;
    }
    else
        return item;
   

}

