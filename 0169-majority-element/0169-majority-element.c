int majorityElement(int* nums, int ns) {
    int i,e=0,v;
    for(int i=0;i<ns;i++)
    {
        if(e==0)
        v=nums[i];
         if(nums[i]==v)
        e+=1;
        else 
        e-=1;
    }
    return v;
}