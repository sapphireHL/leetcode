class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0; i<s.size(); i++){
            if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
                if(stk.empty()) return false;
                char tmp = stk.top();
                stk.pop();
                if(s[i] == ')' && tmp == '('){}
                else if(s[i] == ']' && tmp == '['){}
                else if(s[i] == '}' && tmp == '{'){}
                else return false;
            }
            else stk.push(s[i]);
        }
        return stk.empty();
    }
};
