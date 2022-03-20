#include <stdlib.h>
#include <string.h>
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

line * new_line( const char * s ) {

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

line * set_string( line * l, const char * s) {
  char * ns;
  free(l->string);
  ns = malloc(strlen(s)+1);
  ns = strcpy(ns, s);
  l->string = ns;

  return l;
}

char * get_string( line * l) {
  return l->string;
}

line * set_next( line * l, line * n) {
	l->next = n;
	return l;
}

line * get_next( line * l ) {
	return l->next;
}
