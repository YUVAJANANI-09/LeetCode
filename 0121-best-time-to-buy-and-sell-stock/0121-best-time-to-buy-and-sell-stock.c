int maxProfit(int* p, int ps) {
    int max=0;
    int mp=p[0];
    for(int i=0;i<ps;i++)
    {
        
        if(p[i]<mp)
        mp=p[i];
        if(p[i]-mp>max)
        max=p[i]-mp;
    }
    return max;
}