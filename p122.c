int maxProfit(int* prices, int pricesSize) {
    
    int i=0;
    int j=1;
    int profit=0;
    
    while(i<pricesSize-1 && j<pricesSize){
        j=i+1;
        if(prices[i]<prices[j]){
                profit+=prices[j]-prices[i];
            i=j;
            
        }
        else{
            i++;
        }
    }
    return profit;
}
