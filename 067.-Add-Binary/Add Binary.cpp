class Solution {
public:
    void commonProcess(int &temp, int &up, string &res){
        if(temp > 1){
            res += temp-2+48;
            up = 1;
        }
        else{
            up = 0;
            res += temp+48;
        }
    }
    string addBinary(string a, string b) {
        string res;
        int counta = a.length()-1;
        int countb = b.length()-1;
        int up = 0;
        while(counta >= 0 && countb >= 0){
            int aa = int(a[counta--]) - 48;
            int bb = int(b[countb--]) - 48;
            int temp = aa+bb+up;
            commonProcess(temp, up, res);
        }
        cout<<res<<endl;
        if(counta >= 0){
            while(counta >= 0){
                int temp = a[counta--] - 48 + up;
                commonProcess(temp, up, res);
            }
        }
        else if(countb >= 0){
            while(countb >= 0){
                int temp = b[countb--] - 48 + up;
                commonProcess(temp, up, res);
            }
        }
        if(up == 1){
            res += '1';
        }
        for(int i=0; i<res.length()/2; i++){
            char temp = res[i];
            res[i] = res[res.length()-i-1];
            res[res.length()-i-1] = temp;
        }
        return res;
    }
};
