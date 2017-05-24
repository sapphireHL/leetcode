class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        res.push_back(vector<int>{});
        int n=nums.size(), lastsize = 1, lastlastsize = 0;
        for(int i=0; i<n; i++){
            int m = res.size(), start = 0;
            //重复，跳过上上次的结果
            if(i>0 && nums[i] == nums[i-1]) start = lastlastsize;
            for(int j=start; j<m; j++){
                vector<int> tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
            lastlastsize = lastsize;
            lastsize = res.size();
        }
        return res;
    }
};
