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
	n->prev = l;
	return l;
}

line * get_next( line * l ) {
	return l->next;
}

line * set_prev( line * l, line * p) {
	l->prev = p;
	p->next = l;
	return l;
}

line * get_prev( line * l ) {
	return l->prev;
}

unsigned int count_children(line * l) {
	unsigned int c = 0;
	line * current;
	current = l;

	while ( get_next(current) != NULL ) {
		c++;
		current = get_next(current);
	}

	return c;
}

unsigned int count_ancestors(line * l) {
	unsigned int c = 0;
	line * current;
	current = l;

	while ( get_prev(current) != NULL ) {
		c++;
		current = get_prev(current);
	}

	return c;
}

unsigned int list_size(line * l) {
	return 1 + count_children(l) + count_ancestors(l);
}

void delete_line(line * l) {
	if ( l->prev != NULL ) {
		l->prev->next = l->next;
	}
	if ( l->next != NULL ) {
		l->next->prev = l->prev;
	}

	free(l->string);
	free(l);

	return;
}

void insert_after (line * l, line * il) {
	if ( l->next != NULL ) l->next->prev = il;

	il->prev = l;
	il->next = l->next;
	l->next = il;
	
	return;
}
