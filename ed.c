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
typedef struct line {
    char * the_line;
    struct line * next_line;
    struct line * previous_line;
} line;

line * first_line;
line * current_line;
line * new_node;
void read_file( void )
{
    FILE * the_file;
    char * new_line;
    first_line = NULL;
    current_line = NULL;
    the_file = fopen("ed.c", "r");
    while( fgets( input_line, 255, the_file) != NULL )  {
        new_line = (char *)malloc( 1 + strlen(input_line) );
        strcpy(new_line, input_line);
//        printf("%s", new_line);
        new_node = (line *) malloc( sizeof(line) );
        new_node->the_line = new_line;
	new_node->next_line = NULL;
	new_node->previous_line = NULL;
        if ( first_line == NULL ) {
            first_line = new_node;
            current_line = first_line;
//            printf("%s", first_line->the_line);
            continue;
        }
        current_line->next_line = new_node;
        new_node->previous_line = current_line;
        current_line = new_node;
//        printf("%s", current_line->the_line );
    }
    fclose(the_file);
    current_line = first_line;
//    while ( current_line != NULL ) {
    while ( current_line != 0 ) {
	printf("%d", (unsigned int) current_line);
        printf("%s", current_line->the_line);
        current_line = current_line->next_line;
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
char i;
for ( i = 0; i < 2; i++ ) {
    read_file();
}
while (1) { }
}
