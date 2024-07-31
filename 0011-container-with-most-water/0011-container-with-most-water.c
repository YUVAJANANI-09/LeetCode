int min(int a, int b) {
    if (a > b)
        return b;
    else 
        return a;
}
int maxArea(int* arr, int n) {
    int left = 0;
    int right = n - 1;
    int maxa = 0;
    while (left < right) {
        int area = min(arr[left], arr[right]) * (right - left);
        if (area > maxa) 
        {
            maxa = area;
        }
        if (arr[left] < arr[right]) 
        {
            left++;
        } 
        else 
        {
            right--;
        }
    }
    return maxa;
}