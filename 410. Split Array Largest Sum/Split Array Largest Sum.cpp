class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        const int n = nums.size();
        //dp[i][k] 表示将前i个数切分成k组的结果
        //dp[i][k] = min{max(dp[j][k-1], sum(j+1, i))}, 1<=j<i
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        dp[1][1] = nums[0];
        vector<int> sum{0};
        for(int i:nums) sum.push_back(sum.back()+i);
        for(int i=1; i<=n; i++) dp[i][1] = sum[i];
        for(int k=2; k<=m; k++){
            for(int i=2; i<=n; i++){
                dp[i][k] = INT_MAX;
                int localmax = 0;
                for(int j=1; j<i; j++){
                    int localmax = max(dp[j][k-1], sum[i]-sum[j]);
                    dp[i][k] = min(dp[i][k], localmax);
                }
            }
        }
        return dp[n][m];
    }
};
