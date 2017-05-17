class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int mm = m-1, nn = n-1, mn = m+n-1;
        while(mm>=0 && nn>=0){
            nums1[mn--] = nums1[mm]> nums2[nn]?nums1[mm--]:nums2[nn--];
        }
        while(nn>=0){
            nums1[mn--] = nums2[nn--];
        }
    }
};
