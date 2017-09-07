class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> zig(numRows);
        int count = 0;
        while(count < s.size()){
            for(int i=0; i<numRows && count<s.size(); i++)
                zig[i].push_back(s[count++]);
            for(int i=numRows-2; i>0 && count<s.size(); i--)
                zig[i].push_back(s[count++]);
        }
        string res;
        for(int i=0; i<numRows; i++){
            for(int j=0; j<zig[i].size(); j++)
                res += zig[i][j];
        }
        return res;
    }
};
