#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#define MAX_INPUT_LINE_LENGTH 88
char command[MAX_INPUT_LINE_LENGTH];

typedef struct line {
    char the_line[1];
    struct line * next_line;
    struct line * previous_line;
} line;


void main( void )
{
FILE * the_file;
char input_line[255];
the_file = fopen("ed.c", "r");
while( fgets( input_line, 255, the_file) != NULL )  {
puts(input_line);
}
fclose(the_file);
    while(1) {
        fgets(command, sizeof(command), stdin);
        printf("?\n");
    }
}
