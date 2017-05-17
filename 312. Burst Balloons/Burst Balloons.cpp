class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector<vector<int>> f(nums.size(), vector<int>(nums.size()));
        
        for(int len = 1; len<=n; len++){
            for(int start = 1; start<=n-len+1; start++){
                int end = start+len-1;
                int maxc = 0;
                for(int j=start; j<=end; j++){
                    int c = f[start][j-1]+f[j+1][end];
                    c += nums[start-1] * nums[j] * nums[end+1];
                    if(c > maxc) maxc = c;
                }
                f[start][end] = maxc;
            }
        }
        return f[1][n];
    }
};
