#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>

int main(void) {
    printf("=== C Basic Syntax and Data Types ===\n");
    int i = 42;
    double d = 3.1415926535;
    char c = 'Z';
    bool b = true;

    printf("int: %d (size: %zu bytes)\n", i, sizeof(i));
    printf("double: %.5f (size: %zu bytes)\n", d, sizeof(d));
    printf("char: %c (ASCII: %d, size: %zu bytes)\n", c, (int)c, sizeof(c));
    printf("bool: %s (size: %zu bytes)\n", b ? "true" : "false", sizeof(b));
    printf("INT_MIN: %d, INT_MAX: %d\n", INT_MIN, INT_MAX);
    printf("DBL_MIN: %e, DBL_MAX: %e\n", DBL_MIN, DBL_MAX);

    // Arithmetic
    int a = 20, val = 6;
    printf("Arithmetic: a=%d, val=%d -> sum=%d, diff=%d, prod=%d, div=%d, mod=%d\n",
           a, val, a + val, a - val, a * val, a / val, a % val);

    return 0;
}
