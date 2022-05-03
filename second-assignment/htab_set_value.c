// *************************************************************// 
// htab_set_value.c                                             // 
// Reseni DU2-IJC, priklad b                                    // 
// Autor: Lukas Foltyn                                          // 
// Fakulta: VUT - Fakulta informacnich technologii              // 
// Posledni zmena:26.3.2020                                     // 
// Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0         // 
// *************************************************************//

#include "lib_htab.h"

htab_value_t htab_iterator_set_value(htab_iterator_t it, htab_value_t val)
{
    return it.ptr->data = val;
}

