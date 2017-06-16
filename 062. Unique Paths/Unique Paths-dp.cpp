class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> f(n, 1);
        vector<int> pre(n, 1);
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                f[j] = f[j-1]+pre[j];
            }
            pre = f;
        }
        return f[n-1];
    }
};
