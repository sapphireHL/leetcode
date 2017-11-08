class Solution {
public:
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    const int mod = 1000000007;
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<long long>> pre(m, vector<long long>(n)), cur(m, vector<long long>(n));
        pre[i][j] = 1.0;
        cur[i][j] = 1.0;
        long long res = 0;
        for(int t=0; t<N; t++){
            cur.assign(m, vector<long long>(n, 0.0));
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(pre[i][j] != 0){
                        for(int d=0; d<4; d++){
                            int row = i+dir[d][0];
                            int col = j+dir[d][1];
                            if(row>=0 && row<m && col>=0 && col<n){
                                cur[row][col] += pre[i][j];
                                cur[row][col] %= mod;
                            }
                            else{
                                res += pre[i][j];
                                res %= mod;
                            }
                        }
                    }
                }
            }
            pre = cur;
        }
        return res;
    }
};
