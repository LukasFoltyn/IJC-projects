// *************************************************************//
// eratosthenes.c						                        //
// Reseni DU1-IJC, priklad a,b					                //
// Autor: Lukas Foltyn						                    //
// Fakulta: VUT - Fakulta informacnich technologii		        //
// Polsedni zmena: 4.3.2020					                    //
// Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0		    //
// *************************************************************//


#include <math.h>
#include "bitset.h"

void Eratosthenes(bitset_t bit_array)
{
	bitset_index_t i = FIRST_PRIME; 
	for(bitset_index_t j = i*i; j < bitset_size(bit_array); j += i)//vyskrtani vsech nasobku dvojky
	{
	    bitset_setbit(bit_array, j, 1);
	}
	i++;
	while(i < sqrt(bitset_size(bit_array)))
	{	
					
		if(bitset_getbit(bit_array,i) == 0)
		{
			for(bitset_index_t j = i*i; j < bitset_size(bit_array); j += i<<1)//vyskrtani lichych cisel, ktere nejsou prvocisla
			{
				bitset_setbit(bit_array, j, 1);
			}
		}
		i += 2;	
	}
}
	
