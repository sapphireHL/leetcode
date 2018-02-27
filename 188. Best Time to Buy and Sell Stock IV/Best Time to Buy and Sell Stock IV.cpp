class Solution {
public:
    int allProfit(vector<int>& prices){
        int res = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > prices[i-1]){
                res += prices[i] - prices[i-1];
            }
        }
        return res;
    }
    int maxProfit(int k, vector<int>& prices) {
        const int n = prices.size();
        if(n <= 1) return 0;
        if(k >= n / 2) return allProfit(prices);
        //dp[k][i] = max(dp[k][i-1], dp[k-1][j-1] + p[i] - p[j](j=1,2...i-1))
        vector<vector<int>> dp(k+1, vector<int>(n));
        for(int kk = 1; kk <= k; kk++){
            int tmpMax = dp[kk-1][0] - prices[0];
            for(int i = 1; i < n; i++){
                dp[kk][i] = max(dp[kk][i-1], prices[i] + tmpMax);
                tmpMax = max(tmpMax, dp[kk-1][i-1] - prices[i]);
            }
        }
        return dp[k][n-1];
    }
};
