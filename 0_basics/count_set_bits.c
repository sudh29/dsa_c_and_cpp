#include <stdio.h>

// Brian Kernighan's Algorithm: O(number of set bits)
int count_set_bits(unsigned int n) {
    int count = 0;
    while (n > 0) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main(void) {
    printf("=== Counting Set Bits (Hamming Weight) ===\n");
    unsigned int nums[] = {0, 1, 5, 7, 15, 1023, 1024};
    int size = sizeof(nums) / sizeof(nums[0]);
    for (int i = 0; i < size; i++) {
        printf("Number %u (0x%X) has %d set bits\n", nums[i], nums[i], count_set_bits(nums[i]));
    }
    return 0;
}
