int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int i,j;
    int sum;
    int wealth=0;
    for(i=0;i<accountsSize;i++){
        sum=0;
        for(j=0;j<*accountsColSize;j++){
            sum+=accounts[i][j];
        }
        if(sum>wealth){
            wealth=sum;
        }
    }
    return wealth;
}
