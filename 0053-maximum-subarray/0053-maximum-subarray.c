int maxSubArray(int* nums, int numsSize){
    int sum=nums[0];
    int maxsum=nums[0];
for(int i=1;i<numsSize;i++)
{
    if(sum<0)
    {
        if(nums[i]>sum)
        sum=nums[i];
        
        
    }
    else
    {
        sum=sum+nums[i];
    }
    if(sum>maxsum)
    maxsum=sum;
}
return maxsum;



}