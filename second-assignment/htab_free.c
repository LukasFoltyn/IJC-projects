// *************************************************************// 
// htab_free.c                                                  // 
// Reseni DU2-IJC, priklad b                                    // 
// Autor: Lukas Foltyn                                          // 
// Fakulta: VUT - Fakulta informacnich technologii              // 
// Posledni zmena:26.3.2020                                     // 
// Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0         // 
// *************************************************************//

#include "lib_htab.h"

void htab_free(htab_t * t)
{
    htab_clear(t);
    free(t);
    t=NULL;
}
