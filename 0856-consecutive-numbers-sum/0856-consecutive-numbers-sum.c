int consecutiveNumbersSum(int n) {
    int c=0;
    for (int i=2;i<n;i++)
    {
    int s=i*(i+1)/2;
    if(s>n) break;
    if((n-s)%i==0) c++;
    }
    return c+1;
}