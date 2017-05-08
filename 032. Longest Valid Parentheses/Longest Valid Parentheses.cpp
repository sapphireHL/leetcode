class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0, last = -1;//position of last non-matching ')'
        stack<int> stk;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(') stk.push(i);
            else{
                if(stk.empty()) last = i;//non-matching ')'
                else {
                    stk.pop();
                    if(stk.empty()) result = max(result, i-last);
                    else result = max(result, i-stk.top());
                }
            }
        }
        return result;
    }
};
