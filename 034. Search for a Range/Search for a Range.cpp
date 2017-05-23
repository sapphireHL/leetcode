class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size(),left=0, right=nums.size()-1, start=-1, end=-1;
        vector<int> res;
        while(left <= right){
            int mid = left+(right-left)/2;
            if(nums[mid] == target){
                int l=mid, r=mid;
                for(;l>=0&&nums[l]==target; l--){start=l;}
                for(;r<n&&nums[r]==target; r++){end=r;}
                break;
            }
            else if(nums[mid] > target){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        res.push_back(start);
        res.push_back(end);
        return res;
    }
};
