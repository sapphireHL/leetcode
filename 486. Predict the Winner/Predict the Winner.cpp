class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        const int n = nums.size();
        int sum = 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i=0; i<n; i++) {
            dp[i][i] = nums[i];
            sum += nums[i];
        }
        //dp[i][j] = max(min(dp[i+2][j], dp[i+1][j-1])+nums[i], min(dp[i+1][j-1], dp[i][j-2])+nums[j])
        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                int a = (i+1 < n)&&(j-1 > 0)?dp[i+1][j-1]:0;
                int b = (i+2 < n)?dp[i+2][j]:0;
                int c = (j-2 > 0)?dp[i][j-2]:0;
                dp[i][j] = max(min(a, b)+nums[i], min(a, c)+nums[j]);
            }
        }
        return dp[0][n-1]*2 >= sum;
    }
};
