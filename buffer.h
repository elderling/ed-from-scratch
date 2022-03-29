
struct buffer;
typedef struct buffer buffer;
struct line;
typedef struct line line;

buffer * new_buffer( void );
line * buff_get_head( buffer * b );
line * buff_get_tail( buffer * b );
unsigned int buff_get_length( buffer * b );
buffer * buff_append_line( buffer * b, const char * s );
line * new_line( const char * s );
line * set_string(line * l, const char * s);
char * get_string(line * l);
line * set_next( line * l, line * n);
line * get_next( line * l);
line * set_prev( line * l, line * p);
line * get_prev( line * l);
unsigned int count_children(line * l);
unsigned int count_ancestors(line * l);
unsigned int list_size(line * l);
void delete_line( line * l);
void insert_after (line * l, line * il);
line * get_nth(line * l, unsigned int n);
