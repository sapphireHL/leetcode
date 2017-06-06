class Solution {
public:
    void addNext(string cur, queue<string>& q, unordered_set<string>& m){
        m.erase(cur);
        int len = cur.length();
        for(int i=0; i<len; i++){
            char letter = cur[i];
            for(int j=0; j<26; j++){
                if(j!=letter-'a') cur[i] = 'a'+j;
                if(m.find(cur)!=m.end()){
                    q.push(cur);
                    m.erase(cur);
                }
            }
            cur[i] = letter;
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int res = 0;
        queue<string> q;
        unordered_set<string>m;
        for(auto i:wordList) m.insert(i);
        m.insert(beginWord);
        addNext(beginWord, q, m);
        
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                string tmp = q.front();
                q.pop();
                if(tmp == endWord) return res+2;
                addNext(tmp, q, m);
            }
            res++;
        }
        return 0;
    }
};
