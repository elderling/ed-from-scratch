#include <stdint.h>

#ifdef DEBUG
#include <stdio.h>
#endif

typedef struct line {
    char * string;
    struct line * prev;
    struct line * next;
} line;

typedef struct buffer {
    line * head;
    line * tail;
    uint16_t length;
} buffer;

buffer * buffer_new(void);
line * line_new(const uint8_t * s);
void buffer_append( buffer * b, const uint8_t * s);
uint8_t * buffer_get( buffer * b, uint16_t n );
void buffer_delete(buffer * b, uint16_t n);
void buffer_insert(buffer * buff, uint16_t index, const uint8_t * str);

#ifdef DEBUG
void buffer_debug_print( buffer * buff );
#endif
