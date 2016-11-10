class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxn = nums[0], minn = nums[0], maxpo = 0;
        for(int i=0; i<nums.size(); i++){
            if(maxn < nums[i]){
                maxn = nums[i];
                maxpo = i;
            }
            if(minn > nums[i]){
                minn = nums[i];
            }
        }
        int res = maxn - minn;
        for(int i=0; i<nums.size(); i++){
            if(i != maxpo){
                res += nums[i] - minn;
            }
        }
        return res;
    }
};
