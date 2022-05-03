// *************************************************************// 
// htab_erase.c                                                 //
// Reseni DU2-IJC, priklad b                                    // 
// Autor: Lukas Foltyn                                          // 
// Fakulta: VUT - Fakulta informacnich technologii              // 
// Posledni zmena:26.3.2020                                     // 
// Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0         // 
// *************************************************************//

#include "lib_htab.h"

void htab_erase(htab_t * t, htab_iterator_t it)
{
    if(it.ptr == NULL)
        return;
    struct htab_item *temp=t->ptr[it.idx];
    struct htab_item *delete= temp;
    if(!strcmp(temp->key, it.ptr->key))
        t->ptr[it.idx] = t->ptr[it.idx]->next;
    else
    { 
        while(temp->next != NULL && strcmp(temp->next->key, it.ptr->key))
                temp = temp->next;
        if(temp->next != NULL)
        {   
            delete = temp->next;
            temp->next=temp->next->next;
        }   
        else
            return;
    }
    
    t->size--;
    free((char*)delete->key);
    delete->key = NULL;
    free(delete);
    
}


