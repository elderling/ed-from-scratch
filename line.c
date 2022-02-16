#include <stdlib.h>
#include "line.h"

line * new_line ( char * the_string ) {
    line * the_line;

    the_line = malloc(sizeof(line));

    the_line->the_string = the_string;

    return the_line;
}