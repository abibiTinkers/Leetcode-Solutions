int removeDuplicates(int* nums, int numsSize) {
   int i;int j=0;
   int prev=INT_MAX;
    for(i=0;i<numsSize;i++){
        if(nums[i]!=prev){
            nums[j++]=nums[i];
            prev=nums[i];
        }
        else{
            

            continue;
        }
    }
    return j;
}
