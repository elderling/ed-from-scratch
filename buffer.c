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
    line * tail;
    unsigned int length;
};

buffer * new_buffer(void)
{
    buffer * nb;

    nb = malloc(sizeof(buffer));

    nb->head = NULL;
    nb->tail = NULL;
    nb->length = 0;

    return nb;
}

line * buff_get_head(buffer * b)
{
    return b->head;
}

line * buff_get_tail(buffer * b)
{
    return b->tail;
}

buffer * buff_append_string(buffer * b, const char * s)
{
    line * l;

    l = new_line(s);

    if(b->head == NULL) {
        b->head = l;
        b->tail = l;
        b->length = 1;
        return b;
    }

    if(b->head == b->tail) {
        b->tail = l;
        b->tail->prev = b->head;
        b->head->next = l;
        b->length++;
        return b;
    }

    l->prev = b->tail;
    b->tail->next = l;
    b->tail = l;
    b->length++;

    return b;
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

line * get_next(line * l)
{
    return l->next;
}

line * set_prev(line * l, line * p)
{
    l->prev = p;
    p->next = l;
    return l;
}

line * get_prev(line * l)
{
    return l->prev;
}
