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

uint8_t * buffer_get( buffer * b, uint16_t n )
{
    line * l;
    uint16_t i;

    if ( n >= b->length ) return NULL;

    l = b->head;
    for (i=0; i < n; i++) {
        l = l->next;
    }

    return l->string;
}

void buffer_delete(buffer * buff, uint16_t index)
{
    line * current;
    uint16_t i;

    if ( index >= buff->length ) return;

    current = buff->head;
    for (i=0; i < index; i++) {
        current = current->next;
    }

    if ( current == buff->head && current == buff->tail ) {
        buff->head = NULL;
        buff->tail = NULL;
    } else if ( current == buff->head ) {
        buff->head = current->next;
        current->next->prev = NULL;
    } else if ( current == buff->tail ) {
        buff->tail = current->prev;
        current->prev->next = NULL;
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    free(current->string);
    free(current);
    buff->length--;

    return;
}

void buffer_insert(buffer * buff, uint16_t index, const uint8_t * str)
{
    line * current;
    line * new_line;
    uint16_t i;

    // invalid index
    if ( index > buff->length ) return;

    // empty buffer or end of buffer
    if ( buff->length == 0 || index == buff->length ) {
        buffer_append(buff, str);
        return;
    }

    new_line = line_new( str );

    // before any existing element
    current = buff->head;
    for (i=0; i < index; i++) {
        current = current->next;
    }

    if ( current == buff->head ) {
        new_line->next = buff->head;
        buff->head->prev = new_line;
        buff->head = new_line;
    } else {
        new_line->next = current;
        new_line->prev = current->prev;
        current->prev->next = new_line;
        current->prev = new_line;
    }

    buff->length++;

    return;
}

#ifdef DEBUG
void buffer_debug_print( buffer * buff )
{
    uint16_t i;
    line * current;

    if(buff->length == 0 ) {
        printf("%s\n", "NULL");
        return;
    }

    if(buff->length == 1 ) {
        printf("%s\n", buffer_get(buff, 0));
        return;
    }

    current = buff->head;
    do {
        printf("%s\n", current->string);
        current = current->next;
    } while (current != NULL);

    return;
}
#endif
