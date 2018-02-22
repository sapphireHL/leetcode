class TrieNode{
public:
    unordered_map<char, TrieNode*> next;
    char ch;
    bool isword;
    TrieNode(char c, bool b = false){
        ch = c;
        isword = b;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode(' ');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root;
        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            if(p->next.count(ch)){
                p = p->next.find(ch)->second;
                continue;
            } 
            else{
                TrieNode* node = new TrieNode(ch);
                p->next.insert(pair<char, TrieNode*>(ch, node));
                p = node;
            }
        }
        p->isword = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = findNode(word);
        return node && node->isword;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = findNode(prefix);
        return node != nullptr;
    }
    
    TrieNode* findNode(string s){
        TrieNode* p = root;
        for(int i = 0; i < s.size(); i++){
            if(!p->next.count(s[i]))
                return nullptr;
            TrieNode* nextnode = p->next.find(s[i])->second;
            p = nextnode;
        }
        return p;
    }
    
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
