class Solution {
public:
    int res = 0;
    vector<vector<int>> visit;
    void dfs(vector<vector<int>>& grid, int m, int n, int i, int j, int& count){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0){
            res = max(res, count);
            return;
        }
        if(visit[i][j]) return;
        visit[i][j] = 1;
        count++;
        dfs(grid, m, n, i-1, j, count);
        dfs(grid, m, n, i+1, j, count);
        dfs(grid, m, n, i, j-1, count);
        dfs(grid, m, n, i, j+1, count);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        const int m = grid.size(), n = grid[0].size();
        visit.resize(m, vector<int>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visit[i][j] && grid[i][j] == 1){
                    int count = 0;
                    dfs(grid, m, n, i, j, count);
                }
            }
        }
        return res;
    }
};
