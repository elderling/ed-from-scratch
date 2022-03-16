
struct line {
    char * the_string;
    struct line * next_line;
};

typedef struct line line;

line * new_line( char * the_string );
line * append_line( line * the_line, char * the_string);
