class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0, mask = 0;
        for(int i=31; i>=0; i--){
            unordered_set<int> set;
            mask |= (1<<i);
            for(int j=0; j<nums.size(); j++){
                set.insert(nums[j] & mask);
            }
            
            int prefix = res | (1<<i);
            for(auto i:set){
                if(set.count(i ^ prefix)){
                    res = prefix;
                }
            }
        }
        return res;
    }
};
