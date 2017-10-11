class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.empty()) return res;
        if(nums.size() == 1) return vector<string>{to_string(nums[0])};
        int start = nums[0], end = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i]-nums[i-1] != 1){
                if(start != end) res.push_back(to_string(start)+"->"+to_string(end));
                else res.push_back(to_string(start));
                start = end = nums[i];
            }
            else{
                end++;
            }
        }
        if(start != end) res.push_back(to_string(start)+"->"+to_string(end));
        else res.push_back(to_string(start));
        return res;
    }
};
