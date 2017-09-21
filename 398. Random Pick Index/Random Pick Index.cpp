class Solution {
public:
    vector<int> arr;
    
    Solution(vector<int> nums) {
        arr = nums;
    }
    //蓄水池抽样
    int pick(int target) {
        int count = 1, res = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] == target){
                if(rand() % count == 0)
                    res = i;
                count++;
            }
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
