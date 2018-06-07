class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int res = 0;
        if(grid.empty()) return res;
        const int n = grid.size(), m = grid[0].size();
        vector<vector<int>> maxh = grid;
        //每行最大值
        for(int i=0; i<n; ++i){
            int maxinline = INT_MIN;
            for(int j=0; j<m; ++j)
                maxinline = max(maxinline, grid[i][j]);
            for(int j=0; j<m; ++j)
                maxh[i][j] = maxinline;
        }
        //每列最大值
        for(int j=0; j<m; ++j){
            int maxincol = INT_MIN;
            for(int i=0; i<n; ++i)
                maxincol = max(maxincol, grid[i][j]);
            for(int i=0; i<n; ++i)
                maxh[i][j] = min(maxh[i][j], maxincol);
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                res += maxh[i][j] - grid[i][j];
            }
        }
        return res;
    }
};
