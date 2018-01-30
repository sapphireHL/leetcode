class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        unordered_map<char, int> mp;
        for(char ch:J) mp[ch] = 1;
        for(char ch:S){
            if(mp.count(ch)) res++;
        }
        return res;
    }
};
