class Solution {
public:
    int calc(int a, int b, string ch){
        if(ch == "+") return a+b;
        if(ch == "-") return a-b;
        if(ch == "*") return a*b;
        if(ch == "/") return a/b;
    }
    
     int priority(char ch){
         if(ch == '+' || ch == '-') return 1;
         if(ch == '*' || ch == '/') return 2;
         if(ch == '(') return 0;
     }
    
    string inToPost(string exp) {
        string res;
        stack<char> sign;
        int start = 0, i = 0;
        for (; i<exp.size(); i++) {
            if (exp[i] == ')') {
                res += " ";
                while (!sign.empty() && sign.top() != '(') {
                    char opt = sign.top();
                    sign.pop();
                    res += opt;
                    res += " ";
                }
                sign.pop();
            }
            else if(exp[i] == '('){
                sign.push(exp[i]);
            }
            else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
                res += " ";
                while(!sign.empty() && priority(sign.top()) >= priority(exp[i])){
                    res += sign.top();
                    res += " ";
                    sign.pop();
                }
                sign.push(exp[i]);
            }
            else 
                res += exp[i];
        }
        while (!sign.empty()) {
            res += " ";
            res += sign.top();
            sign.pop();
        }
        return res;
    }
    
    int calcPost(string s){
        stack<int> sk;
        string tmp;
        stringstream ss(s);
        while(getline(ss, tmp, ' ')){
            if(tmp != ""){
                if(tmp == "+" || tmp == "-" || tmp == "*" || tmp == "/"){
                    int num2 = sk.top();
                    sk.pop();
                    int num1 = sk.top();
                    sk.pop();
                    sk.push(calc(num1, num2, tmp));
                }
                else{
                    sk.push(stoi(tmp));
                }
            }
        }
        return sk.top();
    }
    
    int calculate(string s) {
        string exp;
        for(int i=0; i<s.size(); i++){
            if(s[i] != ' ') exp += s[i];
        }
        string post = inToPost(exp);
        cout<<post<<endl;
        return calcPost(post);
    }
};
