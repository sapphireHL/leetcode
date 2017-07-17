class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        int res = 0;
        map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        for(auto i=m.begin(); i!=prev(m.end(), 1); i++){
            auto j = prev(i, -1);
            if(abs(i->first-j->first) == 1)
                res = max(res, i->second+j->second);
        }
        return res;
    }
};
