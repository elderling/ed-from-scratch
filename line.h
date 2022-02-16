
typedef struct _line {
    char * the_string;
    struct line * next_line;
} line;

line * new_line ( char * the_string );