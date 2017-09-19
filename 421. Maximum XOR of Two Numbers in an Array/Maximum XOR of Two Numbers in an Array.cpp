class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0, mask = 0;
        for(int i=31; i>=0; i--){
            unordered_set<int> set;
            mask |= (1<<i);
            //计算出每个数字的最高i位
            for(int j=0; j<nums.size(); j++){
                set.insert(nums[j] & mask);
            }
            //假设第i位为1， a^b=c -> a^c=b   b^c=a
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
