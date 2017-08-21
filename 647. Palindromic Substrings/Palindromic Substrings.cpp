class Solution {
public:
    int countSubstrings(string s) {
        const int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        int res = 0;
        for(int i=n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                dp[i][j] = (s[i] == s[j]) && (j-i<3 || dp[i+1][j-1]);
                if(dp[i][j]) res++;
            }
        }
        return res;
    }
};

