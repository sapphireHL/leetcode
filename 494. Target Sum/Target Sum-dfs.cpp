class Solution {
public:
    int res = 0;

    void dfs(vector<int>& nums, int S, int pos, int sum){
        if(pos == nums.size()){
            if(sum == S) res++;
            return;
        }
        dfs(nums, S, pos+1, sum+nums[pos]);
        dfs(nums, S, pos+1, sum-nums[pos]);
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        dfs(nums, S, 0, 0);
        return res;
    }
};
