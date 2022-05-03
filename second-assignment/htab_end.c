// *************************************************************// 
// htab_end.c                                                   // 
// Reseni DU2-IJC, priklad b                                    // 
// Autor: Lukas Foltyn                                          // 
// Fakulta: VUT - Fakulta informacnich technologii              // 
// Posledni zmena:26.3.2020                                     // 
// Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0         // 
// *************************************************************//

#include "lib_htab.h"

htab_iterator_t htab_end(const htab_t * t)
{
    htab_iterator_t item = {NULL, t, t->arr_size};
    return item;
}


