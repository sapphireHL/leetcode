class Solution {
public:
    unordered_map<string, vector<int>> mp;

    //dfs + cache
    vector<int> diffWaysToCompute(string input) {
        if(mp.count(input)) return mp[input];
        vector<int> res;
        const int n = input.size();
        for(int i=0; i<n; i++){
            if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
                string sub1 = input.substr(0, i);
                string sub2 = input.substr(i+1);
                vector<int> res1 = diffWaysToCompute(sub1);
                vector<int> res2 = diffWaysToCompute(sub2);
                for(int m:res1){
                    for(int n:res2){
                        if(input[i] == '+')
                            res.push_back(m+n);
                        else if(input[i] == '-')
                            res.push_back(m-n);
                        else if(input[i] == '*')
                            res.push_back(m*n);
                    }
                }
            }
        }
        if(res.empty())
            res.push_back(stoi(input));
        mp[input] = res;
        return res;
    }
};
