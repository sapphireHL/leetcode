class Solution {
public:
    int findKth(vector<int>& nums1, vector<int>& nums2, int k, int p1, int p2){
        //assume nums1 is larger than nums2
        if(nums1.size() - p1 > nums2.size() - p2)
            return findKth(nums2, nums1, k, p2, p1);
        if(p1 >= nums1.size())
            return nums2[p2+k-1];
        if(k == 1)
            return min(nums1[p1], nums2[p2]);
            
        int k1 = min(k/2, (int)nums1.size()-p1), k2 = k - k1;
        if(nums1[p1+k1-1] < nums2[p2+k2-1])
            return findKth(nums1, nums2, k-k1, p1+k1, p2);
        else if(nums1[p1+k1-1] > nums2[p2+k2-1])
            return findKth(nums1, nums2, k-k2, p1, p2+k2);
        else 
            return nums1[p1+k1-1];
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size(), total = size1+size2;
        if(total == 0) 
            return 0.0;
        if(total % 2 != 0) 
            return findKth(nums1, nums2, total/2+1, 0, 0);
        else
            return (findKth(nums1, nums2, total/2, 0, 0)+findKth(nums1, nums2, total/2+1, 0, 0))/2.0;
    }
};
