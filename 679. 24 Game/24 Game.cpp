class Solution {
public:
	const double eps = 0.0001;
  
	bool res(vector<double>&nums, vector<int>&visit) {
		int count = 0, index = 0;
		for (int i = 0; i < visit.size(); i++) {
			count += visit[i];
			if (!visit[i])index = i;
		}
		if (count != visit.size() - 1) return false;
		if (abs(nums[index] - 24.0) < eps) return true;
		return false;
	}
  
	bool dfs(vector<double>&nums, vector<int>&visit) {
		if (res(nums, visit)) {
				return true;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (visit[i]) continue;
			for (int j = i + 1; j < nums.size(); j++) {
				if (!visit[i] && !visit[j]) {
					visit[i] = visit[j] = 1;
					double a = nums[i], b = nums[j];
					vector<double> tmp{ a + b,a - b,b - a,a*b };
					if (abs(a) > eps) tmp.push_back(b / a);
					if (abs(b) > eps) tmp.push_back(a / b);
					for (double n : tmp) {
						nums.push_back(n);
						visit.push_back(0);
						if (dfs(nums, visit))
							return true;
						nums.pop_back();
						visit.pop_back();
					}
					visit[i] = visit[j] = 0;
				}
			}
		}
		return false;
	}
  
	bool judgePoint24(vector<int>& nums) {
		vector<double> num(nums.begin(), nums.end());
		vector<int> visit(nums.size());
		return dfs(num, visit);
	}
};
