
struct buffer;
typedef struct buffer buffer;
struct line;
typedef struct line line;

buffer * new_buffer(void);
line * buff_get_head(buffer * b);
line * buff_get_tail(buffer * b);
buffer * buff_append_string(buffer * b, const char * s);
line * new_line(const char * s);
line * set_string(line * l, const char * s);
line * set_next(line * l, line * n);
line * get_next(line * l);
line * set_prev(line * l, line * p);
line * get_prev(line * l);
