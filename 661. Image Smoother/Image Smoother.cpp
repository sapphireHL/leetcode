class Solution {
public:
    int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        const int n = M.size(), m = M[0].size();
        vector<vector<int>> res(n, vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int count = 1;
                int sum = M[i][j];
                for(int k=0; k<8; k++){
                    int x = i+dir[k][0];
                    int y = j+dir[k][1];
                    if(x>=0 && x<n && y>=0 && y<m){
                        sum += M[x][y];
                        count++;
                    }
                }
                res[i][j] = sum / count;
            }
        }
        return res;
    }
};
