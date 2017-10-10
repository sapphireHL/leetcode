class NumMatrix {
public:
    vector<vector<int>> row;//row[i][j] 第i行前j个元素和
    vector<vector<int>> dp;
    //row[i][j] = row[i][j-1]+matrix[i][j]
    //dp[i][j] = dp[i-1][j] + row[i][j];
    //积分图
    
    NumMatrix(vector<vector<int>> matrix) {
        if(matrix.empty()) return;
        const int m = matrix.size(), n = matrix[0].size();
        row.resize(m + 1, vector<int>(n + 1));
        dp.resize(m + 1, vector<int>(n + 1));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                row[i][j] = row[i][j-1] + matrix[i-1][j-1];
                dp[i][j] = dp[i-1][j] + row[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        return dp[row1][col1] + dp[row2+1][col2+1] - dp[row1][col2+1] - dp[row2+1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
