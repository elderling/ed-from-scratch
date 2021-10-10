#include <stdio.h>
#define MAX_INPUT_LINE_LENGTH 88
char command[MAX_INPUT_LINE_LENGTH];

void main( void )
{
    while(1)
    {
        fgets(command, sizeof(command), stdin);
        printf("?\n");
    }
}
