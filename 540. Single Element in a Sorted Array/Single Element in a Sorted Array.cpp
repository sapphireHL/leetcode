class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left < right){
            int mid = left + (right-left)/2;
            mid = mid%2 == 1?mid-1:mid;
            if(nums[mid] == nums[mid+1])
                left = mid + 2;
            else
                right = mid;
        }
        return nums[left];
    }
};
