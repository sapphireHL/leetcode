class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minp = INT_MAX, res=0;
        for(int i=0; i<prices.size(); i++){
            minp = min(minp, prices[i]);
            res = max(res, prices[i]-minp);
        }
        return res;
    }
};
