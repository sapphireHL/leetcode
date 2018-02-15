class Solution {
public:
    int numRabbits(vector<int>& answers) {
        //最多n+1个n可以组成一组，例如1，1最少有2只兔子；2，2，2最少有3只兔子
        if(answers.empty())
            return 0;
        if(answers.size() == 1)
            return answers[0] + 1;
        int res = 0;
        unordered_map<int, int> mp;
        for(int i:answers)
            mp[i]++;
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->first == 0) res += it->second;
            else res += (it->first + 1) * ((it->second - 1) / (it->first + 1) + 1);
        }
        return res;
    }
};
