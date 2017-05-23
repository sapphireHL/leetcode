class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size(), left=0, right=nums.size()-1, pos=0;
        if(n==0) return 0;
        if(target < nums[0]) return 0;
        if(target > nums[n-1]) return n;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid] < target) left = mid+1;
            else if(nums[mid] >target) right = mid-1;
            else return mid;
        }
        return left;
    }
};
