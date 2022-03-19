
struct buffer;
typedef struct buffer buffer;
struct line;
typedef struct line line;

buffer * new_buffer( void );
line * get_head( buffer * b );
line * new_line( char * s );
line * set_string(line * l, char * s);
char * get_string(line * l);
