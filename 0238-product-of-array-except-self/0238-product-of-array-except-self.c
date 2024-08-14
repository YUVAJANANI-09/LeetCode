int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int n = numsSize;
    int* ans = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        ans[i] = 0;
    }
    int product = 1;
    int zeros = 0;

    for (int i = 0; i < n; i++) {
        int num = nums[i];
        if (num == 0) {
            zeros++;
            continue;
        }
        product *= num;
    }

    if (zeros == 1) {
        for (int i = 0; i < n; i++) {
            ans[i] = nums[i] == 0 ? product : 0;
        }
    } else if (zeros == 0) {
        for (int i = 0; i < n; i++) {
            ans[i] = product / nums[i];
        }
    }

    *returnSize = n;
    return ans;
}