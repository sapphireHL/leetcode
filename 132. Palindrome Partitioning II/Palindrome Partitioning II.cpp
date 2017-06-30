class Solution {
public:

//Calculate and maintain 2 DP states:
//p[i][j] , which is whether s[i..j] forms a pal
//dp[i], which
//is the minCut for s[i..n-1]
//Once we comes to a pal[i][j]==true:
//if j==n-1, the string s[i..n-1] is a Pal, minCut is 0, dp[i]=0;
//else: the current cut num (first cut s[i..j] and then cut the rest
//s[j+1...n-1]) is 1+dp[j+1], compare it to the exisiting minCut num
//dp[i], repalce if smaller.
//dp[0] is the answer.

    int minCut(string s) {
        const int n = s.size();
        vector<int> dp(n+1);
        vector<vector<int>> p(n, vector<int>(n));
        dp[n] = -1;//n-1-n
        
        for(int i=n-1; i>=0; i--){
            dp[i] = n-1-i;
            for(int j=i; j<n; j++){
                if(s[i] == s[j] && (j-i<2 || p[i+1][j-1])){
                    p[i][j] = 1;
                    dp[i] = min(dp[i], dp[j+1]+1);
                }
            }
        }
        return dp[0];
    }
};
