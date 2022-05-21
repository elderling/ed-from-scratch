#include <stdlib.h>
#include <string.h>
#include "buffer.h"

buffer * new_buffer(void)
{
    buffer * nb;

    nb = malloc(sizeof(buffer));

    nb->head = NULL;
    nb->tail = NULL;
    nb->length = 0;

    return nb;
}

line * new_line(const char * s)
{
    char * ns;
    line * nl;

    nl = malloc(sizeof(line));
    ns = malloc(strlen(s)+1);

    ns = strcpy(ns, s);

    nl->prev = NULL;
    nl->next = NULL;
    nl->string = ns;

    return nl;
}
