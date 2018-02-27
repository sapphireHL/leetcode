class Solution {
public:
    static bool cmp(const string& a, const string& b){
        string ab = a + b;
        string ba = b + a;
        return ab > ba;
    }
    
    string largestNumber(vector<int>& nums) {
        string res;
        vector<string> snums;
        for(int i:nums) snums.push_back(to_string(i));
        sort(snums.begin(), snums.end(), cmp);
        int i = 0;
        while(i < (int)snums.size() - 1 && snums[i] == "0") i++;
        for(; i < snums.size(); i++)
            res += snums[i];
        return res;
    }
};
