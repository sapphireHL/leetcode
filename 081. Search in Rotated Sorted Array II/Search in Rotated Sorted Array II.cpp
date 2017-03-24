class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0) return false;
        int left = nums[0], right = nums[nums.size()-1], mid = 0;
        if(target >= left){
            for(int i=0; i<nums.size() && target >= nums[i]; i++){
                if(target == nums[i]) 
                    return true;
            }
        }
        else{
            for(int i=nums.size()-1; i>=0 && target <= nums[i]; i--){
                if(target == nums[i])
                    return true;
            }
        }
        return false;
    }
};
