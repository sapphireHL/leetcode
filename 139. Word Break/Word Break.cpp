class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int n = s.size();
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        vector<int> dp(n+1);
        dp[0]=1;
        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                if(dp[j] && set.find(s.substr(j, i-j))!=set.end())
                    dp[i] = 1;
            }
        }
        return dp[n];
    }
};
