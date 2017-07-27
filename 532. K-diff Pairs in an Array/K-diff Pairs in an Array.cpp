class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k<0) return 0;
        map<int, int> m;
        int res = 0;
        for(int i=0; i<nums.size(); i++) m[nums[i]]++;
        for(auto i = m.begin(); i!=m.end(); i++){
            if(k == 0) res += i->second>=2?1:0;
            else
                if(m.find(i->first+k) != m.end()) res++;
        }
        return res;
    }
};
