class Solution {
public:
    int maxProfit(vector<int>& prices) {
    //dp1[i] is maxprofit of prices[0]~prices[i]
    //dp2[i] is maxprofit of prices[i]~prices[n-1]
    //res = max(dp1[i]+dp2[i])
    
        if(prices.size() <= 1) return 0;
        int res = 0, buy = prices[0];
        const int n = prices.size();
        vector<int> dp1(n), dp2(n);
        for(int i=1; i<n; i++){
            buy = min(buy, prices[i]);
            dp1[i] = max(dp1[i-1], prices[i]-buy);
        }
        buy = prices[n-1];
        for(int i=n-2; i>=0; i--){
            buy = max(buy, prices[i]);
            dp2[i] = max(dp2[i+1], buy - prices[i]);
            res = max(res, dp1[i]+dp2[i]);
        }
        return res;
    }
};
