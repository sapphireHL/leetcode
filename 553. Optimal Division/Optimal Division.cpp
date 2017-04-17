class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string result;
        for(int i=0; i<nums.size(); i++){
            if(nums.size() > 2 && i == 1)
                result += '(';
            result += to_string(nums[i]);
            if(nums.size() > 1 && i < nums.size()-1)
                result += '/';
            else if(nums.size() > 2 && i == nums.size()-1)
                result += ')';
        }
        return result;
    }
};
