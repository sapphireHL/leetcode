class Solution {
public:
    string convertToBase7(int num) {
        if(!num){
            return "0";
        }
        string result;
        string s;
        if(num < 0){
            result += '-';
            num *= -1;
        }
        while(num != 0){
            stringstream ss;
            ss << num % 7;
            ss >> s;
            result += s;
            num /= 7;
        }
        int start = 0;
        if(result[0] == '-'){
            start = 1;
        }
        for(int i=start; i<(result.length())/2+start; i++){
            char temp = result[i];
            result[i] = result[result.length()-i-1+start];
            result[result.length()-i-1+start] = temp;
        }
        return result;
    }
};
