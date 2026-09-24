#include <stdio.h>

void swap_pointers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_xor(int *a, int *b) {
    if (a != b) {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}

int main(void) {
    printf("=== Swapping Two Numbers (Pointers & XOR) ===\n");
    int x = 10, y = 20;
    printf("Initial: x=%d, y=%d\n", x, y);

    swap_pointers(&x, &y);
    printf("After swap_pointers: x=%d, y=%d\n", x, y);

    swap_xor(&x, &y);
    printf("After swap_xor: x=%d, y=%d\n", x, y);
    return 0;
}
