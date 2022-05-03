// *************************************************************// 
// io.h                                                         // 
// Reseni DU2-IJC, priklad b                                    // 
// Autor: Lukas Foltyn                                          // 
// Fakulta: VUT - Fakulta informacnich technologii              // 
// Posledni zmena:26.3.2020                                     // 
// Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0         // 
// *************************************************************//

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STR_SIZE 128
#define FULL_BUFFER 49
#define RESET 0

int get_word(char *s, int max, FILE *f);

