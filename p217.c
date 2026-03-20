void merge(int* nums, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++) L[i] = nums[left + i];
    for (j = 0; j < n2; j++) R[j] = nums[mid + 1 + j];

    i = 0; j = 0; k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) nums[k++] = L[i++];
        else nums[k++] = R[j++];
    }

    while (i < n1) nums[k++] = L[i++];
    while (j < n2) nums[k++] = R[j++];

    free(L);
    free(R);
}

// Recursive Merge Sort function
void mergeSort(int* nums, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }
}
bool containsDuplicate(int* nums, int numsSize) {
    mergeSort(nums,0,numsSize-1);
    for(int k=0;k<numsSize-1;k++){
        if(nums[k]==nums[k+1]){
            return true;
        }
    }
    return false;
}
