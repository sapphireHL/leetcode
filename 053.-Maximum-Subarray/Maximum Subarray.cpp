class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MAX, current = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < max){
                max = nums[i];
            }
        }
        for(int i=0; i<nums.size(); i++)
        {
            current += nums[i];
            if(current > max){
                max = current;
            }
            if(current < 0){
                current = 0;
            }
        }
        return max;
    }
};
