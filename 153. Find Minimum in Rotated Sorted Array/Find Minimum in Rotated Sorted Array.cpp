class Solution {
public:
    int findM(vector<int> &nums, int left, int right){
        if(left != right){
            if(nums[left] <= nums[right])
                return findM(nums, left, --right);
            else
                return findM(nums, ++left, right);
        }
        else
            return nums[left];
    }
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1, mid = right/2;
        if(nums[left] <= nums[mid] && nums[mid] <= nums[right]) return nums[left];
        if(nums[left] >= nums[mid] && nums[mid] >= nums[right]) return nums[right];
        int min1 = findM(nums, left, mid), min2 = findM(nums, mid+1, right);
        return min1 < min2?min1:min2;
    }
};
