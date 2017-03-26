class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int result = 0, pre = 0, conse = 1;
        map<int, int> m;
        for(int i=0; i<nums.size(); i++)
            m[nums[i]] = 1;
        map<int, int>::iterator it = m.begin();
        pre = it->first;
        it++;
        while(it != m.end()){
            if(it->first - pre == 1)
                conse++;
            else{
                if (conse > result)
                    result = conse;
                conse = 1;
            }
            pre = it->first;
            it++;
        }
        if (conse > result)
            result = conse;
        return result;
    }
};
