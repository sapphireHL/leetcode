class Solution {
public:
    struct node{
        int val;
        int i;
        int j;
        node(int v = INT_MAX, int ii = 0, int jj = 0) : val(v), i(ii), j(jj){}
        friend bool operator<(node a, node b) {
            return a.val > b.val;
        }
    };
    
    int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
    int swimInWater(vector<vector<int>>& grid) {
        //最小堆
        priority_queue<node> q;
        const int n = grid.size();
        int res = 0;
        vector<vector<int>> visit(n, vector<int>(n));
        q.push(node(grid[0][0], 0, 0));
        while(!q.empty()){
            node cur = q.top();
            q.pop();
            visit[cur.i][cur.j] = 1;
            res = max(res, cur.val);
            if(cur.i == n-1 && cur.j == n-1){
                return res;
            }
            for(int i = 0; i < 4; i++){
                int newi = cur.i + dir[i][0];
                int newj = cur.j + dir[i][1];
                if(newi >= 0 && newi < n && newj >= 0 && newj < n && !visit[newi][newj]){
                    q.push(node(grid[newi][newj], newi, newj));
                    visit[newi][newj] = 1;
                }
            }
        }
        return 1;
    }
};
