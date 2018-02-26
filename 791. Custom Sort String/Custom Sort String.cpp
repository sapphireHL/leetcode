class Solution {
public:
    string customSortString(string S, string T) {
        string res;
        unordered_map<char, int> mp;
        for(char i:T){
            mp[i]++;
        }
        for(char i:S){
            if(mp.count(i)){
                for(int j = 0; j < mp[i]; j++)
                    res += i;
                mp.erase(mp.find(i));
            }
        }
        for(auto i:mp){
            for(int j = 0; j < i.second; j++)
                res += i.first;
        }
        return res;
    }
};
