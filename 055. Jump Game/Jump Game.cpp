class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxstep = 0;
        for(int i=0; maxstep>=i && i<nums.size()-1; i++){
            maxstep = max(maxstep, i+nums[i]);
        }
        return maxstep>=nums.size()-1;
    }
};
