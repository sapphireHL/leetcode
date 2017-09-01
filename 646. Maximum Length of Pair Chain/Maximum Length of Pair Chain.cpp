class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a.front() < b.front();
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.empty()) return 0;
        sort(pairs.begin(), pairs.end(), cmp);
        const int n = pairs.size();
        vector<int> dp(n, 1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(pairs[i][0] > pairs[j][1])
                    dp[i] = max(dp[i], dp[j]+1);
                else
                    dp[i] = max(dp[i], dp[j]);
            }
        }
        return dp[n-1];
    }
};
