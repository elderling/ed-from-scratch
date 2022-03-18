#include <stdio.h>
#include "buffer.h"

buffer * buffer1;
line * line1;
char * str1 = "String 1";

void main(void) {
  printf("Beginning tests...\n");

  buffer1 = new_buffer();

  if ( get_head(buffer1) == NULL ) {
    printf("PASS: initialized buffer head correctly");
  } else {
    printf("FAIL: initialized buffer head incorrectly");
  }

}
