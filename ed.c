#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <stddef.h>
#include "ed.h"

void parse_input( void )
{
}

void read_file( char * filename )
{
    FILE * the_file;
    char * new_line;
    first_node = NULL;
    current_node = NULL;
    the_file = fopen(filename, "r");
    while( fgets( input_line, 255, the_file) != NULL )  {
        new_line = (char *)malloc( 1 + strlen(input_line) );
        strcpy(new_line, input_line);
        new_node = (line_node *) malloc( sizeof(line_node) );
        new_node->the_line = new_line;
        new_node->next_node = NULL;
        new_node->previous_node = NULL;
        if ( first_node == NULL ) {
            first_node = new_node;
            current_node = first_node;
            continue;
        }
        current_node->next_node = new_node;
        new_node->previous_node = current_node;
        current_node = new_node;
    }
    fclose(the_file);
}

void print_range( address_range * range )
{
// TODO: error if nothing printed
// TODO: error error if range invalid
//       ( or just prevent that, of course)
    unsigned int node_index;
    char print_node;
    char done;
    print_node = 0;
    done = 0;
    node_index = 1;
    current_node = first_node;
//printf("range->start:%d", range->start);
//printf("range->end:%d", range->end);
    while ( current_node != NULL && node_index <= range->end ) {
        if ( range->start >= node_index ) {
            print_node = 1;
        }
        if ( node_index > range->end || node_index < range->start ) {
            print_node = 0;
        }
//printf("%d", node_index);
//printf("%d", print_node);
        if ( print_node ) {
            printf("%s", current_node->the_line);
        }
        current_node = current_node->next_node;
        node_index++;
    }
}

void print_all_nodes( void )
{
    current_node = first_node;
    while ( current_node != NULL ) {
        printf("%s", current_node->the_line);
        current_node = current_node->next_node;
    }
}

void do_command(char * command) {
  if ( ! (strcmp( command, "q\n" ) == 0) ) {
    printf("%s", "?\n");
  } else {
    exit(0);
  }
}

void main( void )
{
  while(1) {
      fgets(user_input, sizeof(user_input), stdin);
      //printf("%lu,%s", sizeof(user_input), user_input);
      do_command(user_input);
  }
/*
    address_range range;
    range.start = 10;
    range.end = 20;
    strcpy( filename, "ed.c" );
    read_file( filename );
    print_range( &range );
*/
//    print_all_nodes();
}
