#include <stdint.h>
int jump(int* nums, int numsSize) 
{
    if(numsSize == 1) return 0;
    if(numsSize == 2) return 1;
    int* reach = nums+*nums;
    int* last = nums; 
    int* pos = nums;
    int* next = NULL;
    uint16_t jumps = 0; 
    while (pos < nums+numsSize)
    {
        next = pos+*pos;
        if(next > reach)
        {
            reach = next;
        }

        if(pos == last)
        {
            last = reach;
            jumps++;
        }

        if(last >= nums+numsSize-1)
        {
            break;
        }
        pos++;
    }
    return jumps;
}