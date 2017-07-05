class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    //dp[i][j]表示s1[0,i]，s2[0,j]匹配s3[0, i+j].
    //dp[i][j] = (s1[i - 1] == s3 [i + j - 1] && dp[i - 1][j] || (s2[j - 1] == s3 [i + j - 1] && dp[i][j - 1])
    
    
        // if(s1.size()+s2.size() != s3.size()) return false;
        // const int m = s1.size(), n = s2.size();
        // vector<vector<int>> dp(m+1, vector<int>(n+1, 1));
        // for(int i=0; i<m; i++) dp[i+1][0] = (s1[i] == s3[i]) && (dp[i][0]);
        // for(int j=0; j<n; j++) dp[0][j+1] = (s2[j] == s3[j]) && (dp[0][j]);
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         dp[i+1][j+1] = (s1[i]==s3[i+j+1] && dp[i][j+1]) || (s2[j]==s3[i+j+1] && dp[i+1][j]);
        //     }
        // }
        // return dp[m][n];
        
        //optimized
        if(s1.size()+s2.size() != s3.size()) return false;
        if(s1.size() < s2.size()) return isInterleave(s2, s1, s3);
        const int m = s1.size(), n = s2.size();
        vector<int> dp(n+1,1);
        for(int j=0; j<n; j++) dp[j+1] = (s2[j] == s3[j]) && (dp[j]);
        
        for(int i=0; i<m; i++){
            dp[0] = (s1[i] == s3[i]) && (dp[0]);
            for(int j=0; j<n; j++){
                dp[j+1] = (s1[i]==s3[i+j+1] && dp[j+1]) || (s2[j]==s3[i+j+1] && dp[j]);
            }
        }
        return dp[n];
    }
};
