class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> findtable(nums.size(), -1);
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[j] > nums[i]){
                    findtable[i] = nums[j];
                    break;
                }
            }
        }
        for(int i=0; i<findNums.size(); i++){
            for(int j=0; j<nums.size(); j++){
                if(findNums[i] == nums[j]){
                    result.push_back(findtable[j]);
                    break;
                }
            }
        }
        return result;
    }
};
