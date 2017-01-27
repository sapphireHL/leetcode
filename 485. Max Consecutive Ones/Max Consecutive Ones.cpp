class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0;
        int max = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                max++;
                if(i == nums.size()-1){
                    return max>result?max:result;
                }
            }
            else{
                if(max > result){
                    result = max;
                }
                max = 0;
            }
        }
        return result;
    }
};
