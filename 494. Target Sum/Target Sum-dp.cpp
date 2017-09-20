class Solution {
public:
    int subsetSum(vector<int>& nums, int s){
        vector<int> dp(s+1);
        dp[0] = 1;
        for(int i=0; i<nums.size(); i++){
            for(int j=s; j>=nums[i]; j--){
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[s];
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        //sum(p) - sum(N) = S
        //sum(p) - sum(N) + sum(p) + sum(N) = S + sum(nums)
        //sum(p) * 2 = S + sum(nums)
        //sum(p) = (S + sum(nums)) / 2
        //subsetsum problem
        int sum = 0;
        for(auto i:nums) sum += i;
        if(sum < S || (S+sum) % 2 == 1) return 0;
        return subsetSum(nums, (S+sum)/2);
    }
};
