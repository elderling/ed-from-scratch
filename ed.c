#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <stddef.h>
#define MAX_INPUT_LINE_LENGTH 88
char command[MAX_INPUT_LINE_LENGTH];

typedef struct line {
    char the_line[1];
    struct line * next_line;
    struct line * previous_line;
} line;

line * first_line;
line * current_line;
void main( void )
{
FILE * the_file;
char input_line[255];
char * new_line;
first_line = NULL;
current_line = NULL;
the_file = fopen("ed.c", "r");
while( fgets( input_line, 255, the_file) != NULL )  {
  new_line = (char *)malloc( 1 + strlen(input_line) );
  strcpy(new_line, input_line);
puts(new_line);
}
fclose(the_file);
    while(1) {
        fgets(command, sizeof(command), stdin);
        printf("?\n");
    }
}
