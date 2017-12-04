class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		if (nums.size() <= 1)return nums.size();
		const int n = nums.size();
		vector<int> dp(n, 1);
		vector<bool> rise(n + 1);
		dp[1] = nums[0] == nums[1] ? 1 : 2;
		rise[1] = nums[1] > nums[0] ? true : false;
		for (int i = 2; i < n; i++) {
			if (nums[i] > nums[i - 1]) {
				rise[i] = true;
				if (!rise[i - 1])
					dp[i] = dp[i - 1] + 1;
				else
					dp[i] = max(2, dp[i - 1]);
			}
			else if (nums[i] < nums[i - 1]) {
				rise[i] = false;
				if (rise[i - 1])
					dp[i] = dp[i - 1] + 1;
				else
					dp[i] = max(2, dp[i - 1]);
			}
			else {
				rise[i] = rise[i - 1];
				dp[i] = dp[i - 1];
			}
		}
		return dp[n - 1];
	}
};
