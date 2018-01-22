class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m + n - 1; i++){
            int mm, nn;
            if(i < m){
                mm = m - 1 - i;
                nn = 0;
            }
            else{
                mm = 0;
                nn = n -1 - (i - m);;
            }
            //cout<<mm <<' '<<nn<<endl;
            int cur = matrix[mm][nn];
            for(; mm < m && nn < n; mm++, nn++){
                if(matrix[mm][nn] != cur)
                    return false;
            }
        }
        return true;
    }
};
