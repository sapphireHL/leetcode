class Solution {
public:
    void dfs(int &res, vector<int>&p, int N, vector<int>&use){
        if(p.size() == N) {
            res++;
            return;
        }
        for(int i=1; i<=N; i++){
            if(!use[i] && (i%(p.size()+1) == 0 || (p.size()+1)%i == 0)){
                p.push_back(i);
                use[i] = 1;
                dfs(res, p, N, use);
                p.pop_back();
                use[i] = 0;
            }
        }
    }
    int countArrangement(int N) {
        int res = 0;
        vector<int> use(N+1);
        vector<int> p;
        dfs(res, p, N, use);
        return res;
    }
};
