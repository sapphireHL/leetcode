class Solution {
public:
    void dfs(vector<vector<int>> &res, vector<int> &path,  map<int, int> &times, int n){
    	if (path.size() == n){
    		res.push_back(path);
    		return;
    	}
    	for (auto &i : times){
    		if (i.second <= 0) 
    			continue;
    		i.second--;
    		path.push_back(i.first);
    		dfs(res, path, times, n);
    		path.pop_back();
    		i.second++;
    	}
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	vector<vector<int>> res;
    	vector<int> path;
    	map<int, int> times;
    	for (auto i : nums){
    		times[i]++;
    	}
    	dfs(res, path, times, nums.size());
    	return res;
    }
};
