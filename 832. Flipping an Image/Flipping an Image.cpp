class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> res;
        for(int i=0; i<A.size(); ++i){
            reverse(A[i].begin(), A[i].end());
            res.push_back(A[i]);
        }
        for(int i=0; i<A.size(); ++i){
            for(int j=0; j<A[i].size(); ++j){
                res[i][j] = !res[i][j];
            }
        }
        return res;
    }
};
