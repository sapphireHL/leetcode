class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> copy(nums.size()*2, -1);
        vector<int> result(nums.size(), -1);
        for(int i=0; i<nums.size(); i++){
            copy[i] = nums[i];
        }
        for(int i=nums.size(); i<nums.size()*2; i++){
            copy[i] = nums[i-nums.size()];
        }
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<copy.size(); j++){
                if(copy[j] > copy[i]){
                    result[i] = copy[j];
                    break;
                }
            }
        }
        return result;
    }
};
