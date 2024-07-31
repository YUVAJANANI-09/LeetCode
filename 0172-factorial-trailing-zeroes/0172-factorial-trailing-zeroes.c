int trailingZeroes(int n) {
    int v=0;
    for(long long  i=5;(n/i)>0; i*=5)
    {
       v=v+(n/i);
    }
    return v;
}