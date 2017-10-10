class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> sum = {0};
        for(int i:nums) 
            sum.push_back(sum.back()+i);
        
        //中间区间起点为i时，使得左区间和最大的左区间的起点
        vector<int> posleft(n, 0);
        int leftsum = sum[k]-sum[0], leftmaxsumIndex = 0;
        for(int i=k+1; i<=n-2*k; i++){
            if(sum[i]-sum[i-k] > leftsum){
                posleft[i] = i-k;
                leftsum = sum[i]-sum[i-k];
                leftmaxsumIndex = i-k;
            }
            else{
                posleft[i] = leftmaxsumIndex;
            }
        }
        
        vector<int> posright(n, n-k);
        int rightsum = sum[n]-sum[n-k], rightmaxsumIndex = n-k;
        for(int i=n-2*k; i>=k; i--){
            //>=!
            if(sum[i+2*k]-sum[i+k] >= rightsum){
                posright[i] = i+k;
                rightsum = sum[i+2*k]-sum[i+k];
                rightmaxsumIndex = i+k;
            }
            else{
                posright[i] = rightmaxsumIndex;
            }
        }
        
        vector<int> res;
        int maxsum = 0;
        for(int i=k; i<=n-2*k; i++){
            int l = posleft[i], r = posright[i];
            int total = sum[l+k]-sum[l] + sum[i+k]-sum[i] + sum[r+k]-sum[r];
            if(total > maxsum){
                maxsum = total;
                res = {l, i, r};
            }
        }
        return res;
    }
};
