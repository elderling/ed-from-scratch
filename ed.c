#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <stddef.h>
#define MAX_INPUT_LINE_LENGTH 88
void read_file( void );
void print_all_nodes( void );
char user_input[MAX_INPUT_LINE_LENGTH];

char input_line[255];
typedef struct line_node {
    char * the_line;
    struct line_node * next_node;
    struct line_node * previous_node;
} line_node;

line_node * first_node;
line_node * current_node;
line_node * new_node;
unsigned int first_address, second_address;
char command;
void parse_input( void );
void parse_input( void )
{
}
void read_file( void )
{
    FILE * the_file;
    char * new_line;
    first_node = NULL;
    current_node = NULL;
    the_file = fopen("ed.c", "r");
    while( fgets( input_line, 255, the_file) != NULL )  {
        new_line = (char *)malloc( 1 + strlen(input_line) );
        strcpy(new_line, input_line);
        new_node = (line_node *) malloc( sizeof(line_node) );
        new_node->the_line = new_line;
        new_node->next_node = NULL;
        new_node->previous_node = NULL;
        if ( first_node == NULL ) {
            first_node = new_node;
            current_node = first_node;
            continue;
        }
        current_node->next_node = new_node;
        new_node->previous_node = current_node;
        current_node = new_node;
    }
    fclose(the_file);
}
void print_all_nodes( void )
{
    current_node = first_node;
    while ( current_node != NULL ) {
        printf("%s", current_node->the_line);
        current_node = current_node->next_node;
    }
}
void main( void )
{
    /*
        while(1) {
            fgets(user_input, sizeof(user_input), stdin);
            printf("%lu,%s", sizeof(user_input), user_input);
        }
    */
    read_file();
    print_all_nodes();
}
