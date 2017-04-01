class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = 0, min = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            int j = i+1, k = nums.size()-1;
            while(j < k){
                if(abs(nums[i]+nums[j]+nums[k]-target) < min){
                    min = abs(nums[i]+nums[j]+nums[k]-target);
                    result = nums[i]+nums[j]+nums[k];
                }
                if(nums[i]+nums[j]+nums[k] < target)
                    j++;
                else if(nums[i]+nums[j]+nums[k] > target)
                    k--;
                else{
                    result = target;
                    break;
                }
            }
            if(result == target) break;
        }
        return result;
    }
};
