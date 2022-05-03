// *************************************************************//
// primes.c						                            	//
// Reseni DU1-IJC, priklad a					                //
// Autor: Lukas Foltyn						                    //
// Fakulta: VUT - Fakulta informacnich technologii		        //
// Polsedni zmena: 4.3.2020					                    //
// Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0		    //
// *************************************************************//


#include <time.h>
#include "bitset.h"

int main()
{
	clock_t start;
	start = clock();

	bitset_create(bit_array, 500000001);
	Eratosthenes(bit_array);
	bitset_index_t primes[10] = {0};
	short int prime_count = 0;
	bitset_index_t size = bitset_size(bit_array)-1;
	while(prime_count < 10)//nacitani poslednich deseti prvocisel od konce
	{
		if(bitset_getbit(bit_array, size) == 0)
		{	
			primes[prime_count] = size;
			prime_count++;
		}
		size--;
	}
	prime_count--;
	while(prime_count >= 0)
	{
		printf("%lu\n", primes[prime_count]);
		prime_count--;
	}	
	fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
	return 0;
}
