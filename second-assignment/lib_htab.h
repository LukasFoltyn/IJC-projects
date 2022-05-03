// *************************************************************// 
// lib_htab.h                                                   // 
// Reseni DU2-IJC, priklad b                                    // 
// Autor: Lukas Foltyn                                          // 
// Fakulta: VUT - Fakulta informacnich technologii              // 
// Posledni zmena:26.3.2020                                     // 
// Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0         // 
// *************************************************************//

#ifndef __LIB_HTAB_H__
#define __LIB_HTAB_H__

#include <stdlib.h>
#include <stdio.h>
#include "htab.h"

struct htab_item {
    htab_key_t key;
    htab_value_t data;
    struct htab_item *next;
};

struct htab {
    unsigned size;
    unsigned arr_size;    
    struct htab_item *ptr[];
    };

#endif // __LIB_HTAB_H__



