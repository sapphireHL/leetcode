class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<int> visit;
    
    void dfs(vector<vector<int>>& graph, const int& n, int cur){
        if(cur == n-1){
            res.push_back(path);
            return;
        }
        for(int i = 0; i < graph[cur].size(); i++){
            int next = graph[cur][i];
            if(!visit[next]){
                visit[next] = 1;
                path.push_back(next);
                dfs(graph, n, next);
                path.pop_back();
                visit[next] = 0;
            }
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        const int n = graph.size();
        visit.resize(n);
        path.push_back(0);
        dfs(graph, n, 0);
        return res;
    }
};
