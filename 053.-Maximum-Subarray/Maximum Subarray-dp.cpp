class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        int res = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};
