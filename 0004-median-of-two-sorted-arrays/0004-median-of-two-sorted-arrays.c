double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int n = nums1Size + nums2Size;
    int nums[n];
    int j = 0, k = 0;
    int i = 0;
    while (j < nums1Size && k < nums2Size) {

        if (j[nums1] < k[nums2]) {
            i[nums] = j[nums1];
            j++;

        } else {
            i[nums] = k[nums2];
            k++;
        }
        i++;
    }

    while (j < nums1Size) {
        i[nums] = j[nums1];
        i++;
        j++;
    }
    while (k < nums2Size) {
        i[nums] = k[nums2];
        i++;
        k++;
    }
    if (n % 2 == 0) 
        return ((double)((n / 2 - 1)[nums]+(n / 2)[nums])/2);
    return nums[n / 2];
}