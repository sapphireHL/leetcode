class Solution {
public:
    string getHint(string secret, string guess) {
        string res;
        int bulls = 0;
        int cows = 0;
        for(int i=0; i<secret.length(); i++){
            if(secret[i] == guess[i]){
                bulls++;
            }
        }
        vector<int> m1(10, 0);
        vector<int> m2(10, 0);
        for(int i=0; i<secret.length(); i++){
            m1[secret[i]-48]++;
            m2[guess[i]-48]++;
        }
        for(int i=0; i<10; i++){
            cows += m1[i]<m2[i]?m1[i]:m2[i];
        }
        cows -= bulls;
        char temp[10];
        sprintf(temp, "%dA%dB", bulls, cows);
        res = temp;
        return res;
    }
};
