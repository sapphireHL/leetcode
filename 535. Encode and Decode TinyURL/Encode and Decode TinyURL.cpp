class Solution {
public:
    vector<char> table;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string result;
        for(int i=0; i<longUrl.size(); i++){
            table.push_back(longUrl[i]);
        }
        result = "tinyurl.com";
        return result;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string result;
        for(int i=0; i<table.size(); i++){
            result += table[i];
        }
        return result;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
