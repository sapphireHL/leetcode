class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(string s:strs){
            int zeros = 0, ones = 0;
            for(int i=0; i<s.size(); i++){
                if(s[i] == '1') ones++;
                else zeros++;
            }
            for(int i=m; i>=zeros; i--){
                for(int j=n; j>=ones; j--){
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones]+1);
                }
            }
        }
        return dp[m][n];
    }
};
