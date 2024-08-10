 void swap(int* a, int* b){
     int temp = *a;
     *a = *b;
     *b = temp;
 }

 void backtrack(int* nums, int numsSize, int*** arr, int* returnSize, int** returnColumnSizes, int index){
     if(index == numsSize - 1){
         (*returnSize)++;
         *arr = (int**)realloc(*arr, sizeof(int*) * (*returnSize));
         (*returnColumnSizes)[*returnSize - 1] = numsSize;
         (*arr)[*returnSize - 1] = (int*)malloc(sizeof(int) * numsSize);
         for(int i=0; i<numsSize; i++){
             (*arr)[*returnSize - 1][i] = nums[i];
         }
         return;
     }
     for(int i=index; i<numsSize; i++){
         swap(nums+index, nums+i);
         backtrack(nums, numsSize, arr, returnSize, returnColumnSizes, index + 1);
         swap(nums+index, nums+i);
     }
 }

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 1;
    for(int i=1; i<=numsSize; i++) (*returnSize) *= i;
    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int)); 
    *returnSize = 0;
    int **arr = (int**)malloc(sizeof(int*));
    backtrack(nums, numsSize, &arr, returnSize, returnColumnSizes, 0);
    return arr;
}