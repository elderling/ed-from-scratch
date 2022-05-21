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

buffer * buffer_new(void);
line * line_new(const char * s);
