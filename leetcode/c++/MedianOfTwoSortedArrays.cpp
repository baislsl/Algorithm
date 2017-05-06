//There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
//Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).


double getNext(int* nums1, int nums1Size, int* nums2, int nums2Size){
    static int index1,index2;
    if(index1==nums1Size) return nums2[index2++];
    else if(index2==nums2Size) return nums1[index1++];
    else return nums1[index1] > nums2[index2] ? nums2[index2++] : nums1[index1++];
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int total = nums1Size + nums2Size;
    int flag = total%2,middle = total/2;
    int cur = 0;
    double result;
    if(flag){
        while(cur++ != middle + 1) result = getNext(nums1,nums1Size,nums2,nums2Size);
        return result;
    }else{
        while(cur++ != middle) result = getNext(nums1,nums1Size,nums2,nums2Size);
        return (result + getNext(nums1,nums1Size,nums2,nums2Size))/2;
    }

}

