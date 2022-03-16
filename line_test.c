#include <stdlib.h>
#include <stdio.h>
#include "line.h"

char * test_string1 = "Test string";

char test_new_line(void);
char test_append_line(void);

int main (void) {
    printf("Starting tests.\n");

    if ( test_new_line() ) {
        printf("test_new_line() pass\n");
    } 
    else {
        printf("test_new_line() fail\n");
    }

    if ( test_append_line() ) {
        printf("test_append_line() pass\n");
    } 
    else {
        printf("test_append_line() fail\n");
    }

    return 0;
}

char test_new_line(void) {
    line * a_line;

    char * a_string = test_string1;

    a_line = new_line(test_string1);

    if (a_line->the_string != a_string) {
        return 0;
    }

    if (a_line->next_line != NULL) {
      return 0;
    }

    return 1;
}

char test_append_line(void) {
    line * the_line;
    line * appended_line;

    the_line = new_line(test_string1);

    appended_line = append_line( the_line, test_string1);

    if ( the_line->next_line != appended_line ) {
      return 0;
    }

    return 1;
}
