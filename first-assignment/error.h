// *************************************************************//
// error.h							                            //
// Reseni DU1-IJC, priklad a,b					                //
// Autor: Lukas Foltyn						                    //
// Fakulta: VUT - Fakulta informacnich technologii		        //
// Polsedni zmena: 4.3.2020					                    //
// Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0		    //
// *************************************************************//


#include <stdarg.h>
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int print_msg(const char *fmt, va_list list);

void warning_msg(const char *fmt, ...);

void error_exit(const char *fmt, ...);


