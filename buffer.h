struct buffer;
typedef struct buffer buffer;
struct line;
typedef struct line line;

buffer * new_buffer(void);
line * new_line(const char * s);
