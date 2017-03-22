class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int count = 2;
        for(int i = 2; i < nums.size(); i++){
            if(nums[i] != nums[count-2])
                nums[count++] = nums[i];
        }
    	return count;
    }
};
