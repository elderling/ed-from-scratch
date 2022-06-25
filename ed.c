#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <stddef.h>
#include "ed.h"

char user_input[MAX_INPUT_LINE_LENGTH];

void do_command(char *);

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
}
