class Solution {
public:
    int dir[8][2] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
    double knightProbability(int N, int K, int r, int c) {
        //用int出错
        vector<vector<double>> pre(N, vector<double>(N)), cur(N, vector<double>(N));
        pre[r][c] = 1;
        cur[r][c] = 1;
        for(int k=0; k<K; k++){
            cur.assign(N, vector<double>(N, 0));
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    if(pre[i][j] != 0){
                        for(int d=0; d<8; d++){
                            int ni = i + dir[d][0];
                            int nj = j + dir[d][1];
                            if(ni >= 0 && ni < N && nj >= 0 && nj < N)
                                cur[ni][nj] += pre[i][j];
                        }
                    }
                }
            }
            pre = cur;
        }
        double res = 0.0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(cur[i][j] != 0)
                    res += cur[i][j];
            }
        }
        return res / pow(8, K);
    }
};
