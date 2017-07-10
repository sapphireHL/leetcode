class Solution {
public:
    int numDecodings(string s) {
        const int n = s.size();
        if(n==0) return 0;
        vector<int> dp(n+1, 1);
        if(s[0] == '0') return 0;
        for(int i=2; i<=n; i++){
            if(s[i-1] == '0'){
                if(s[i-2] == '1' || s[i-2] == '2'){
                    dp[i-1] = dp[i-2];
                    dp[i] = dp[i-1];
                }
                else return 0;
            }
            else if(s[i-1] >= '1' && s[i-1] <= '6' && (s[i-2]=='1'||s[i-2]=='2')) 
                dp[i] = dp[i-1]+dp[i-2];
            else if(s[i-1] >= '7' && s[i-1] <= '9' && s[i-2] == '1') 
                dp[i] = dp[i-1]+dp[i-2];
            else dp[i] = dp[i-1];
        }
        return dp[n];
    }
};
