class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size(), redindex = 0, blueindex = n-1;
        for(int i=0; i<=blueindex; ){
            if(nums[i] == 0){
                swap(nums[i++], nums[redindex]);
                redindex++;
            }
            else if(nums[i] == 2){
                swap(nums[i], nums[blueindex]);
                blueindex--;
            }
            else i++;
        }
        
    }
};
