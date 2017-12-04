class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<pair<int, int>> s;
        for(int i=0; i<temperatures.size(); i++){
            if(s.empty() || temperatures[i] <= s.top().first)
                s.push(pair<int, int>(temperatures[i], i));
            else{
                int cur = temperatures[i];
                while(!s.empty() && cur > s.top().first){
                    auto tmp = s.top();
                    s.pop();
                    res[tmp.second] = i - tmp.second;
                }
                s.push(pair<int, int>(cur, i));
            }
        }
        return res;
    }
};
