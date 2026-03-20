int convertToInteger(char *nums,int numsSize){
    int ans=0;
    int exp=numsSize-1;
    for(int i=0;i<numsSize;i++){
        ans+=(nums[i]-'0')*(pow(2,exp));
        exp--;

    }
    printf("%s %d\n",nums,ans);
    return ans;
}
char* findDifferentBinaryString(char** nums, int numsSize) {
    int ansInNumber=0;
    int* numArray=(int*)malloc(numsSize*sizeof(int));
    for(int i=0;i<numsSize;i++){
        int equivNumber=convertToInteger(nums[i],numsSize);
        numArray[i]=equivNumber;
    }
    int j;
    for(int i=0;i<=pow(2,numsSize-1);i++){
        for( j=0;j<numsSize;j++){
            if(numArray[j]==i){

                break;
            }
        }
        if(j==numsSize){
            ansInNumber=i;
        }

    }
    
    for(int b=numsSize-1;b>=0;b--){
       nums[0][b]=(ansInNumber % 2)+'0';
       ansInNumber/=2;
    }
    
    return nums[0];
}
