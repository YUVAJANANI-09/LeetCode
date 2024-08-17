int* twoSum(int* nums, int j, int target, int* resSize){
    int i = 0; j--;
    *resSize = 2;
    int *res = (int *)malloc(sizeof(int)*2); 
    while(i < j){
        int check = nums[i]+nums[j];
        if(check == target) break;
        if(check < target) i++;
        else j--;
    }
    res[0] = i+1;
    res[1] = j+1;
    return res;
}