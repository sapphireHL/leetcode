class Solution {
public:
    void twoSum(vector<int>& nums, int pos, int target, vector<vector<int>>& result) {
        int left = pos+1, right = nums.size()-1;
        while(left < right){
            if(nums[left]+nums[right] > target)
                right--;
            else if(nums[left]+nums[right] < target)
                left++;
            else{
                result.push_back({nums[pos], nums[left], nums[right]});
                right--;
                while(right > left && nums[right] == nums[right+1])
                    right--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.empty()) return result;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i++){
            if(i >= 1 && nums[i] == nums[i-1])  continue;
            int target = -nums[i];
            twoSum(nums, i, target, result);
        }
        return result;
    }
};
