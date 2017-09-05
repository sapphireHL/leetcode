class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        // for(int i=1; i<=numRows; i++){
        //     vector<int> row(i);
        //     row[0] = row[i-1] = 1;
        //     for(int j=1; j<i-1; j++){
        //         if(i > 0){
        //             row[j] = res.back()[j-1] + res.back()[j];
        //         }
        //     }
        //     res.push_back(row);
        // }
        for(int i=0; i<numRows; i++){
            res[i].resize(i+1, 0);
            for(int j=0; j<=i; j++){
                if(i == 0 || j == 0 || j == i) res[i][j] = 1;
                else res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
        return res;
    }
};
