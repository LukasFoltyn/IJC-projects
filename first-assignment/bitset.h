// *************************************************************//
// bitset.h                                                     //
// Reseni DU1-IJC, priklad a,b                                  //
// Autor: Lukas Foltyn                                          //
// Fakulta: VUT - Fakulta informacnich technologii              //
// Polsedni zmena: 4.3.2020                                     //
// Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0         //
// Makra a inline funkce, pouziti zavisi na podminenem prekladu //
// *************************************************************//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "error.h"
#define ARRAY_LIMIT 1000000000
#define FIRST_PRIME 2

typedef unsigned long bitset_t[];
typedef unsigned long bitset_index_t;
void Eratosthenes(bitset_t bit_array);

#define bitset_create(array_name, array_size) unsigned long array_name[array_size%(sizeof(unsigned long)<<3) ? (array_size/(sizeof(unsigned long)<<3))+2:\
                          (array_size/(sizeof(unsigned long)<<3))+1]= {array_size,};\
                          static_assert(array_size >= 0, "Array size can not be negative!");

#define bitset_alloc(array_name, array_size) assert(array_size < ARRAY_LIMIT);unsigned long *array_name = calloc(array_size%(sizeof(unsigned long)<<3) ?(array_size/(sizeof(unsigned long)<<3))+2 :\
                         (array_size/(sizeof(unsigned long)<<3))+1, sizeof(unsigned long));\
                         if(array_name == NULL)error_exit("bitset_alloc: Chyba alokace pameti\n"); array_name[0] = array_size;\

#ifndef USE_INLINE
#ifndef MACROS
#define MACROS

#define bitset_free(array_name) do{free(array_name); array_name = NULL;}while(0)

#define bitset_size(array_name) array_name[0]

#define bitset_setbit(array_name,index, expression) index > array_name[0] ? error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n",index, array_name[0]-1),2 :\
                            (expression ? (array_name[index/(sizeof(unsigned long)<<3)+1] |= (1UL << index%(sizeof(unsigned long)<<3))):\
                            (array_name[index/(sizeof(unsigned long)<<3)+1] &= ~(1UL << index%(sizeof(unsigned long)<<3))));

#define bitset_getbit(array_name, index) index > array_name[0] ? error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n",index, array_name[0]-1),2 :\
                     (array_name[index/(sizeof(unsigned long)<<3)+1] & (1UL << index%(sizeof(unsigned long)<<3)) ? 1 : 0)


#endif
#else

inline void bitset_free(bitset_t array_name)
{
    free(array_name); 
    array_name = NULL;
}

inline unsigned long bitset_size(bitset_t array_name)
{
    return array_name[0];
}

inline void bitset_setbit(bitset_t array_name,bitset_index_t index,int expression)
{
    index > array_name[0] ? error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n",index, array_name[0]-1),2 :
    (expression ? (array_name[index/(sizeof(unsigned long)<<3)+1] |= (1UL << index%(sizeof(unsigned long)<<3))):
    (array_name[index/(sizeof(unsigned long)<<3)+1] &= ~(1UL << index%(sizeof(unsigned long)<<3))));
}

inline bool bitset_getbit(bitset_t array_name, bitset_index_t index)
{
    return index > array_name[0] ? error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n",index, array_name[0]-1),2 :
    (array_name[index/(sizeof(unsigned long)<<3)+1] & (1UL << index%(sizeof(unsigned long)<<3)) ? 1 : 0);
}

#endif
