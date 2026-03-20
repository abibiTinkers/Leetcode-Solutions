/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    *returnSize=n;
    char** answer=(char**)malloc(n*sizeof(char*));

    for(int i=1;i<=n;i++){
        if(i%3 ==0 && i%5 ==0){
            answer[i-1]=(char*)malloc(9*sizeof(char));
            strcpy(answer[i-1],"FizzBuzz");
        }
        else if(i%3==0){
            answer[i-1]=(char*)malloc(5*sizeof(char));
            strcpy(answer[i-1],"Fizz");
        }
        else if(i%5==0){
            answer[i-1]=(char*)malloc(5*sizeof(char));
           strcpy(answer[i-1],"Buzz");
        }
        else{
            answer[i-1]=(char*)malloc(12*sizeof(char));
            sprintf(answer[i-1],"%d",i);
            
        }
        
    }
    return answer;
}
