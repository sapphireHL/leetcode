class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        const int n = s1.size();
        int dp[n+1][n][n]={0};
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dp[1][i][j] = s1[i] == s2[j];
            }
        }
        for(int m=2; m<=n; m++){
            for(int i=0; i+m<=n; i++){
                for(int j=0; j+m<=n; j++){
                    for(int k=1; k<m; k++)
                        if((dp[k][i][j] && dp[m-k][i+k][j+k]) || (dp[k][i][j+m-k] && dp[m-k][i+k][j])){
                            dp[m][i][j] = 1;
                        }
                }
            }
        }
        return dp[n][0][0];
    }
};
