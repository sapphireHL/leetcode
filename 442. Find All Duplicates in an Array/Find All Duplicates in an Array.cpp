class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size, 0);
        for(int i=0; i<size; i++){
            result[nums[i]-1] += nums[i];
        }
        for(int i=0; i<size; i++){
            if(result[i] == 2*(i+1)){
                nums.push_back(i+1);
            }
        }
        result.resize(0);
        for(int i=size; i<nums.size(); i++){
            result.push_back(nums[i]);
        }
        return result;
    }
};
