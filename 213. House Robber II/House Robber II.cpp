class Solution {
public:
    int rob1(vector<int>& nums, int start, int end) {
        if(nums.empty()) return 0;
        const int n = nums.size();
        vector<int> dp(n, 0);
        for(int i=start; i<=end; i++){
            if(i == start) dp[i] = nums[i];
            else if(i>start && i<start+2) dp[i] = max(dp[i-1], nums[i]);
            else dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[end];
    }
    int rob(vector<int>& nums) {
        const int n = nums.size();
        if(n == 1) return nums[0];
        return max(rob1(nums, 0, n-2), rob1(nums, 1, n-1));
    }
};
