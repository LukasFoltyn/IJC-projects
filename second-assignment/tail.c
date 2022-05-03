// *************************************************************//
// tail.c       						                        //
// Reseni DU2-IJC, priklad a					                //
// Autor: Lukas Foltyn						                    //
// Fakulta: VUT - Fakulta informacnich technologii		        //
// Posledni zmena:19.4.2020					                    //
// Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0		    //
// *************************************************************//

#include "tail.h"

int main(int argc, char **argv)
{   
    int result_of_alloc=0;
    char **strings = NULL;    
    unsigned int starting_index=0; 
    char *no_num_part=NULL;
    long int num_lines=0;
    int error_long=0; 
    
    if (argc == LINES_ARG || argc == MAX_ARGS)
    {   
        if(!strcmp(argv[GIVEN_LINES],"0"))
            return 0;
        num_lines = strtol(argv[GIVEN_LINES], &no_num_part,10);
        if (strcmp(argv[SPEC_LINES], "-n") || num_lines < 0 || strcmp (no_num_part,""))
            goto ERROR_END;
    }
     
    switch(argc)
    {
        case MAX_ARGS:
            if(argv[GIVEN_LINES][FIRST_CHAR] == '+')
            {
                if((error_long = addition_sign_file(argv[FILENAME_SPEC_LINES], num_lines)) == ERROR)
                    goto ERROR_END;
            }
            else
            {   
                if((error_long=tail_fseek_version(argv[FILENAME_SPEC_LINES], num_lines)) == ERROR)
                    goto ERROR_END;
            }
            break; 
        case LINES_ARG:
            if(argv[GIVEN_LINES][FIRST_CHAR] == '+')
            {
                if((error_long=addition_sign_stdin(num_lines)) == ERROR)
                    goto ERROR_END;    
            }
            else
            {
                if(!(result_of_alloc=alloc_for_strings(&strings, num_lines)) && (error_long=get_n_lines(argv[FILENAME_SPEC_LINES], num_lines, &starting_index, strings)) != ERROR)
                { 
                    print_n_lines(strings, num_lines, starting_index);
                    free_strings(&strings, num_lines);
                }
                else
                {   
                    if(result_of_alloc)
                        free_strings(&strings, num_lines);
                    goto ERROR_END;
                }
            }
            break;
        case FILE_ARG:
            if((error_long=tail_fseek_version(argv[FILENAME], DEFAULT_LINES)) == ERROR)
                goto ERROR_END;
            break;
        case NO_ARG:
            if(!(result_of_alloc=alloc_for_strings(&strings, DEFAULT_LINES)) && (error_long=get_n_lines(argv[FILENAME], DEFAULT_LINES, &starting_index, strings)) != ERROR)
            {       
                print_n_lines(strings, DEFAULT_LINES, starting_index);
                free_strings(&strings, DEFAULT_LINES);
            }
            else
            {   
                if(result_of_alloc)
                    free_strings(&strings, DEFAULT_LINES);
                goto ERROR_END;
            }
            break;
        default:
            goto ERROR_END;
    }
    if(error_long)
        return 1;
    else        
        return 0;
    
    ERROR_END:
        fprintf(stderr, "Reading failed.\n");
        return 2;                
}


int alloc_for_strings(char ***strings, long int n_lines)
{
    *strings = calloc(n_lines, sizeof(char*));
    if(*strings != NULL)
        return 0;
    return ERROR;
}

void free_strings(char ***string, long int n_lines)
{
    if(*string == NULL)
        return;
    for(unsigned i=0; i<n_lines && (*string)[i] != NULL ;i++)
    {
        if((*string)[i] != NULL)    
            free((*string)[i]);
        (*string)[i] = NULL;
    }
    free(*string);
    *string = NULL;
}

int get_n_lines(char *filename, long int n_lines, unsigned int *starting_index, char **strings)
{
    bool first_error=false;
    char buffer[STR_MAX_SIZE];
    FILE *file_p;
    if(filename)
    { 
        file_p = fopen(filename, "r");
        if(file_p == NULL)
            return ERROR;
    }
    else
        file_p = NULL;
    while(fgets(buffer, STR_MAX_SIZE, filename == NULL ? stdin : file_p) != NULL)
    {   
        if(check_modify_string(buffer, file_p) > STR_MAX_SIZE-1 && !first_error) 
        {
            fprintf(stderr,"Input contains string of invalid lenght\n");
            first_error=true;    
        }
        if(strings[*starting_index] != NULL)
            free(strings[*starting_index]);
        strings[*starting_index] = malloc((strlen(buffer)+1));
        if(strings[*starting_index]==NULL)
        {
            if(filename)
                fclose(file_p);
            return ERROR;
        }
        strcpy(strings[*starting_index], buffer);
        (*starting_index)++;
        if(*starting_index == n_lines)
            *starting_index=0;
    }
    if(filename)
        fclose(file_p);
    if(first_error)
        return INVALID_LENGHT;
    return 0;    
}
int check_modify_string(char *buffer, FILE *file_p)
{
    char help_buffer[LOAD_EOL];
    unsigned lenght = 0;
    if(buffer[strlen(buffer)-1] != '\n')
    {   
        buffer[strlen(buffer)-1] = '\n';
        while(fgets(help_buffer, LOAD_EOL, file_p == NULL ? stdin : file_p) != NULL)
        {  
            lenght = + strlen(help_buffer);
            if(help_buffer[strlen(help_buffer)-1] == '\n')
                return lenght+strlen(buffer);
        }
    }
    return strlen(buffer);
}

