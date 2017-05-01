class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(r*c != nums.size()*nums[0].size()) return nums;
        vector<vector<int>> result(r, vector<int>(c));
        int rr = 0, cc = 0;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums[i].size(); j++){
                result[rr][cc++] = nums[i][j];
                if(cc>=c){
                    rr++; cc = 0;
                }
            }
        }
        return result;
    }
};
