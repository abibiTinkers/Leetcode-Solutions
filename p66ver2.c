/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int countNumberOfNines(int* digits, int digitsSize){
    int count=0;
    for(int j=digitsSize-1;j>=0;j--){
        if(digits[j]==9){
            count++;
        }
        else{
            break;
        }
    }
    return count;
}
void iamprinter(int * ret, int* rs){
    printf("\nIam printing\t");
    for(int i=0;i<*rs;i++){
        printf("%d ",ret[i]);
    }
}
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* ret;
    bool ch=digits[digitsSize-1] ==9? true:false;
    switch(ch){
        case true:
            int nines=countNumberOfNines(digits,digitsSize);
            printf("Nines:%d\n",nines);
            if (nines==digitsSize){
                ret=(int*)malloc(sizeof(int)*(digitsSize+1));
                *returnSize=digitsSize+1;
                iamprinter(ret, returnSize);
                for(int i=1;i<=digitsSize;i++){
                    ret[i]=0;
                                    iamprinter(ret, returnSize);

                }
                ret[0]=1;
                                iamprinter(ret, returnSize);

            }else{
                ret=(int*)malloc(digitsSize*sizeof(int));
                *returnSize=digitsSize;
                for(int i=0;i<digitsSize-1;i++){
                    ret[i]=digits[i];
                 }
                int idx=digitsSize-1;
                
                while(nines!=0){
                   ret[idx]=0;
                   nines--;
                   idx--;
                } 
                ret[idx]+=1;
            }
            break;
            
        case false:
            ret=(int*)malloc(digitsSize*sizeof(int));
            for(int i=0;i<digitsSize;i++){
                ret[i]=digits[i];
            }
            ret[digitsSize-1]+=1;
            *returnSize=digitsSize;
            break;
            
    }
    return ret;
}
