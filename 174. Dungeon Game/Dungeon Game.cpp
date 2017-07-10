class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        const int m=dungeon.size();
        if(m==0) return 0;
        const int n = dungeon[0].size();
        vector<vector<int>> minhp(m+1, vector<int>(n+1, INT_MAX));
        minhp[m][n-1] = 1;
        minhp[m-1][n] = 1;
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                int life = min(minhp[i+1][j], minhp[i][j+1])-dungeon[i][j];
                minhp[i][j] = life<=0?1:life;
            }
        }
        return minhp[0][0];
    }
};
