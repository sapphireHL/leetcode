class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        const int n = prices.size();
        if(n == 0) return 0;
        vector<int> have(n+1), nothave(n+1);
        have[0] = -prices[0];
        for(int i=1; i<=n; i++){
            have[i] = max(have[i-1], nothave[i-1]-prices[i-1]);
            nothave[i] = max(nothave[i-1], have[i-1]+prices[i-1]-fee);
        }
        return nothave[n];
    }
};