void print_n_lines(char **strings_to_print, long int n_lines, unsigned int starting_index)
{
    if(strings_to_print[n_lines-1] != NULL)
    {
        for(unsigned temp = starting_index; temp < n_lines; temp++)
            printf("%s", strings_to_print[temp]);
        
        for(unsigned i=0; i<starting_index; i++)
            printf("%s", strings_to_print[i]);        
    }
    else
    {    
        for(unsigned i=0; strings_to_print[i] != NULL; i++)
        {
            printf("%s", strings_to_print[i]);
        }
    }
}

int tail_fseek_version(char *filename, long int n_lines)
{
    bool first_error=false;
    int loop;
    char buffer[STR_MAX_SIZE];
    int current_char;
    FILE *file_p;
    if(filename)
    {   
        file_p = fopen(filename, "r");
        if(file_p == NULL) 
            return ERROR;
    }
    else
        file_p = NULL;
    if(fseek(filename == NULL ? stdin : file_p , 0, SEEK_END))
        return 0;
    for(unsigned count=0;count<n_lines;count++) 
    {     
        while(!(loop = fseek(filename == NULL ? stdin : file_p , -2, SEEK_CUR)) && (current_char = fgetc(filename == NULL? stdin : file_p)) != '\n');
        if(loop)
        {   
            fseek(filename == NULL ? stdin : file_p , -1, SEEK_CUR);
            break;
        }
    }  
    while(fgets(buffer, STR_MAX_SIZE, filename == NULL ? stdin : file_p) != NULL)
    {   
        if(check_modify_string(buffer, file_p) > STR_MAX_SIZE-1 && !first_error)
        {
            fprintf(stderr,"File contains string of invalid lenght\n");
            first_error=true;    
        }

        printf("%s", buffer);
    }
    if(filename)
        fclose(file_p);
    if(first_error)
        return INVALID_LENGHT;
    return 0;
}

int add_string(l_list **head, char *buffer)
{
    l_list *new = malloc(sizeof(struct linked_list));
    if(new == NULL)
        return ERROR;
    new->next = NULL;
    new->string = malloc(strlen(buffer)+1);
    if(new->string == NULL)
        return ERROR;
    strcpy(new->string,buffer);
    if(*head == NULL)
        *head = new;
    else
    {    l_list *temp = *head;
         while(temp->next != NULL)
            temp=temp->next;
        temp->next=new;
    }
    return 0;
}

void cleanup_linked_list(l_list **head)
{
    if(*head == NULL)
        return;  
    l_list *temp; 
    while(*head != NULL)
    {   
        temp  = *head;
        *head = (*head)->next;
        if(temp->string != NULL)
            free(temp->string);
        free(temp);
    }
}

void print_linked_list(l_list **head)
{
    l_list *temp = *head;
    while(temp != NULL)
    {
        printf("%s", temp->string);
        temp=temp->next;
    }
}

int addition_sign_stdin(long int n_lines)
{ 
    bool first_error=false; 
    l_list *head = NULL;
    char buffer[STR_MAX_SIZE];
    while(fgets(buffer, STR_MAX_SIZE, stdin) != NULL)
    { 
        if(check_modify_string(buffer, NULL) > STR_MAX_SIZE-1 && n_lines < 2 && !first_error)
        {
            fprintf(stderr,"Input contains string of invalid lenght\n");
            first_error=true;    
        }
        if(n_lines<2)
        {   
            if(add_string(&head, buffer) == ERROR)
            {
                cleanup_linked_list(&head);    
                return ERROR;
            }
        }
        n_lines--;
    }
    print_linked_list(&head);
    cleanup_linked_list(&head);
    if(first_error)
        return INVALID_LENGHT;
    return 0;
}

int addition_sign_file(char *filename,long int n_lines)
{
    bool first_error=false; 
    char buffer[STR_MAX_SIZE];
    FILE*file_p;
    file_p = fopen(filename, "r");
    if(file_p == NULL)
        return ERROR;
    while(fgets(buffer, STR_MAX_SIZE, file_p) != NULL)
    {    
        if(check_modify_string(buffer, file_p) > STR_MAX_SIZE-1 && n_lines < 2 && !first_error)
        {
            fprintf(stderr,"File contains string of invalid lenght\n");
            first_error=true;    
        }
        if(n_lines < 2) //tail leaves out lines if the number is higher than 1 
            printf("%s", buffer);

        n_lines--;

    }
    fclose(file_p);
    if(first_error)
        return INVALID_LENGHT;
    return 0;

}
