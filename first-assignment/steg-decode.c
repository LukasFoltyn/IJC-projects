// *************************************************************//
// steg-decode.c						                        //
// Reseni DU1-IJC, priklad b					                //
// Autor: Lukas Foltyn						                    //
// Fakulta: VUT - Fakulta informacnich technologii		        //
// Polsedni zmena: 4.3.2020					                    //
// Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0		    //
// *************************************************************//

#include "ppm.h"
#include "error.h"
#include "bitset.h"

int main(int argc, char **argv)
{
	if(argc != NEEDED_ARGS)
		error_exit("Expected two arguments - program/file to read from.\n");
	
	struct ppm *picture = ppm_read(argv[FILENAME]);
	if(picture == NULL)	
		error_exit("Reading from the %s file failed.\n", argv[FILENAME]);	
	
	bitset_alloc(temp_array,3*picture->xsize*picture->ysize);
	Eratosthenes(temp_array);
	
	bool literal_finished = false;
	int decoded_letter[2] = {CHAR_BIT,0};
	unsigned short count = 0;
	
	for(long unsigned i = 23; i < bitset_size(temp_array); i += 2)
	{
		if(bitset_getbit(temp_array, i) == 0)		
		{	
			bitset_setbit(decoded_letter, count, picture->data[i] & 1);
			count++;
		}
		if(count == CHAR_BIT)
		{
			putchar(decoded_letter[1]);

			if(decoded_letter[1] == '\0')
			{	
				literal_finished = true;
				break;
			
			}
			count = 0;
		}

	}
	ppm_free(picture);
	bitset_free(temp_array);
	if(!literal_finished)
		error_exit("Hidden message was not ended properly!\n");	
	
	putchar('\n');

	return 0;	
}
