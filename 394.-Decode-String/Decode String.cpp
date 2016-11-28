class Solution {
public:
    string decodeString(string s) {
        string res;
        stack<int> count;
        stack<string> str;
        int i=0;
        while(i<s.length()){
            if(s[i]>='0' && s[i]<='9'){
                string num;
                while(s[i]>='0' && s[i]<='9'){
                    num += s[i];
                    i++;
                }
                count.push(atoi(num.c_str()));
            }
            else if(s[i] == ']'){
                string temp;
                string sum;
                while(strcmp(str.top().c_str(), "[")){
                    temp += str.top();
                    str.pop();
                }
                str.pop();
                for(int k=0; k<count.top(); k++){
                    sum += temp;
                }
                count.pop();
                str.push(sum);
                i++;
            }
            else{
                string tt;
                tt += s[i];
                str.push(tt);
                i++;
            }
        }
        while(!str.empty()){
            res+=str.top();
            str.pop();
        }
        for(int i=0; i<res.size()/2; i++){
            char temp = res[i];
            res[i] = res[res.size()-1-i];
            res[res.size()-1-i] = temp;
        }
        return res;
    }
};
