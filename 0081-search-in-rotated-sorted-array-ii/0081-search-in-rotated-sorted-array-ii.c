bool search(int* nums, int numsSize, int target) {
   int left = 0, right = numsSize - 1;
    while (left <= right) {
        const int middle = (left + right) / 2;
        if (target == nums[middle]) {
            return true;
        }
        else if (nums[middle] < nums[right]) {
            if (target > nums[middle] && target <= nums[right]) 
                left = middle + 1;
            else 
                right = middle - 1;
        } 
        else if (nums[middle] > nums[right]) {
            if (target < nums[middle] && target >= nums[left]) 
                right = middle - 1;
            else 
                left = middle + 1;
        } 
        else if (nums[middle] == nums[right]) {
            right--;
        }
    }
    return false; 
}