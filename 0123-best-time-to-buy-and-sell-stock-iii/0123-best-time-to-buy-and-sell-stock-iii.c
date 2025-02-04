int maxProfit(int* prices, int pricesSize){
    int *s1 = (int *)malloc(sizeof(int) * pricesSize);
    int *s2 = (int *)malloc(sizeof(int) * pricesSize);
    
    memset(s1, 0, sizeof(int) * pricesSize);
    memset(s2, 0, sizeof(int) * pricesSize);
    
    int max = INT_MIN, min= prices[0];

    for(int i=1; i<pricesSize-1; i++){
        if(min > prices[i]) min = prices[i]; 
        
        if(max < (prices[i]- min)) max = prices[i] - min;
        s1[i] = max;
    }//for i
   
    min= INT_MIN, max=prices[pricesSize-1];
    s2[pricesSize-1] = 0;

    for(int i=pricesSize-2; i>=0; i--){
        if(prices[i] > max) max = prices[i]; 
        if(min < (max- prices[i])) min = max - prices[i];
    
        s2[i] = min;
    }//for i
    
    max=INT_MIN;
    for(int i=0;i<pricesSize;i++){
        max = max < (s1[i] + s2[i]) ?  (s1[i] + s2[i]) : max;
    }

    return max;
}