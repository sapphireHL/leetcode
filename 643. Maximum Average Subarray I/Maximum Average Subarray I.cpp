class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int res = 0, prev = 0, cur = 0, n=nums.size();
        for(int i=0; i<k; i++)
            prev+=nums[i];
        res = prev;
        for(int i=1; i<=n-k; i++){
            cur = prev+nums[i+k-1]-nums[i-1];
            prev = cur;
            res = max(res, cur);
        }
        return res*1.0/k;
    }
};
