class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0, sum = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            result += m[sum-k];
            m[sum]++;
        }
        return result;
    }
};
