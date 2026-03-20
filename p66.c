int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // 1. We don't know the final size yet, so don't malloc (digitsSize+1) immediately.
    // 2. First, modify the input 'digits' in-place to calculate the result.
    int carry = 1;
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] + carry == 10) {
            digits[i] = 0;
            carry = 1;
        } else {
            digits[i] += carry;
            carry = 0;
            break;
        }
    }

    if (carry == 0) {
        // CASE 1: No overflow (e.g., 123 -> 124)
        *returnSize = digitsSize;
        int* res = malloc(digitsSize * sizeof(int));
        for (int i = 0; i < digitsSize; i++) res[i] = digits[i]; // MUST copy all values
        return res;
    } else {
        // CASE 2: Overflow (e.g., 99 -> 100)
        *returnSize = digitsSize + 1;
        int* res = malloc((*returnSize) * sizeof(int));
        res[0] = 1;
        for (int i = 1; i < *returnSize; i++) res[i] = 0; // The rest are 0s
        return res;
    }
}
