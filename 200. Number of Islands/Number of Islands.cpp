class Solution {
public:
    vector<vector<int>> visit;
    void dfs(vector<vector<char>>& grid, int m, int n, int i, int j){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == '0' || visit[i][j] == 1) return;
        visit[i][j] = 1;
        dfs(grid, m, n, i-1, j);
        dfs(grid, m, n, i+1, j);
        dfs(grid, m, n, i, j-1);
        dfs(grid, m, n, i, j+1);
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        const int m = grid.size(), n = grid[0].size();
        visit.resize(m, vector<int>(n));
        int res = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(!visit[i][j] && grid[i][j] == '1'){
                    dfs(grid, m, n, i, j);
                    res++;
                }
            }
        }
        return res;
    }
};
