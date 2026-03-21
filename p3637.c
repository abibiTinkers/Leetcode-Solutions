#include <stdbool.h>

bool isTrionic(int* nums, int numsSize) {
    // A trionic array must have at least 4 elements to satisfy 0 < p < q < n-1
    if (numsSize < 4) return false;

    int i = 0;

    // Phase 1: Strictly Increasing (0 to p)
    while (i < numsSize - 1 && nums[i] < nums[i + 1]) {
        i++;
    }
    // If no initial increase happened, it's not trionic
    if (i == 0 || i == numsSize - 1) return false;

    int p = i;

    // Phase 2: Strictly Decreasing (p to q)
    while (i < numsSize - 1 && nums[i] > nums[i + 1]) {
        i++;
    }
    // If no decrease happened after the first peak, or it reached the end
    if (i == p || i == numsSize - 1) return false;

    int q = i;

    // Phase 3: Strictly Increasing (q to n-1)
    while (i < numsSize - 1 && nums[i] < nums[i + 1]) {
        i++;
    }

    // Valid if we successfully reached the very last element
    return i == numsSize - 1;
}
