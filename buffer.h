
struct buffer;
typedef struct buffer buffer;
struct line;
typedef struct line line;

buffer * new_buffer(void);
line * buff_get_head(buffer * b);
line * buff_get_tail(buffer * b);
buffer * buff_append_string(buffer * b, const char * s);
line * new_line(const char * s);
