class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> index;
        for(int i=0; i<nums.size(); i++){
            if(index.count(target-nums[i])){
                res.push_back(index[target-nums[i]]);
                res.push_back(i);
                break;
            }
            index[nums[i]] = i;
        }
        return res;
    }
};
