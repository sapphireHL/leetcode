class Solution {
public:
    int integerBreak(int n) {
        vector<int> f(n+1, 1);
        for(int i=2; i<=n; i++){
            for(int j=2; j<i; j++){
                int cur = j*max(f[i-j], i-j);
                f[i] = max(f[i], cur);
            }
        }
        return f[n];
    }
};
