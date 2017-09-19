class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        const int n = nums.size();
        vector<int> dp(n, 0);
        for(int i=0; i<n; i++){
            if(i == 0) dp[i] = nums[i];
            else if(i>0 && i<2) dp[i] = max(dp[i-1], nums[i]);
            else dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};
