class Solution {
public:
    int countX(string s){
        int n = s.size();
        if(n == 1) return 1;
        string sub = s.substr(0, n-1);
        if(sub == "+") return 1;
        if(sub == "-") return -1;
        return stoi(sub);
    }
    
    void count(string s, int& x, int& n){
        int start = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '+' || s[i] == '-'){
                if(i == 0) continue;
                string sub = s.substr(start, i-start);
                if(i > 0 && s[i-1] == 'x')
                    x += countX(sub);
                else
                    n += stoi(sub);
                start = i;
            }
        }
        string sub = s.substr(start);
        if(s.back() == 'x')
            x += countX(sub);
        else
            n += stoi(sub);
    }
    
    string solveEquation(string equation) {
        int pos = equation.find('=');
        int lx = 0, rx = 0, ln = 0, rn = 0;
        string s1 = equation.substr(0, pos), s2 = equation.substr(pos+1);
        count(s1, lx, ln);
        count(s2, rx, rn);
        if(lx == rx && ln == rn) return "Infinite solutions";
        if(lx == rx && ln != rn) return "No solution";
        return "x=" + to_string((rn-ln)/(lx-rx));
    }
};
