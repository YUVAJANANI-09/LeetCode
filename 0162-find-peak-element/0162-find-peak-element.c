int getPeak(int* nums,int s,int e,int low,int high){
    int mid = (s + e) / 2;
    if(mid == low || nums[mid] > nums[mid - 1]){
        if(mid == high || nums[mid] > nums[mid + 1]){
            return mid;
        }
        else{
            return getPeak(nums,mid + 1,e,low,high);
        }
    }
    else{
        return getPeak(nums,s,mid - 1,low,high);
    }
}

int findPeakElement(int* nums, int numsSize){
    return getPeak(nums,0,numsSize - 1,0,numsSize - 1);
}