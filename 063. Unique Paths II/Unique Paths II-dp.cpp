class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> f(m+1, vector<int>(n+1));
        for(int i=0; i<m; i++){
            if(!obstacleGrid[i][0]) f[i][0]=1;
            else break;
        }
        for(int j=0; j<n; j++) {
            if(!obstacleGrid[0][j]) f[0][j]=1;
            else break;
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                f[i][j] = !obstacleGrid[i][j]?f[i-1][j]+f[i][j-1]:0;
            }
        }
        return f[m-1][n-1];
    }
};
