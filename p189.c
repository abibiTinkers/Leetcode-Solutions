void rotate(int* nums, int numsSize, int k) {
    int* temp=(int*) malloc (numsSize* sizeof(int));
    int i;
    for(i=0;i<numsSize;i++){
        temp[i]=nums[i];
    }
    for(i=0;i<numsSize;i++){
        nums[(i+k)%numsSize]=temp[i];
    }
}
