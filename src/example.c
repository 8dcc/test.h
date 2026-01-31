
#include <stddef.h>
#include <stdlib.h>

#include "test.h"

/*----------------------------------------------------------------------------*/

static int add(int a, int b) {
    return a + b;
}

static int* create_int(int value) {
    int* p = malloc(sizeof(int));
    if (p != NULL)
        *p = value;
    return p;
}

/*----------------------------------------------------------------------------*/

TEST_DECL(add_positive) {
    TEST_ASSERT_EQ(add(2, 3), 5);
}

TEST_DECL(add_negative) {
    TEST_ASSERT_EQ(add(-1, -2), -3);
}

TEST_DECL(add_zero) {
    TEST_ASSERT_EQ(add(0, 0), 0);
    TEST_ASSERT_EQ(add(5, 0), 5);
}

TEST_DECL(create_int_not_null) {
    int* p = create_int(42);
    TEST_ASSERT_NOT_NULL(p);
    free(p);
}

TEST_DECL(create_int_value) {
    int* p = create_int(123);
    TEST_ASSERT_NOT_NULL(p);
    TEST_ASSERT_EQ(*p, 123);
    free(p);
}

TEST_DECL(boolean_true) {
    TEST_ASSERT_TRUE(1 == 1);
}

TEST_DECL(boolean_false) {
    TEST_ASSERT_FALSE(1 == 2);
}

TEST_DECL(intentionally_failed_test) {
    TEST_ASSERT(1 == 2);
}

TEST_DECL(not_equal) {
    TEST_ASSERT_NE(1, 2);
    TEST_ASSERT_NE(add(1, 1), 3);
}

/*----------------------------------------------------------------------------*/

int main(void) {
    printf("Running example tests...\n\n");

    TEST_RUN(add_positive);
    TEST_RUN(add_negative);
    TEST_RUN(add_zero);
    TEST_RUN(create_int_not_null);
    TEST_RUN(create_int_value);
    TEST_RUN(boolean_true);
    TEST_RUN(boolean_false);
    TEST_RUN(intentionally_failed_test);
    TEST_RUN(not_equal);

    putchar('\n');
    TEST_PRINT_RESULTS(stdout);

    return (TEST_NUM_FAILED > 0) ? 1 : 0;
}
