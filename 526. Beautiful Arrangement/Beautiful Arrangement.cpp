class Solution {
public:
    void dfs(int &res, int N, vector<int>&use, int pos){
        if(pos > N) {
            res++;
            return;
        }
        for(int i=1; i<=N; i++){
            if(!use[i] && (i%pos == 0 || pos%i == 0)){
                use[i] = 1;
                dfs(res, N, use, pos+1);
                use[i] = 0;
            }
        }
    }
    int countArrangement(int N) {
        int res = 0, pos = 1;
        vector<int> use(N+1);
        dfs(res, N, use, pos);
        return res;
    }
};
