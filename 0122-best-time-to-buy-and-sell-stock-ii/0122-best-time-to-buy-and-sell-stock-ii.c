int maxProfit(int* prices, int pricesSize){
    int maximumProfit = 0;
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] > prices[i - 1])
            maximumProfit += prices[i] - prices[i - 1];
    }
    return maximumProfit;     
}