class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int, int> m;
        for(int i=0; i<nums.size(); i++)
            m[nums[i]] = i;
        for(int i=0; i<nums.size(); i++){
            int gap = target - nums[i];
            if(m.find(gap) != m.end() && m[gap] > i){
                res.push_back(i);
                res.push_back(m[gap]);
                break;
            }
        }
        return res;
    }
};
