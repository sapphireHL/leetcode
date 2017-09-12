class MagicDictionary {
public:
    set<string> s;
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto i:dict){
            s.insert(i);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        int len = word.size();
        for(int i=0; i<len; i++){
            char ch = word[i];
            for(int j=0; j<26; j++){
                if(ch == 'a'+j) continue;
                string newword = word;
                newword[i] = 'a'+j;
                if(s.find(newword) != s.end()) return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
