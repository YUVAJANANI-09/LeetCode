int numJewelsInStones(char* jl, char* s) {
    int c=0;
    for(int i=0;i<strlen(jl);i++)
    {
        for(int j=0;j<strlen(s);j++)
        {
            if(jl[i]==s[j])
            {
                c++;
            }
        }
    }
    return c;

}