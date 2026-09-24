#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("=== C Pointers and Dynamic Memory Allocation ===\n");
    int x = 100;
    int *ptr = &x;

    printf("Value of x: %d\n", x);
    printf("Address of x (&x): %p\n", (void*)&x);
    printf("Pointer ptr: %p, dereferenced *ptr: %d\n", (void*)ptr, *ptr);

    *ptr = 250;
    printf("After *ptr = 250, x is: %d\n", x);

    // Dynamic memory allocation
    int n = 5;
    int *arr = (int*)malloc(n * sizeof(int));
    if (!arr) {
        perror("malloc failed");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = (i + 1) * 10;
    }

    printf("Dynamically allocated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    arr = NULL;
    printf("Memory freed successfully.\n");
    return 0;
}
