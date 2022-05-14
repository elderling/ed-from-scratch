#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "buffer.h"
#include "Unity/src/unity.h"

buffer * buffer1;
line * line1;
char * str1 = "String 1";

void test_buff_get_head(void);

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

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_buff_get_head);

    return UNITY_END();
}
