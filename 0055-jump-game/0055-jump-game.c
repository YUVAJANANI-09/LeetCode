bool canJump(int* nums, int numsSize) {
     int n = numsSize-1;
        for (int i = numsSize-2; i>=0; i--) {
            if (n-i<=nums[i]) {
                n=i;
            }
        }
        return n==0;
}