#include <stdint.h>

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
