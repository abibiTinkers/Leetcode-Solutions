/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
    int* run=(int*)malloc(numsSize*sizeof(int));
    int i;
    *returnSize=numsSize;
    int retValue=0;
    for(i=0;i<numsSize;i++){
        int j;
        for(j=i;j>=0;j--){
           retValue+=nums[j];
        }
        run[i]=retValue;
        retValue=0;
    }
    return run;
}
