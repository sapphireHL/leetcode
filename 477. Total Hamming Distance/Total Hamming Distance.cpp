class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        //从最低位开始比较每一位，数出0和1的个数p,q,距离加p*q
        int res = 0, n = nums.size(), ones = 0;
        for(int i=0; i<32; i++){
            ones = 0;
            for(int j=0; j<n; j++){
                if((nums[j] & (1<<i)) != 0) ones++;
            }
            res += ones*(n-ones);
        }
        return res;
    }
};
