/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

long factorial(int n){
    if(n == 1 || n == 0) return 1;
    return n * factorial(n - 1);
}
void backtrack(int* nums, int** arr, int n, int k, int* index, int pos, int cur){
    if(pos == k){
        for(int i=0; i<k; i++){
            arr[*index][i] = nums[i];
        }
        (*index)++;
        return;
    }
    for(int i=cur; i<=n-k+pos+1; i++){ // 不能把後面的用完(沒有排列)
        nums[pos] = i;
        backtrack(nums, arr, n, k, index, pos+1, i+1);
    }
}
int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    long long c = 0;
    c = factorial(n) / (factorial(k) * factorial(n - k)); // C n取k
    *returnColumnSizes = (int*)malloc(c * sizeof(int));
    *returnSize = c;
    int** arr = (int**)malloc(c * sizeof(int*));
    for(int i=0; i<c; i++){
        arr[i] = (int*)calloc(k, sizeof(int));
        (*returnColumnSizes)[i] = k;
    }
    int* nums = (int*)malloc(k * sizeof(int));
    int* index = (int*)malloc(sizeof(int));
    *index = 0;
    backtrack(nums, arr, n, k, index, 0, 1);
    free(index);
    free(nums);
    return arr;
}