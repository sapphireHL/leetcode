class Solution {
public:
    bool subsetSum(vector<int>& nums, int target){
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        for(int i=0; i<nums.size(); i++){
            for(int j=target; j>=nums[i]; j--){
                dp[j] += dp[j-nums[i]];
            }
            if(dp[target] > 0) return true;
        }
        return false;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto n:nums) sum += n;
        if(sum % 2 == 1) return false;
        return subsetSum(nums, sum / 2);
    }
};
