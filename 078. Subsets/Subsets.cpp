class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //类似DP，每次向res里面添加新元素
        vector<vector<int>> res;
        res.push_back(vector<int>{});
        sort(nums.begin(), nums.end());
        int n=nums.size();
        for(int i=0; i<n; i++){
            int m=res.size();
            for(int j=0; j<m; j++){
                vector<int> tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }
        return res;
    }
};
