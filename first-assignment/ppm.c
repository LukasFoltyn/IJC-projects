// *************************************************************//
// ppm.c							                            //
// Reseni DU1-IJC, priklad b					                //
// Autor: Lukas Foltyn						                    //
// Fakulta: VUT - Fakulta informacnich technologii		        //
// Polsedni zmena: 4.3.2020					                    //
// Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0		    //
// *************************************************************//

#include "ppm.h"
#include "error.h"
#include "bitset.h"
#define DATA_SIZE 3*loaded_data->xsize*loaded_data->ysize


struct ppm * ppm_read(const char * filename)
{
	unsigned color = 0;
	unsigned xsize;
	unsigned ysize;
	FILE*fp;
	fp = fopen(filename, "r");
	if(fp != NULL)
	{		
		if((fscanf(fp, "P6 %u %u %u\n", &xsize, &ysize, &color) != 3) || (color != COLOR_VALUES) )//testing file format
		{
		    fclose(fp);
			warning_msg("The format of a file does not match with the description!\n");
			return NULL;
		}

		if(3*xsize*ysize <= LIMIT && xsize > 0 && ysize > 0)//testing the file size being above limit
		{
			struct ppm *loaded_data = malloc(sizeof(struct ppm)+3*xsize*ysize*sizeof(char));
			if(loaded_data != NULL)
			{	
                //unsigned loaded_chars;
				int curr_char;
				loaded_data->xsize = xsize;
				loaded_data->ysize = ysize;
                //loads the data to structer and checks if the data size matches the given format, then check for EOF
                if((fread(loaded_data->data,sizeof(char),DATA_SIZE , fp)) != DATA_SIZE || (curr_char = fgetc(fp)) != EOF)
				{
					warning_msg("Number of chars does not match with given format\n");
					fclose(fp);
					ppm_free(loaded_data);
					return NULL;	
				}
				fclose(fp);
				return loaded_data;
			}
			else
			{
				fclose(fp);
				warning_msg("Allocation failed.\n");
				return NULL;
			}
		}	
		else
		{	
			fclose(fp);
			warning_msg("The picture format is invalid!\n");
			return NULL;
		}
	}	
	else
	{
		warning_msg("File opening failed.\n");
		return NULL;
	}	
}

int ppm_write(struct ppm *loaded_data, char *filename)
{
	FILE*fp;
	fp = fopen(filename, "w");
	if(!fp)
		return 0;	
	fprintf(fp,"P6\n%u %u\n255\n", loaded_data->xsize, loaded_data->ysize);
    if(fwrite(loaded_data->data, sizeof(char), DATA_SIZE, fp) != DATA_SIZE)
    {
        fclose(fp);
        return 0;
    }   
    fclose(fp);
	return 1;
}

void ppm_free(struct ppm *p)
{
	free(p);
}

