class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int left = nums[0], right = nums[nums.size()-1], mid = 0;
        if(target >= left){
            for(int i=0; i<nums.size() && target >= nums[i]; i++){
                if(target == nums[i]) 
                    return i;
            }
        }
        else{
            for(int i=nums.size()-1; i>=0 && target <= nums[i]; i--){
                if(target == nums[i])
                    return i;
            }
        }
        return -1;
    }
};
