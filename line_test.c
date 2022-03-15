#include <stdlib.h>
#include <stdio.h>
#include "line.h"

char test_new_line(void);

int main (void) {
    printf("Starting tests.\n");

    if ( test_new_line() ) {
        printf("test_new_line() pass\n");
    } 
    else {
        printf("test_new_line() fail\n");
    }

    return 0;
}

char test_new_line(void) {
    line * a_line;

    char * a_string = "Test string";

    a_line = new_line(a_string);

    if (a_line->the_string != a_string) {
        return 0;
    }

    if (a_line->next_line != NULL) {
      return 0;
    }

    return 1;
}
