#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "buffer.h"
#include "Unity/src/unity.h"

buffer * buffer1;
line * line1;
char * str1 = "String 1";

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
    RUN_TEST(test_buff_append_string);

    return UNITY_END();
}
