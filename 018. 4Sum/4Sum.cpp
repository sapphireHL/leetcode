class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size() < 4) return  result;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size()-3; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1; j<nums.size()-2; j++){
                if(j>i+1 && nums[j] == nums[j-1]) continue;
                int k = j+1, l = nums.size()-1;
                while(k < l){
                    if(nums[i]+nums[j]+nums[k]+nums[l] < target)
                        k++;
                    else if(nums[i]+nums[j]+nums[k]+nums[l] > target)
                        l--;
                    else{
                        result.push_back({nums[i], nums[j], nums[k], nums[l]});
                        l--;
                         while(nums[l] == nums[l+1])
                             l--;
                    }
                }
            }
        }
        return result;
    }
};
