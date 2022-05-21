typedef struct line {
    char * string;
    struct line * prev;
    struct line * next;
} line;

typedef struct buffer {
    line * head;
    line * tail;
    unsigned int length;
} buffer;

buffer * new_buffer(void);
line * new_line(const char * s);
