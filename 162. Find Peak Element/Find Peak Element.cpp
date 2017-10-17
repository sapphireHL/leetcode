class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // if(nums.size() <= 1) return 0;
        // for(int i=0; i<nums.size(); i++){
        //     if(i == 0 && nums[0] > nums[1]) return i;
        //     if(i == nums.size()-1 && nums[i] > nums[i-1]) return i;
        //     if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) return i;
        // }
        // return 0;
        int left = 0, right = nums.size()-1;
        while(left < right){
            int mid = left + (right-left)/2;
            if(nums)
            if(nums[mid] > nums[mid+1])
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
};
