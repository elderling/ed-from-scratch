#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "buffer.h"
#include "Unity/src/unity.h"

buffer * buffer1;
line * line1;
char * str1 = "String 1";

void test_set_next(void);
void test_set_prev(void);
void test_buff_get_head(void);
void test_buff_append_line(void);

void setUp(void)
{
    return;
}

void tearDown(void)
{
    return;
}

void test_buff_get_head(void)
{
    buffer1 = new_buffer();

    TEST_ASSERT_NULL(buff_get_head(buffer1));

    return;
}

void test_set_next(void)
{
    line * l;
    line * n;

    l = new_line("first");
    n = new_line("second");

    set_next(l,n);

    TEST_ASSERT_EQUAL_PTR(n, get_next(l));

    return;
}

void test_set_prev(void)
{
    line * l;
    line * p;

    l = new_line("first");
    p = new_line("previous");

    set_prev(l,p);

    TEST_ASSERT_EQUAL_PTR(p, get_prev(l));

    return;
}

void test_buff_append_string(void)
{
    buffer * b;
    b = new_buffer();

    buff_append_string(b, "first line");
    buff_append_string(b, "second line");
    TEST_ASSERT_NOT_EQUAL(buff_get_head(b), buff_get_tail(b));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_buff_get_head);
    RUN_TEST(test_set_next);
    RUN_TEST(test_set_prev);
    RUN_TEST(test_buff_append_string);

    return UNITY_END();
}
