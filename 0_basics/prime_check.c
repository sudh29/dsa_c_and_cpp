#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; (long long)i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int main(void) {
    printf("=== Prime Number Check in C ===\n");
    int test_vals[] = {1, 2, 3, 4, 17, 19, 20, 29, 97, 100};
    int count = sizeof(test_vals) / sizeof(test_vals[0]);
    for (int i = 0; i < count; i++) {
        printf("%d is %s\n", test_vals[i], is_prime(test_vals[i]) ? "PRIME" : "NOT prime");
    }
    return 0;
}
