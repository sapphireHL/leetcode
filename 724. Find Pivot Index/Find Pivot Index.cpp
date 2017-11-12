class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        const int n = nums.size();
        vector<int> sum{0};
        for(int i=0; i<n; i++){
            sum.push_back(sum.back() + nums[i]);
        }
        for(int i=0; i<n; i++){
            if(sum[i] == sum[n]-sum[i+1])
                return i;
        }
        return -1;
    }
};
