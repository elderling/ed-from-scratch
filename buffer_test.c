#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "buffer.h"
#include "Unity/src/unity.h"

void test_line_new( void );
void test_buffer_new( void );
void test_buffer_append( void );
void test_buffer_get( void );
void test_buffer_delete( void );
void test_buffer_insert( void );

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

void test_buffer_delete( void )
{
  buffer * b;
  b = buffer_new();

  buffer_append( b, "test single element");
  buffer_delete( b, 0 );
  TEST_ASSERT_NULL(b->head);
  TEST_ASSERT_NULL(b->tail);

  buffer_append( b, "first line" );
  buffer_append( b, "second line" );
  buffer_append( b, "third line" );

  buffer_delete(b, 1);

  TEST_ASSERT_EQUAL_STRING( "first line", buffer_get(b, 0));
  TEST_ASSERT_EQUAL_STRING( "third line", buffer_get(b, 1));

  buffer_delete(b, 0);
  TEST_ASSERT_EQUAL_STRING( "third line", buffer_get(b, 0));

  buffer_delete(b,0);

  TEST_ASSERT_NULL(b->head);
  TEST_ASSERT_NULL(b->tail);

  buffer_append( b, "third line" );
  TEST_ASSERT_EQUAL_STRING( "third line", buffer_get(b, 0));
  
  return;
}

void test_buffer_get( void )
{
  buffer * b;
  b = buffer_new();

  buffer_append( b, "first line" );
  buffer_append( b, "second line" );
  buffer_append( b, "third line" );

  TEST_ASSERT_EQUAL_STRING( "first line", buffer_get(b, 0));
  TEST_ASSERT_EQUAL_STRING( "second line", buffer_get(b, 1));
  TEST_ASSERT_EQUAL_STRING( "third line", buffer_get(b, 2));
  TEST_ASSERT_NULL(buffer_get(b, 3));

  return;
}

void test_buffer_insert( void )
{
  buffer * b;
  b = buffer_new();

  buffer_insert( b, 0, "first line");
  TEST_ASSERT_EQUAL_STRING( "first line", buffer_get(b, 0));

  buffer_insert( b, 0, "new first line");
  TEST_ASSERT_EQUAL_STRING( "new first line", buffer_get(b, 0));
  TEST_ASSERT_EQUAL_STRING( "first line", buffer_get(b, 1));

  buffer_insert( b, 1, "second line" );
  TEST_ASSERT_EQUAL_STRING( "second line", buffer_get(b, 1));
  TEST_ASSERT_EQUAL_STRING( "first line", buffer_get(b, 2));

  buffer_insert( b, 2, "third line" );
  TEST_ASSERT_EQUAL_STRING( "third line", buffer_get(b, 2));
  TEST_ASSERT_EQUAL_STRING( "first line", buffer_get(b, 3));

  buffer_insert( b, 0, "newest first line");
  TEST_ASSERT_EQUAL_STRING( "newest first line", buffer_get(b, 0));

  return;
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_line_new);
    RUN_TEST(test_buffer_new);
    RUN_TEST(test_buffer_append);
    RUN_TEST(test_buffer_get);
    RUN_TEST(test_buffer_delete);
    RUN_TEST(test_buffer_insert);

    return UNITY_END();
}
