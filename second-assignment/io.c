// *************************************************************// 
// io.c                                                         // 
// Reseni DU2-IJC, priklad b                                    // 
// Autor: Lukas Foltyn                                          // 
// Fakulta: VUT - Fakulta informacnich technologii              // 
// Posledni zmena:26.3.2020                                     // 
// Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0         // 
// *************************************************************//

#include "io.h"

int get_word(char *s, int max, FILE *f)
{
    int current_char;
    unsigned char_count=0;

    if(fscanf(f==NULL? stdin : f,"%127s", s) != 1)
        return EOF;
    while(!isspace(current_char = fgetc(f == NULL ? stdin : f)))
        char_count++; //counting for fgetc
    return strlen(s)+char_count;
}

