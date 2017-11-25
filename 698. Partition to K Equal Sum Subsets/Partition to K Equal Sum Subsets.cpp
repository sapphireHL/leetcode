class Solution {
public:
    bool flag = false;
	void dfs(vector<int>&nums, vector<int>&visit, int sum, int index, int len, int k) {
		if (flag) return;
		if (sum > len) return;
		if (sum == len) {
			dfs(nums, visit, 0, 0, len, k - 1);
		}
		if (k == 0) {
			flag = true;
			return;
		}
		for (int i = index; i<nums.size(); i++) {
			if (!visit[i]) {
				sum += nums[i];
				visit[i] = 1;
				dfs(nums, visit, sum, i+1, len, k);
				sum -= nums[i];
				visit[i] = 0;
			}
		}
	}
    //the same as 473. Matchsticks to Square
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int i:nums) sum += i;
        if(sum % k != 0) return false;
        int len = sum / k;
        vector<int> visit(nums.size());
        dfs(nums, visit, 0, 0, len, k);
        return flag;
    }
};
