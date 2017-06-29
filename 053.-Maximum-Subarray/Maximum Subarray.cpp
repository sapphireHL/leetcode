class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, current = 0;
        for(int i=0; i<nums.size(); i++){
            if(current >= 0)
                current += nums[i];
            else 
                current = nums[i];
            res = max(current, res);
        }
        return res;
    }
};
