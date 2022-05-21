#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "buffer.h"
#include "Unity/src/unity.h"

void test_line_new( void );
void test_buffer_new( void );
void test_buffer_append( void );

void setUp(void)
{
    return;
}

void tearDown(void)
{
    return;
}

void test_line_new( void )
{
  line * l;

  l = line_new("test line new");

  TEST_ASSERT_EQUAL_STRING("test line new", l->string);
  TEST_ASSERT_NULL(l->next);
  TEST_ASSERT_NULL(l->prev);
}

void test_buffer_new( void )
{
  buffer * b;

  b = buffer_new();

  TEST_ASSERT_NULL(b->head);
  TEST_ASSERT_NULL(b->tail);
  TEST_ASSERT_EQUAL_UINT16(b->length, 0);
}

void test_buffer_append( void )
{
  buffer * b;
  line * cursor;

  b = buffer_new();

  buffer_append( b, "first line" );
  TEST_ASSERT_EQUAL_UINT16(1, b->length);
  buffer_append( b, "second line" );
  TEST_ASSERT_EQUAL_UINT16(2, b->length);
  buffer_append( b, "third line" );
  TEST_ASSERT_EQUAL_UINT16(3, b->length);

  cursor = b->head;
  TEST_ASSERT_EQUAL_STRING( "first line", cursor->string);

  cursor = cursor->next;
  TEST_ASSERT_EQUAL_STRING( "second line", cursor->string);

  cursor = cursor->next;
  TEST_ASSERT_EQUAL_STRING( "third line", cursor->string);

  return;
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_line_new);
    RUN_TEST(test_buffer_new);
    RUN_TEST(test_buffer_append);

    return UNITY_END();
}
