#include <stdlib.h>
#include <string.h>
#include "buffer.h"

buffer * buffer_new(void)
{
    buffer * nb;

    nb = malloc(sizeof(buffer));

    nb->head = NULL;
    nb->tail = NULL;
    nb->length = 0;

    return nb;
}

line * line_new(const uint8_t * s)
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

void buffer_append( buffer * b, const uint8_t * s)
{
  line * l;

  l = line_new(s);

  if ( b->tail == NULL ) {
    b->head = l;
    b->tail = l;
  } else {
    l->prev = b->tail;
    b->tail->next = l;
    b->tail = l;
  }

  b->length++;

  return;
}
