class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        const int n = a.size()>b.size()?a.size():b.size();
        int carry = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for(int i=0; i<n; i++){
            const int ai = i<a.size()?a[i]-'0':0;
            const int bi = i<b.size()?b[i]-'0':0;
            int val = (ai+bi+carry) % 2;
            carry = (ai+bi+carry) / 2;
            res+=val+'0';
        }
        if(carry == 1) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};
