class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //the array can form a linked list with cycle
        //ex:2 3 1 4 2
        //2->1->3->4->2->1_3->4
        if(nums.size() <= 1) return -1;
        int fast = nums[nums[0]], slow = nums[0];
        while(fast != slow){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while(fast != slow){
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
};
