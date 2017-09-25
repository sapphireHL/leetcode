class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        int res = 0;
        for(int i=0; i<ops.size(); i++){
            if(ops[i] == "D"){
                if(!s.empty())
                    s.push(s.top()*2);
            }
            else if(ops[i] == "C"){
                if(!s.empty())
                    s.pop();
            }
            else if(ops[i] == "+"){
                if(s.size() >= 2){
                    int a = s.top();
                    s.pop();
                    int b = s.top();
                    s.push(a);
                    s.push(a+b);
                }
            }
            else{
                s.push(stoi(ops[i]));
            }
        }
        while(!s.empty()){
            res += s.top();
            s.pop();
        }
        return res;
    }
};
