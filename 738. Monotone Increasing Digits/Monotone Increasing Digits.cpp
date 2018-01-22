class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        for(int i = s.size() - 2; i >= 0; i--){
            if(s[i] > s[i+1]){
                s[i] = s[i] - 1;
                for(int j = i+1; j<s.size(); j++)
                    s[j] = '9';
            }
        }
        return stoi(s);
    }
};
