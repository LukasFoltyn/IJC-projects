// *************************************************************//
// inline.c							                            //
// Reseni DU1-IJC, priklad a				                	//
// Autor: Lukas Foltyn						                    //
// Fakulta: VUT - Fakulta informacnich technologii		        //
// Polsedni zmena: 10.3.2020				                    //
// Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0		    //
// *************************************************************//


#include "bitset.h"

void bitset_free(bitset_t array_name);
unsigned long bitset_size(bitset_t array_name);
void bitset_setbit(bitset_t array_name,bitset_index_t index,int expression);
bool bitset_getbit(bitset_t array_name, bitset_index_t index);

