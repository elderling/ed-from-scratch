#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "buffer.h"
#include "Unity/src/unity.h"

buffer * buffer1;
line * line1;
char * str1 = "String 1";

void test_get_string(void);
void test_set_next(void);
void test_set_prev(void);
void test_buff_get_head(void);
void test_count_children(void);
void test_buff_append_line(void);

void setUp(void)
{
    return;
}

void tearDown(void)
{
    return;
}

void test_get_string(void)
{
    line1 = new_line(str1);

    TEST_ASSERT_EQUAL_STRING(str1, get_string(line1));

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

void test_count_children(void)
{
    line * head;
    line * current;
    char i;
    char * s;
    s = malloc(2);
    memset(s,0,2);
    head = new_line("head");
    TEST_ASSERT_EQUAL_UINT(0, count_children(head));
    current = head;

    for(i = 0; i < 3; i++) {
        sprintf(s, "%d", i);
        set_next(current, new_line(s));
        current = get_next(current);
    }

    TEST_ASSERT_EQUAL_UINT(3, count_children(head));

    current = head;

    TEST_ASSERT_EQUAL_STRING("head", get_string(current));
    current = get_next(current);
    TEST_ASSERT_EQUAL_STRING("0", get_string(current));
    current = get_next(current);
    TEST_ASSERT_EQUAL_STRING("1", get_string(current));

    return;
}

void test_buff_append_string(void)
{
    buffer * b;
    b = new_buffer();

    buff_append_string(b, "first line");
    TEST_ASSERT_EQUAL_STRING("first line",get_string(buff_get_head(b)));
    buff_append_string(b, "second line");
    TEST_ASSERT_NOT_EQUAL(buff_get_head(b), buff_get_tail(b));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_get_string);
    RUN_TEST(test_buff_get_head);
    RUN_TEST(test_set_next);
    RUN_TEST(test_set_prev);
    RUN_TEST(test_count_children);
    RUN_TEST(test_buff_append_string);

    return UNITY_END();
}
