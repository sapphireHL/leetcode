class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        if(n == 0) return 0;
        //dp[i]代表以nums[i]结尾的最大递增子序列长度
        vector<int> dp(n, 1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }
        int res = 0;
        for(int i=0; i<n; i++)
            res = max(res, dp[i]);
        return res;
    }
};
