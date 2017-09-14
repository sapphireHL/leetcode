class Solution {
public:
    unordered_map<string, vector<string>> parent;
    vector<vector<string>> res;
    vector<string> path;
    
    void addNext(string s, unordered_set<string>& dict, unordered_set<string>& nextLevel){
        for (int i = 0; i<s.size(); i++){
            string ss = s;
            for (int j = 0; j<26; j++){
                char ch = 'a' + j;
                if (ch == s[i]) continue;
                ss[i] = ch;
                if (dict.count(ss)){
                    nextLevel.insert(ss);
                    parent[ss].push_back(s);
                }
            }
        }
    }

    void dfs(string cur, string start){
        if (cur == start) {
            path.push_back(start);
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
            path.pop_back();
            return;
        }
        for (int i=0; i<parent[cur].size(); i++){
            path.push_back(cur);
            dfs(parent[cur][i], start);
            path.pop_back();
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return res;
        
        unordered_set<string> curLevel, nextLevel;
        curLevel.insert(beginWord);
        
        while(1){
            //在dict中删除当前层的元素，避免重复
            for(auto i = curLevel.begin(); i != curLevel.end(); i++)
                dict.erase(*i);
            //计算下一层的元素
            for(auto i = curLevel.begin(); i != curLevel.end(); i++)
                addNext(*i, dict, nextLevel);
            //若下一层为空，说明当前节点无法扩展
            if(nextLevel.empty())
                return res;
            //若下一层包含目标
            if(nextLevel.count(endWord)){
                dfs(endWord, beginWord);
                return res;
            }
            curLevel = nextLevel;
            nextLevel.clear();
        }
        
        return res;
    }
};
