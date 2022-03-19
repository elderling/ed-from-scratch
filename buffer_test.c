#include <stdio.h>
#include <string.h>
#include "buffer.h"

buffer * buffer1;
line * line1;
char * str1 = "String 1";

void main(void) {
  printf("Beginning tests...\n");

  line1 = new_line(str1);
  buffer1 = new_buffer();

  if ( get_head(buffer1) == NULL ) {
    printf("PASS: initialized buffer head correctly\n");
  } else {
    printf("FAIL: initialized buffer head incorrectly\n");
  }

  if ( strcmp( get_string(line1), str1 ) == 0) {
    printf("PASS: initialized line string correctly\n");
  } else {
    printf("FAIL: initialized line string incorrectly\n");
  }

}
