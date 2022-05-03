// *************************************************************// 
// htab_create_item.c                                           // 
// Reseni DU2-IJC, priklad b                                    // 
// Autor: Lukas Foltyn                                          // 
// Fakulta: VUT - Fakulta informacnich technologii              // 
// Posledni zmena:26.3.2020                                     // 
// Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0         // 
// *************************************************************//

#include "lib_htab.h"

struct htab_item *create_item(htab_key_t key)
{
    struct htab_item *new = malloc(sizeof(struct htab_item));
    if(new == NULL)
        return NULL;
    new->next=NULL;
    new->data=0;
    new->key = malloc(strlen(key)+1);
    if(new->key == NULL)
        return NULL;
    strcpy((char*)new->key, key);
    return new;
}


