int findClosestNumber(int* nums, int numsSize)
{
    int min = INT_MAX;
    int val = INT_MAX;
    for (int i = 0; i < numsSize; i++) {
        if (abs(nums[i]) <= min) {
            min = abs(nums[i]);
            if (abs(val) == abs(nums[i]))
                val = val > nums[i] ? val : nums[i];
            else
                val = nums[i];
            printf("%d ", val);
        }
    }
    return val;
}