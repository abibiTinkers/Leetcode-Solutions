#include <stdio.h>

void giveMeNumber(int* nextCheck, int* nums, int numsSize){
    
    if(*nextCheck < 0){
        *nextCheck = 0;
    }

    for(int i = *nextCheck; i < numsSize; i++){
        if(nums[i] != 0){
            *nextCheck = i;
            return;
        }
    }

    
    *nextCheck = -1;
}

void moveZeroes(int* nums, int numsSize) {
    int count = 0;
    int* nextCheck = &count;

    for(int i = 0; i < numsSize; i++){

        if(*nextCheck == -1){
            break;
        }

        if(nums[i] == 0){
            giveMeNumber(nextCheck, nums, numsSize);

            if(*nextCheck != -1){
                nums[i] = nums[*nextCheck];
                nums[*nextCheck] = 0;

                (*nextCheck)++;
            }
        }
        else{
            if(*nextCheck <= i){
                *nextCheck = i + 1;
            }
        }
    }
}
