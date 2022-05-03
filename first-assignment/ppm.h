// *************************************************************//
// ppm.h							                            //
// Reseni DU1-IJC, priklad b					                //
// Autor: Lukas Foltyn						                    //
// Fakulta: VUT - Fakulta informacnich technologii		        //
// Polsedni zmena: 4.3.2020					                    //
// Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0		    //
// *************************************************************//



#define LIMIT 192000000
#define FILENAME 1
#define NEEDED_ARGS 2
#define COLOR_VALUES 255


struct ppm {
        unsigned xsize;
        unsigned ysize;
        char data[];   
     };


struct ppm * ppm_read(const char * filename); 

void ppm_free(struct ppm *p);

int ppm_write(struct ppm *picture, char *filename);















