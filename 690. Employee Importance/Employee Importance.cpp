/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, int> imp;
        unordered_map<int, vector<int>> sub;
        for(int i=0; i<employees.size(); i++){
            imp[employees[i]->id] = employees[i]->importance;
            sub[employees[i]->id] = employees[i]->subordinates;
        }
        
        queue<int> q;
        unordered_map<int, int> visit;
        q.push(id);
        int res = 0;
        while(!q.empty()){
            int cur = q.front();
            res += imp[cur];
            visit[cur] = 1;
            q.pop();
            for(int i=0; i<sub[cur].size(); i++){
                if(!visit[sub[cur][i]]){
                    q.push(sub[cur][i]);
                    visit[sub[cur][i]] = 1;
                }
            }
        }
        return res;
    }
};
