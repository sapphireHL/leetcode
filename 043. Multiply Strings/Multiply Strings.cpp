class Solution {
public:
    string multiply(string num1, string num2) {
        const int m = num1.size(), n = num2.size();
        string res(m + n, '0');
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                int mul = (num1[i]-'0') * (num2[j]-'0');
                int pos1 = i+j, pos2 = i+j+1;
                int sum = mul + res[pos2]-'0';
                res[pos2] = (sum % 10) + '0';
                res[pos1] += (sum / 10);
            }
        }
        int i = 0;
        while(res[i] == '0') i++;
        if(i == res.size()) return "0";
        return res.substr(i);
    }
};
