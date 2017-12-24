class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, index = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max1){
                index = i;
                max2 = max1;
                max1 = nums[i];
            }
            else if(nums[i] > max2)
                max2 = nums[i];
        }
        cout<<max1<<' '<<max2<<endl;
        if(max1 >= 2*max2)
            return index;
        else return -1;
    }
};
