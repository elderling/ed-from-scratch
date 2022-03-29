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
void test_count_ancestors(void);
void test_list_size(void);
void test_delete_line(void);
void test_insert_after(void);
void test_get_nth(void);
void test_buff_append_line(void);
void test_buff_get_line(void);

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

void test_count_ancestors(void)
{
    line * head;
    line * current;
    char i;
    char * s;
    s = malloc(2);
    memset(s,0,2);
    head = new_line("head");
    TEST_ASSERT_EQUAL_UINT(0, count_ancestors(head));
    current = head;

    for(i = 0; i < 3; i++) {
        sprintf(s, "%d", i);
        set_next(current, new_line(s));
        current = get_next(current);
    }

    TEST_ASSERT_EQUAL_UINT(3, count_ancestors(current));
    TEST_ASSERT_EQUAL_STRING("2", get_string(current));
    current = get_prev(current);
    TEST_ASSERT_EQUAL_STRING("1", get_string(current));
    current = get_prev(current);
    TEST_ASSERT_EQUAL_STRING("0", get_string(current));

    return;
}

void test_list_size(void)
{
    line * head;
    line * current;
    char i;
    char * s;
    s = malloc(2);
    memset(s,0,2);
    head = new_line("head");
    TEST_ASSERT_EQUAL_UINT(0, count_ancestors(head));
    current = head;

    for(i = 0; i < 3; i++) {
        sprintf(s, "%d", i);
        set_next(current, new_line(s));
        current = get_next(current);
    }

    TEST_ASSERT_EQUAL_UINT(4, list_size(current));
    current = get_prev(current);
    TEST_ASSERT_EQUAL_UINT(4, list_size(current));
    current = get_prev(current);
    TEST_ASSERT_EQUAL_UINT(4, list_size(current));
    TEST_ASSERT_EQUAL_UINT(4, list_size(head));

    return;
}

void test_delete_line(void)
{
    line * head;
    line * current;
    char i;
    char * s;
    s = malloc(2);
    memset(s,0,2);
    head = new_line("head");
    current = head;

    for(i = 0; i < 3; i++) {
        sprintf(s, "%d", i);
        set_next(current, new_line(s));
        current = get_next(current);
    }

    current = get_next(head);

    delete_line(current);

    TEST_ASSERT_EQUAL_UINT(3, list_size(head));

    return;
}

void test_insert_after(void)
{
    char * s = "test";
    unsigned char i;
    line * head;
    line * il;
    line * current;

    head = new_line(s);
    current = head;

    for(i=0; i<3; i++) {
        il = new_line(s);
        insert_after(current, il);
        current = il;
    }

    TEST_ASSERT_EQUAL_UINT(4, list_size(head));

    return;
}

void test_get_nth(void)
{
    line * head;
    line * current;
    char i;
    char * s;
    s = malloc(2);
    memset(s,0,2);
    head = new_line("head");
    current = head;

    for(i = 0; i < 3; i++) {
        sprintf(s, "%d", i);
        set_next(current, new_line(s));
        current = get_next(current);
    }

    TEST_ASSERT_EQUAL_STRING(get_string(get_nth(head, 0)), "head");
    TEST_ASSERT_EQUAL_STRING(get_string(get_nth(head, 3)), "2");

    return;
}

void test_buff_append_line(void)
{
    buffer * b;
    b = new_buffer();

    buff_append_line(b, "first line");
    TEST_ASSERT_EQUAL_UINT(1, buff_get_length(b));
    TEST_ASSERT_EQUAL_STRING("first line",get_string(buff_get_head(b)));
    buff_append_line(b, "second line");
    TEST_ASSERT_NOT_EQUAL(buff_get_head(b), buff_get_tail(b));
    buff_append_line(b, "third line");
    TEST_ASSERT_EQUAL_UINT(2, count_ancestors(buff_get_tail(b)));
}

void test_buff_get_line(void)
{
    buffer * b;
    b = new_buffer();
    TEST_ASSERT_NULL(buff_get_line(b, 0));
    buff_append_line(b, "first line");
    buff_append_line(b, "second line");
    buff_append_line(b, "third line");
    TEST_ASSERT_EQUAL_STRING(get_string(buff_get_line(b, 1)), "second line");
    TEST_ASSERT_NULL(buff_get_line(b, 5));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_get_string);
    RUN_TEST(test_buff_get_head);
    RUN_TEST(test_set_next);
    RUN_TEST(test_set_prev);
    RUN_TEST(test_count_children);
    RUN_TEST(test_count_ancestors);
    RUN_TEST(test_list_size);
    RUN_TEST(test_delete_line);
    RUN_TEST(test_insert_after);
    RUN_TEST(test_get_nth);
    RUN_TEST(test_buff_append_line);
    RUN_TEST(test_buff_get_line);

    return UNITY_END();
}
