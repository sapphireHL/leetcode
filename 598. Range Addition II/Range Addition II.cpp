class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(m == 0 || n == 0) return 0;
        int minrow = INT_MAX, mincol = INT_MAX;
        for(int i=0; i<ops.size(); i++){
            if(ops[i][0] < minrow) minrow = ops[i][0];
            if(ops[i][1] < mincol) mincol = ops[i][1];
        }
        minrow = minrow>m?m:minrow;
        mincol = mincol>n?n:mincol;
        return minrow*mincol;
    }
};
