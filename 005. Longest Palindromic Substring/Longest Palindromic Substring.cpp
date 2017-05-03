class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        const int n = s.size();
        bool f[n][n]={false};
        fill_n(&f[0][0], n*n, false);
        //vector<vector<bool> > f(n, vector<bool>(n));
        int max = 1, start = 0;
        for(int i=0; i<s.size(); i++){
            f[i][i] = 1;
            for(int j=0; j<i; j++){
                f[j][i] = ((s[j] == s[i]) && (i-j<2 || f[j+1][i-1]));
                if(f[j][i] && i-j+1 > max){
                    max = i-j+1;
                    start = j;
                }
            }
        }
        return s.substr(start, max);
    }
};
