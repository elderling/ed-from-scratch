
struct buffer;
typedef struct buffer buffer;
struct line;
typedef struct line line;

buffer * new_buffer( void );
line * get_head( buffer * b );
line * new_line( const char * s );
line * set_string(line * l, const char * s);
char * get_string(line * l);
line * set_next( line * l, line * n);
line * get_next( line * l);
line * set_prev( line * l, line * p);
line * get_prev( line * l);
