
int minPartitions(char* n) {
    int num;
    int max=0;
    int i;
    for( i=0;n[i]!='\0';i++){
        num=n[i]-'0';
        max=num>max?num:max;
        
    }
    return max;   
}
