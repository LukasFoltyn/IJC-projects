// *************************************************************//
// tail.c       						                        //
// Reseni DU2-IJC, priklad a					                //
// Autor: Lukas Foltyn						                    //
// Fakulta: VUT - Fakulta informacnich technologii		        //
// Posledni zmena:19.4.2020					                    //
// Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0		    //
// *************************************************************//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define INVALID_LENGHT 1
#define ERROR 2
#define FIRST_CHAR 0
#define FILE_ARG 2
#define NO_ARG 1
#define MAX_ARGS 4
#define LINES_ARG 3
#define SPEC_LINES 1
#define GIVEN_LINES 2
#define FILENAME_SPEC_LINES 3
#define FILENAME 1
#define DEFAULT_LINES 10
#define STR_MAX_SIZE 1025
#define LOAD_EOL 200

typedef struct linked_list{
    char *string;
    struct linked_list *next;
    }l_list;

int tail_fseek_version(char *filename, long int n_lines);

int check_modify_string(char *buffer, FILE * file_p);

int addition_sign_file(char *filename,long int n_lines);

int addition_sign_stdin(long int n_lines);

int add_string(l_list **head, char *buffer);

void cleanup_linked_list(l_list **head);

void print_linked_list(l_list **head);

bool is_positive_integer(char *str);

int get_n_lines(char *filename, long int n_lines, unsigned int* starting_index, char **strings);

void print_n_lines(char **strings_to_print, long int n_lines, unsigned int starting_index);

int  alloc_for_strings(char ***strings, long int n_lines);

void free_strings(char ***string, long int n_lines);


