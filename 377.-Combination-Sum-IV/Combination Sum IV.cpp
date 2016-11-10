class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> result(target+1, 0);
        result[0] = 1;
        for(int i=1; i<=target; i++){
            for(int j:nums){
                if(i >= j){
                    result[i] += result[i-j];
                }
            }
        }
        return result[target];
    }
};
