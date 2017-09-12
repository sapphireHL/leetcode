class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int res = 0, len = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > nums[i-1])
                len++;
            else{
                res = max(res, len);
                len = 1;
            }
        }
        res = max(res, len);
        return res;
    }
};
