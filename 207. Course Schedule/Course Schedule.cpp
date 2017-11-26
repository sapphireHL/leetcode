class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& visit, int cur, int end){
        if(cur == end) return true;
        for(int i=0; i<graph[cur].size(); i++){
            int next = graph[cur][i];
            if(!visit[next]){
                visit[next] = 1;
                if(dfs(graph, visit, next, end))
                    return true;
                //visit[next] = 0;
            }
        }
        return false;
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        //vector<int> visit(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            int from = prerequisites[i].first, to = prerequisites[i].second;
            vector<int> visit(numCourses);
            if(dfs(graph, visit, from, to) && dfs(graph, visit, to, from))
                return false;
        }
        return true;
    }
};
