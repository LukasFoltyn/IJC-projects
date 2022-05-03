// *************************************************************//
// steg-encode.c						                        //
// Reseni DU1-IJC, priklad b					                //
// Autor: Lukas Foltyn						                    //
// Fakulta: VUT - Fakulta informacnich technologii		        //
// Polsedni zmena: 5.3.2020					                    //
// Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0		    //
// *************************************************************//
#include "error.h"
#include "bitset.h"
#include "ppm.h"


int main(int argc, char **argv)
{
	if(argc != NEEDED_ARGS)
		error_exit("Two arguments are needed.\n");
	struct ppm* picture = ppm_read(argv[FILENAME]);
	if(picture == NULL)
		error_exit("Loading of picture failed.\n");
	
	bitset_alloc(bit_array, 3*picture->xsize*picture->ysize);
	Eratosthenes(bit_array);
	
	short unsigned bits = 0;
	int letters[2] = {8,0};
	int letter_temp;
	unsigned i = 23;
	letters[1] = getchar();
	while((letter_temp =getchar()) != EOF)		
	{
		bits = 0;
		for(; i < bitset_size(bit_array) && bits < CHAR_BIT;i++)
		{
			if(!(bitset_getbit(bit_array,i)))
			{	
				if(bitset_getbit(letters, bits))
					picture->data[i] |= 1;
				else
					picture->data[i] &= ~1;
				bits++;
			}
		}
		if(i == bitset_size(bit_array) && bits != CHAR_BIT)
		{	
			ppm_free(picture);
			error_exit("Message for encoding is way too long for the picture of this format!\n");
		}
		letters[1] = letter_temp;
	}
	bits=0; 
	for(;i < bitset_size(bit_array) && bits < CHAR_BIT;i++)
	{
		if(!(bitset_getbit(bit_array,i)))
		{
			picture->data[i] &= ~1;
			bits++;
		}
	}
	bitset_free(bit_array);
	if(bits != CHAR_BIT)
	{	
		ppm_free(picture);
		error_exit("Message for encoding is way too long for the picture of this format!\n");
	}
	if(!(ppm_write(picture,argv[FILENAME])))
	{	
		ppm_free(picture);
		error_exit("Unbale to enocde the message.\n");
	}
	ppm_free(picture);
	return 0;
		
}
