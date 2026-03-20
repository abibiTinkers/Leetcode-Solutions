/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int * returna=(int*)malloc(2*sizeof(int));
    *returnSize=2;
    int flag=0;
    for(int i=0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
                returna[0]=i;
                printf("%d\t",returna[0]);
                
                returna[1]=j;
                printf("%d\n",returna[1]);
                flag=1;
                break;
            }
        }
        if(flag==1){printf("hi"); break;}
    }

    return returna;
}
