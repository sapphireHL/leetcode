class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //next_permutation(nums.begin(), nums.end());
        
        if(nums.size() == 1) return;
        int swappos1 = -1, swappos2 = -1;
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                swappos1 = i;
                break;
            }
        }
        if(swappos1 == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i=nums.size()-1; i>swappos1; i--){
            if(nums[i] > nums[swappos1]){
                swappos2 = i;
                break;
            }
        }
        swap(nums[swappos1], nums[swappos2]);
        vector<int>::iterator left = nums.begin();
        advance(left, swappos1+1);
        reverse(left, nums.end());
    }
};
