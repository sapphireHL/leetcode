class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        const int n = prices.size();
        vector<int> buy(n+1), sell(n+1), rest(n+1);
        buy[0] = -prices[0];
        sell[0] = INT_MIN;
        rest[0] = 0;
        for(int i=1; i<=prices.size(); i++){
            rest[i] = max(rest[i-1], sell[i-1]);
            buy[i] = max(buy[i-1], rest[i-1]-prices[i-1]);
            sell[i] = buy[i-1]+prices[i-1];
        }
        return max(sell[n], rest[n]);
    }
};
