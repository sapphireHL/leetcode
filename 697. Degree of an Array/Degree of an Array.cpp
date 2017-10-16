class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_map<int, vector<int>> mp;
        int maxf = 0, res = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(mp.count(nums[i])){
                mp[nums[i]][0]++;
                mp[nums[i]][2] = i;
            }
            else{
                mp[nums[i]].resize(3);
                mp[nums[i]][0]++;
                mp[nums[i]][1] = i;
                mp[nums[i]][2] = i;
            }
            maxf = max(maxf, mp[nums[i]][0]);
        }
        for(auto i=mp.begin(); i!=mp.end(); i++){
            if(i->second[0] == maxf){
                res = min(res, i->second[2] - i->second[1] + 1);
            }
        }
        return res;
    }
};
