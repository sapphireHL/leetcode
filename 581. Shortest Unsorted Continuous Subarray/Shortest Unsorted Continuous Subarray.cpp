class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy = nums;
        int left = 0, right = -1;
        sort(copy.begin(), copy.end());
        for(int i=0; i<copy.size(); i++){
            if(copy[i] != nums[i]){
                left = i;
                break;
            }
        }
        for(int i=nums.size()-1; i>=0; i--){
            if(copy[i] != nums[i]){
                right = i;
                break;
            }
        }
        return right-left+1;
    }
};
