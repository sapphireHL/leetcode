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
	bool makesquare(vector<int>& nums) {
    if(nums.size() < 4) return false;
		int sum = 0;
		for (int i : nums) sum += i;
		if (sum % 4 != 0) return false;
		int len = sum / 4;
		vector<int> visit(nums.size());
		dfs(nums, visit, 0, 0, len, 4);
		return flag;
	}
}; 
