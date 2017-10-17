class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        vector<vector<int>> reverse(nums.size()+1);
        for(auto i : nums) ++counts[i];
        for(auto  i : counts) {
            reverse[i.second].push_back(i.first);
        }
        vector<int> res;
        for(int i=nums.size(); i>=0; i--){
            for(int j=0; j<reverse[i].size(); j++){
                res.push_back(reverse[i][j]);
                if(res.size() == k)
                    return res;
            }
        }
        return res;
    }
};
