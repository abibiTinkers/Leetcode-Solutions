/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    int duplicate = -1;
    int missing = -1;

    // 1. Find the duplicate by marking visited indices
    for (int i = 0; i < numsSize; i++) {
        int val = abs(nums[i]);
        if (nums[val - 1] < 0) {
            duplicate = val;
        } else {
            nums[val - 1] = -nums[val - 1];
        }
    }

    // 2. Find the missing number (the one whose index remains positive)
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            missing = i + 1;
            break;
        }
    }

    ans[0] = duplicate;
    ans[1] = missing;
    return ans;
}
