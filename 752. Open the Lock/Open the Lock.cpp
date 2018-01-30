class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead{deadends.begin(), deadends.end()};
        if(dead.count("0000")) return -1;
        unordered_set<string> visit;
        queue<string> q;
        q.push("0000");
        int step = 0;
        
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                string cur = q.front();
                q.pop();
                if(cur == target) return step;
                visit.insert(cur);
                
                for(int i = 0; i < 4; i++){
                    string plus = cur, minus = cur;
                    if(plus[i] == '9') plus[i] = '0';
                    else plus[i] = plus[i] + 1;
                    if(!visit.count(plus) && !dead.count(plus)){
                        q.push(plus);
                        visit.insert(plus);
                    }
                    if(minus[i] == '0') minus[i] = '9';
                    else minus[i] = minus[i] - 1;
                    if(!visit.count(minus) && !dead.count(minus)){
                        q.push(minus);
                        visit.insert(minus);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
