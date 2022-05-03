// *************************************************************//
// error.c							                            //
// Reseni DU1-IJC, priklad a,b					                //
// Autor: Lukas Foltyn						                    //
// Fakulta: VUT - Fakulta informacnich technologii		        //
// Polsedni zmena: 4.3.2020					                    //
// Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0		    //
// Variadicke funkce						                    //
// *************************************************************//

#include "error.h"


int print_msg(const char *fmt, va_list list)
{
	char *modified_report = NULL;
	if(asprintf(&modified_report,"%s %s","CHYBA:", fmt) != -1)
	{
		vfprintf(stderr, modified_report, list);
		free(modified_report);
		return 1;
	}
	return 0;
}

void warning_msg(const char *fmt, ...)
{
	va_list list;	
	va_start(list, fmt);
	if(!print_msg(fmt, list))
	{
		fprintf(stderr,"Allocation problem occured!\n");
		va_end(list);
		exit(1);
	}
	va_end(list);

}

void error_exit(const char *fmt, ...)
{
	va_list list;
	va_start(list, fmt);
	if(!print_msg(fmt, list))
		fprintf(stderr,"Allocation problem occured!\n");
	va_end(list);
	exit(1);
}


