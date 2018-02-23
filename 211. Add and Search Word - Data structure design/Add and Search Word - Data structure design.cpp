class TrieNode{
public:
    unordered_map<char, TrieNode*> next;
    char ch;
    bool isword;
    TrieNode(char c){
        ch = c;
        isword = false;
    }
};


class WordDictionary {
public:
    
	/** Initialize your data structure here. */
	WordDictionary() {
	    root = new TrieNode(' ');
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
        TrieNode* p = root;
        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            if(p->next.count(ch)){
                p = p->next[ch];
                continue;
            }
            else{
                TrieNode* node = new TrieNode(ch);
                p->next[ch] = node;
                p = node;
            }
        }
        p->isword = true;
	}

	bool dfs(string &word, int current, TrieNode* p){
		if(current == word.size()){
            return p->isword;
        }
        if(word[current] == '.'){
            TrieNode* origin = p;
            for(auto it:p->next){
                p = it.second;
                if(dfs(word, current + 1, p))
                    return true;
                p = origin;
            }
        }
        else{
            if(!p->next.count(word[current])){
                return false;
            }
            p = p->next[word[current]];
            if(dfs(word, current + 1, p))
                return true;
        }
        return false;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
        TrieNode* p = root;
        return dfs(word, 0, p);
	}
private:
	TrieNode* root;
};

/**
* Your WordDictionary object will be instantiated and called as such:
* WordDictionary obj = new WordDictionary();
* obj.addWord(word);
* bool param_2 = obj.search(word);
*/
