#define MAX_INPUT_LINE_LENGTH 88
#define MAX_FILENAME_LENGTH 16
void read_file( char * filename );
void print_all_nodes( void );
char user_input[MAX_INPUT_LINE_LENGTH];
char filename[MAX_FILENAME_LENGTH];

char input_line[255];
typedef struct line_node {
    char * the_line;
    struct line_node * next_node;
    struct line_node * previous_node;
} line_node;

typedef struct address_range {
    unsigned int start;
    unsigned int end;
} address_range;

void print_range( address_range * range );
line_node * first_node;
line_node * current_node;
line_node * new_node;
unsigned int first_address, second_address;
char command;
void parse_input( void );
void do_command(char *);
