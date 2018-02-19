class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        if(n == 0) return 0;
        int res = nums[0];
        //以第i位结尾的最大最小值
        int localmax = nums[0], localmin = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] < 0) swap(localmax, localmin);
            localmax = max(localmax*nums[i], nums[i]);
            localmin = min(localmin*nums[i], nums[i]);
            res = max(res, localmax);
        }
        return res;
    }
};
