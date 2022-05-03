// *************************************************************// 
// htab_clear.c                                                 // 
// Reseni DU2-IJC, priklad b                                    // 
// Autor: Lukas Foltyn                                          // 
// Fakulta: VUT - Fakulta informacnich technologii              // 
// Posledni zmena:26.3.2020                                     // 
// Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0         // 
// *************************************************************//

#include "lib_htab.h"

void htab_clear(htab_t * t)
{
    for(unsigned i=0; i < htab_bucket_count(t);i++)
    {
        while(t->ptr[i] != NULL)
        {
            struct htab_item *temp=t->ptr[i];
            t->ptr[i]=t->ptr[i]->next;
            free((char*)temp->key);
            free(temp);
            t->size--;
        }
    }    
}

