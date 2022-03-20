#include "buffer.h"
#include "Unity/src/unity.h"

buffer * buffer1;
line * line1;
char * str1 = "String 1";

void test_get_string(void);
void test_set_next(void);
void test_get_head(void);

void setUp(void) {
    return;
}

void tearDown(void) {
    return;
}

void test_get_string(void) {
    line1 = new_line(str1);

    TEST_ASSERT_EQUAL_STRING(str1, get_string(line1));

    return;
}

void test_get_head(void) {
    buffer1 = new_buffer();

    TEST_ASSERT_NULL(get_head(buffer1));

    return;
}

void test_set_next(void) {
	line * l;
	line * n;

	l = new_line("first");
	n = new_line("second");

	set_next(l,n);

	TEST_ASSERT_EQUAL_PTR(n, get_next(l));

	return;
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_get_string);
    RUN_TEST(test_get_head);
    RUN_TEST(test_set_next);

    return UNITY_END();
}
