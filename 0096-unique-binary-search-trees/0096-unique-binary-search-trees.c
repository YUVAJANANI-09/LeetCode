int numTrees(int n) {
    long s=1;
    for(int i=0;i<n;i++)
    {
        s=s*2*(2*i+1)/(i+2);
    }
    return (int)s;
}