#include <stdlib.h>
#include "buffer.h"

struct line {
    char * string;
    struct line * prev;
    struct line * next;
};

struct buffer {
    line * head;
    line * current;
    unsigned int current_index;
};

buffer * new_buffer( void ) {

  buffer * nb;

  nb = malloc(sizeof(buffer));

  nb->head = NULL;
  nb->current = nb->head;
  nb->current_index = 0;

  return nb;
}

line * get_head( buffer * b ) {
  return b->head;
}

line * new_line( char * s ) {

  line * nl;

  nl = malloc(sizeof(line));

  nl->prev = NULL;
  nl->next = NULL;
  nl->string = s;

  return nl;
}
