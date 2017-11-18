class Solution {
public:
    const int N = 2000;
    int parent[2000];
    
    void init(){
        for(int i=0; i<N; i++)
            parent[i] = i;
    }
    
    int find(int x){
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init();
        for(int i=0; i<edges.size(); i++){
            int pa = find(edges[i][0]), pb = find(edges[i][1]);
            if(pa == pb)
                return edges[i];
            else
                parent[pa] = pb;
        }
        return vector<int>{};
    }
};
