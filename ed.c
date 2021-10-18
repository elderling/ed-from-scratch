#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <stddef.h>
#define MAX_INPUT_LINE_LENGTH 88
void read_file( void );
char command[MAX_INPUT_LINE_LENGTH];

char input_line[255];
typedef struct line_node {
    char * the_line;
    struct line_node * next_node;
    struct line_node * previous_node;
} line_node;

line_node * first_node;
line_node * current_node;
line_node * new_node;
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
            fgets(command, sizeof(command), stdin);
            printf("%lu,%s", sizeof(command), command);
        }
    */
    read_file();
while (1) { }
}
